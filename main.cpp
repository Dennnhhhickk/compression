#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <map>
#include <string>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

ll n, len;
map<pair<ll, vector<ll>>, ll> mn;
vector<ll> cur;
vector<pair<ll, vector<ll>>> ANS;

bool F(ll a)
{
    return cur[a];
}

bool check(ll i)
{
    return pow(2, i) < n;
}

ll sum(ll a)
{
    ll anst = 0;
    while (a)
    {
        anst += a % 2;
        a /= 2;
    }
    return anst;
}

vector<ll> decomposition(ll a)
{
    vector<ll> ans;
    ans.clear();
    while (a)
    {
        ans.pb(a % 2);
        a /= 2;
    }
    while (ans.size() < len) 
        ans.pb(0);
    reverse(all(ans));
    return ans;
}

bool fnd(pair<ll, vector<ll>> a)
{
    return mn[a] == 1;
}

void view(vector<ll> a)
{
    for (auto i : a)
        cout << i;
    cout << endl;
}

ll cnt(ll a)
{
    vector<ll> f = decomposition(a);
    for (int i = 0; i < f.size(); i++)
        if (f[i] == 1)
            return i;
}

int main()
{

    vector<ll> em;
    em.clear();

    cin >> n >> len;

    len = pow(2, len);

    cur = decomposition(n);

    reverse(all(cur));

    for (int i = 0; i < cur.size(); i++)
        if (!F(i))
        {
            vector<ll> dec = decomposition(i);
            vector<ll> tmp;
            ll lst = cur.size();
            for (int j = 0; j < lst; j++)
            {
                tmp.clear();
                vector<ll> tmp1 = decomposition(j);
                for (int z = 0; z < tmp1.size(); z++)
                    if (tmp1[z])
                        tmp.pb(dec[z]);
                mn[mp(j, tmp)] = -1;
            }
        }

    for (int i = 0; i < cur.size(); i++)
        if (F(i))
        {
            vector<ll> dec = decomposition(i);

            bool bol = 0;

            vector<ll> tmp;
            ll lst = cur.size();
            ll ans = -1, ans1 = 120, ans3 = -1;
            vector<ll> ans2;

            for (int j = 0; j < lst; j++)
            {
                tmp.clear();
                vector<ll> tmp1 = decomposition(j);
                for (int z = 0; z < tmp1.size(); z++)
                    if (tmp1[z])
                        tmp.pb(dec[z]);
                if (mn[mp(j, tmp)] != -1)
                {
                    bol = bol || fnd(mp(j, tmp));
                    if (sum(j) < ans1 || (sum(j) == ans1 && cnt(j) > ans3))
                    {
                        ans1 = sum(j);
                        ans = j;
                        ans3 = cnt(j);
                        ans2 = tmp;
                    }
                }
            }

            if (ans == -1)
                return 228;

            if (bol)
            {            
                ANS.pb(mp(-1, em));
                continue;
            }

            ANS.pb(mp(ans, ans2)); 
            mn[mp(ans, ans2)] = 1;  
        }
        else
            ANS.pb(mp(-1, em));

    /*string answer = "";

    for (int i = 0; i < ANS.size(); i++)
        if (ANS[i].x != -1)
        {
            vector<ll> dec = decomposition(i);
            vector<ll> d = decomposition(ANS[i].x);
            for (int j = 0; j < d.size(); j++)
                if (d[j])
                {
                    if (dec[j] == 0)
                        answer.pb('!');
                    answer.pb(char(j + 'A'));
                }
            answer += " or ";
        }

    cout << answer.substr(0, answer.size() - 4) << endl;*/

    freopen("p.html", "w", stdout);

    cout << "<!DOCTYPE html> \n <html> \n<head>\n<meta charset=\"UTF-8\">\n<title>\nTest\n</title>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"main.css\">\n</head>\n";

    cout << "<body>";

    cout << "Answer :";

    string answer = "";

    for (int i = 0; i < cur.size(); i++)
        if (ANS[i].x != -1)
        {
            vector<ll> dec = decomposition(i);
            vector<ll> d = decomposition(ANS[i].x);
            for (int j = 0; j < d.size(); j++)
                if (d[j])
                {
                    if (dec[j] == 0)
                        answer.pb('!');
                    answer.pb(char(d.size() - 1 - j + 'A'));
                }
            answer += " or ";
        }

    cout << answer.substr(0, answer.size() - 4) << endl;

    cout << "\n<table border=\"3\">";

    vector<ll> tmp;
    ll lst = cur.size();
    cout << "\n<tr>";
    for (int j = 1; j < lst; j++)
        {
            cout << "<td>";
            tmp.clear();
            vector<ll> tmp1 = decomposition(j);
            for (int z = 0; z < tmp1.size(); z++)
                if (tmp1[z])
                    cout << char(tmp1.size() - 1 - z + 'A');
            cout <<"</td>";
        }
    cout <<"</tr>";

    for (int i = 0; i < cur.size(); i++)
    {
        vector<ll> tmp;
        ll lst = cur.size();
        cout << "\n<tr>";
        vector<ll> dec = decomposition(i);
        for (int j = 1; j < lst; j++)
            {
                tmp.clear();
                vector<ll> tmp1 = decomposition(j);
                for (int z = 0; z < tmp1.size(); z++)
                    if (tmp1[z])
                        tmp.pb(dec[z]);
                cout << "<td" << (mn[mp(j, tmp)] == -1? " id = \"jjjj\"" : (mn[mp(j, tmp)] == 1 ? " id = \"iiii\"" : "")) << ">";
                for (auto i : tmp)
                    cout << i;
                cout <<"</td>";
            }
        cout <<"\n</tr>";
    }

    cout << "</table>\n</body>";

    cout << "\n</html>";

    return 0;
}