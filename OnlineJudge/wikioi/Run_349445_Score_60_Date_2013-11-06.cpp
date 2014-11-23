#include <iostream>
#include <algorithm>
using namespace std;
#define uint unsigned int
const int MAXN = 3005;
uint f[MAXN], a[MAXN], b[MAXN];
int n;
int main()
{
	cin >> n;
	int i, j, k;
	for(i = 1; i <= n; i++) cin >> a[i];
	for(i = 1; i <= n; i++) cin >> b[i];
    uint ans = 0, maxi = 0;;
	for(i = 1; i <= n; i++)
    {
        maxi = 0;
		for(j = 1; j <= n; j++)
        {
            if(a[i] > b[j] && maxi < f[j]) maxi = f[j];
            if(a[i] == b[j]) f[j] = maxi+1, ans = max(ans, f[j]);
        }
    }
	cout << ans;	
	return 0;
}