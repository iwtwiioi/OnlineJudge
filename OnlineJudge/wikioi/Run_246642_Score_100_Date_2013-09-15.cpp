#include <iostream>
#include <string>
using namespace std;
int i, j, u=0, d;
string c1, c2, a, b;
int ans[1000];
int main()
{
	cin >> a >> b;
	c1.assign(a.rbegin(), a.rend());
	c2.assign(b.rbegin(), b.rend());
	for(i = 0; i < c1.size(); i++)
		for(j = 0; j < c2.size(); j++)
			ans[i+j] += (c1[i]-'0') * (c2[j] - '0');
	for(i = 0; i<c1.size()+c2.size(); i++)
	{
		u = ans[i]/10;
		ans[i+1]+=u;
		ans[i]%=10;
		if(ans[i+1]!=0) d=i+1;
	}
	for(i = d; i >= 0;i--)
		cout << ans[i];
	return 0;
}
