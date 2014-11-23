#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double s, p, c, t, u;
    cin >> s >> p >> c;
    t = s/(p+c+(c-p)/(c+p)*p);
    u = (c*t-p*t)/(c+p);
    cout << setiosflags(ios::fixed) << setprecision(2) << 2*t+u;
    return 0;
}