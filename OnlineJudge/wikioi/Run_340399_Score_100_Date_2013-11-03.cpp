#include <iostream>
#include <iomanip>
using namespace std;
double mark = 0, b = 0, c, m;
int main()
{
    cin >> m;
    while(cin >> c >> m)
        mark += c*m, b += c;
    cout << setiosflags(ios::fixed) << setprecision(2) << mark/b;
	return 0;
}