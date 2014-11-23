#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2 && y1 == y2){cout << "nonono~\n"; return 0;}
	double k = (y1-y2)/(x1-x2);
    double b = y1-k*x1;
	cout << setiosflags(ios::fixed) << setprecision(2) << k << ' ' << b;
	return 0;
}