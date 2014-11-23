#include <iostream>
using namespace std;
unsigned long long a, q, r, t;
int main()
{
    cin >> a >> q;
    r = 1; t = 2;
    while(a)
    {
        if(!r) break;
        if(a & 1)
            r = (r * t) % q;
        t = (t * t) % q;
        a >>= 1;
    }
    cout << r;
    return 0;
}