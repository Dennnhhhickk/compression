#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	freopen("p.html", "w", stdout);

	cout << "<!DOCTYPE html> \n <html> \n<head>\n<meta charset=\"UTF-8\">\n<title>\nTest\n</title>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"main.css\">\n</head>\n";

	cout << "<body>\n<table>";



	cout << "</table>\n</body>";

	cout << "\n</html>";

	fclose(stdout);

	return 0;
}