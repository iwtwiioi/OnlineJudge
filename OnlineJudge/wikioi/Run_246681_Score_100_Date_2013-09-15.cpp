#include <iostream>
#include <algorithm>
using namespace std;
int a[110][110]={{0,0}},n,i,j;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)for(j=1;j<=i;j++)cin>>a[i][j];
	for(i=n-1;i>=1;i--)for(j=1;j<=i;j++)a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
	cout<<a[1][1];
	return 0;
}

