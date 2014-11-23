#include <iostream>
using namespace std;
unsigned long long b, c, p, k, r, t;
int main()
{
    cin >> b >> p >> k;
    c = p;
    r = 1; t = b;
    while(c)
    {
        if(!r) break;
        if(c & 1)
            r = (r * t) % k;
        t = (t*t) % k;
        c >>= 1;
    }
    cout << b <<'^' << p << " mod " << k << '=' << r;;
    return 0;
}