#include <iostream>
using namespace std;
int main()
{
    int l, r, ans = 0, t;
    cin >> l >> r;
    int i;
    for(i = l; i <= r; i++)
    {
        t = i;
        while(t)
        {
            if((t+8)%10 == 0) ans++;
            t/=10;
        }
    }
    cout << ans;
    return 0;
}