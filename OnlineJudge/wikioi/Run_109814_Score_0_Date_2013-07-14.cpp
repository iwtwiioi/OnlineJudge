#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	int k,s;
	double count = 0,alpha = 0;
	char al;
	string a,l,r;
	cin>>a;
	for(int i = 0; i < a.size(); i++) if(a[i] >= 'a' && a[i] <= 'z'){al = a[i]; break;}
	char temp[100] = "",temp1[100] = "";
	a.copy(temp,a.find('='),0); l = temp;
	a.copy(temp1,a.size()-a.find('=')-1,a.find('=')+1); r = temp1;
	l.push_back('＋');
	r.push_back('＋');
	int i;
	for(i = 0, k = 0,s = 1; i < l.size(); i++)
	{
		if(l[i] >= '0' && l[i] <= '9'){k = k * 10 + int(l[i] - '0');}
		else if(l[i] == '－'){count += k*s;k=0;s=-1;}
		else if(l[i] == '＋'){count += k*s;k=0;s=1;}
		else if(l[i] == al){alpha += k*s;k=0;s=1;}
	}
	for(i = 0, k = 0, s = -1; i < r.size() ; i++)
	{
		if(r[i] >= '0' && r[i] <= '9'){k = k * 10 + int(r[i] - '0');}
		else if(r[i] == '－'){count += k*s;k=0;s=1;}
		else if(r[i] == '＋'){count += k*s;k=0;s=-1;}
		else if(r[i] == al){alpha += k*s;k=0;s=-1;}
	}
	cout<<al<<"="<<setiosflags(ios::fixed)<<setprecision(3)<<double(-count/alpha)<<endl;
	return 0;
}