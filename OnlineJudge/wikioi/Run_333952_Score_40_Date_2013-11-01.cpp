#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int a[300000], b[300000], s = 1, ans = 0;
void time(int n)
{
    int p, i, j, l, t, k, c;
    for(p = 2; p <= n; p++)
    {
        memcpy(b, a, sizeof(a));
        memset(a, 0, sizeof(a));
        t = p; j = 0;
        while(t)
        {
            k = t%10;
        	for(i = 1; i <= s; i++)
                a[i+j] += b[i]*k;
            t/=10;
            j++;
        }
        i = 1, c = 0;
        while(i<=s || a[i])
        {
            c++;
            l = a[i]/10;
            a[i+1] += l;
            a[i++] %= 10;
        }
        s = c;
    }
}
int main()
{
    a[1] = 1;
    int n;
    cin >> n;
    time(n);
    for(int i = s; i > 0; i--) ans += a[i];
    cout << ans;
    int ok = 1;
    for(int i = 2; i <= sqrt(ans)+1; i++)
        if(ans % i == 0){ok = 0; break;}
    cout << (ok?'T':'F');
    return 0;
}