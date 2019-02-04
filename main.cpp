#include <bits/stdc++.h>

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
        anst += (a % 2);
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
    for (auto i : ANS)
        if (i.x == a.x && i.y == a.y)
            return true;
    return false;
}

void view(vector<ll> a)
{
    for (auto i : a)
        cout << i;
    cout << endl;
}

int main()
{

    vector<ll> em;
    em.clear();

    cin >> n >> len;

    cur = decomposition(n);

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
            ll ans = -1, ans1 = 120;
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
                    if (sum(j) < ans1)
                    {
                        ans1 = sum(j);
                        ans = j;
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
        }
        else
            ANS.pb(mp(-1, em));

    string answer = "";

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

    cout << answer.substr(0, answer.size() - 4) << endl;
    return 0;
}