#include <iostream>
#include <algorithm>
using namespace std;
int hash[5000010], a[200005], ans=0;
int main()
{
    int n, c, t, n1;
    cin >> n >> c; n1 = 0;
    int i, j;
    for(i = 0; i < n; i++) {cin >> t; if(!hash[t]) a[n1++]=t; hash[t]++; }
  //  for(i = 0; i < n1; i++) cout << a[i] << " ";
    cout << endl;
    for(i = 0; i < n1; i++)
        if(c == 0 && hash[a[i]-c]>1)
        	ans+=hash[a[i]-c];
        else if(hash[a[i]-c] && c != 0)
        	ans+=hash[a[i]-c];
    cout << ans;
    return 0;
}