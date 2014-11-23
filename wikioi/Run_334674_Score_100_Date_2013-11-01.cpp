#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double m, n, r;
    cin >> m >> n >> r;
    double ans;
    if(n >= m) ans = r;
    else ans = (double)(sqrt(pow(m-n, 2)+pow(r, 2)));
    cout << setiosflags(ios::fixed) << setprecision(3) << ans;
	return 0;
}