#include <iostream>
#include <iterator>
#include <string>
using namespace std;
string a, b, Max, Min, temp, ans="";
ostream_iterator<char> iter(cout);
int i;
int main()
{
	cin>>a>>b;
	Max.assign(a.rbegin(), a.rend());
	Min.assign(b.rbegin(), b.rend());
	if(Max.size() < Min.size()){temp=Max;Max=Min;Min=temp;}
	int e = 0;
	for(i = 0; i < Min.size(); i++)
	{
		if(e){Max[i]++;e=0;}
		if(Max[i]-'0'+(Min[i]-'0') > 9){e=1;ans+=char(Max[i]-'0'+(Min[i]-'0')-10+'0');}
		else ans+=char(Max[i]-'0'+(Min[i]-'0')+'0');
	}
	for(i = Min.size(); i < Max.size()||e; i++)
	{
		if(e){(Max[i]++);e=0;}
		if(Max[i] > '9'){e=1;ans+=Max[i]-10;}
		else ans+=Max[i];
	}
	copy(ans.rbegin(), ans.rend(), iter);
	return 0;
}

