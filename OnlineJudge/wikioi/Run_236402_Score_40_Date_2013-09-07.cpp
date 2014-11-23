#include <iostream>
using namespace std;
int day[1000001],n,m,i,j,ans=0,ok=1;
struct cost
{
	int f,l,r;
}pay[1000001];
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>day[i];
	for(i=1;i<=m;i++) cin>>pay[i].r>>pay[i].f>>pay[i].l;
	for(i=1;i<=n&&ok;i++)
		for(j=1;j<=m;j++)
		{
        	if(pay[j].f<=i&&pay[j].l>=i) day[i]-=pay[j].r;
        	if(day[i]<0&&j!=m){ ans=j; ok=0; break;}
		}
	if(!ans) cout<<0<<endl;
	else cout<<-1<<endl<<ans<<endl;
	return 0;
}