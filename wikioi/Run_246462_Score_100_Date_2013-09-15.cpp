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
	int size = (Max.size() < Min.size()) ? Max.size() : Min.size();
	int e = 0;
	for(i = 0; i < size; i++)
	{
		if(e){Max[i]++;e=0;}
		if(Max[i]-'0'+(Min[i]-'0') > 9){e=1;ans+=char(Max[i]-'0'+(Min[i]-'0')-10+'0');}
		else ans+=char(Max[i]-'0'+(Min[i]-'0')+'0');
	}
	bool y=(Max.size() < Min.size()) ? 1:0;
	for(i = (y?Max.size():Min.size()); i < (y?Min.size():Max.size()) || e; i++)
	{
		if(e){(y?Min[i]++:Max[i]++);e=0;}
		if((y?Min[i]:Max[i]) > '9'){e=1;ans+=(y?Min[i]:Max[i])-10;}
		else ans+=(y?Min[i]:Max[i]);
	}
	copy(ans.rbegin(), ans.rend(), iter);
	return 0;
}

