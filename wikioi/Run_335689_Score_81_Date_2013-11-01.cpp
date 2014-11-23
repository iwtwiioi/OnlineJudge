#include <iostream>
#include <algorithm>
using namespace std;
int a[200005], ans = 0;
int main()
{
    int n, c;
    cin >> n >> c;
    int i, j;
    for(i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    i = 0; j = 1;
    while(i < n)
    {
        j = i+1;
        while(a[j] <= a[i]+c)
        {
            if(a[i] == a[j]-c)
                if(c == 0) ans+=2;
            	else ans++;
            j++;
        }
        i++;
    }
    cout << ans;
    return 0;
}