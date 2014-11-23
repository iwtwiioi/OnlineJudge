#include <iostream>
using namespace std;
#define ll long long
const int MAXN = 3005;
int max(const int& a, const int& b){return a>b?a:b;}
ll f[MAXN], a[MAXN], b[MAXN];
int n;
int main()
{
    cin >> n;
    int i, j, k;
    for(i = 1; i <= n; i++) cin >> a[i];
    for(i = 1; i <= n; i++) cin >> b[i];
    ll ans = 0, maxi = 0;;
    for(i = 1; i <= n; i++)
    {
        maxi = 0;
        for(j = 1; j <= n; j++)
            if(a[i] > b[j]) maxi = f[j];
            else if(a[i] == b[j]) f[j] = maxi+1, ans = max(ans, f[j]); //我们在这里直接维护ans就ok
    }
    cout << ans;  
    return 0;
}