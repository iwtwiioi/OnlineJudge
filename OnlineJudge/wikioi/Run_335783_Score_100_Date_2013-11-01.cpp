#include <iostream>
using namespace std;
int hash[5000010], a[200005], ans=0;
int main()
{
    int n, c;
    cin >> n >> c;
    int i, j;
    for(i = 0; i < n; i++) {cin >> a[i]; hash[a[i]]++; }
    for(i = 0; i < n; i++)
        if(a[i]-c >= 0)
        	ans+=hash[a[i]-c];
    cout << ans;
    return 0;
}