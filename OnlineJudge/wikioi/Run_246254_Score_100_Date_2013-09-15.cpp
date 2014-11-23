#include <iostream>
#include <iterator>
#include <string>
using namespace std;
bool sign1, sign2, signa, signt=0;
string a, b, Max, Min, temp, ans="";
ostream_iterator<char> iter(cout);
int i;
int main()
{
	cin>>a>>b;
	if(a[0]=='-') {Max.assign(a.rbegin(), a.rend() - 1); sign1 = 1;}
	else {Max.assign(a.rbegin(), a.rend()); sign1 = 0;}
	if(b[0]=='-') {Min.assign(b.rbegin(), b.rend() - 1); sign2 = 1;}
	else {Min.assign(b.rbegin(), b.rend()); sign2 = 0;}
	if(Max.size() < Min.size()) signt=1;
	else if(Max.size() == Min.size())
		for(i = Max.size(); i >=0; i--) if(Max[i] < Min[i]){signt=1;cout<<"Yes 2\n";temp=Max;Max=Min;Min=temp;signa=sign1;sign1=sign2;sign2=signa;break;}
	if(Max.size() < Min.size()){temp=Max;Max=Min;Min=temp;signa=sign1;sign1=sign2;sign2=signa;}

	int e = 0;
	for(i = 0; i < Min.size(); i++)
	{
		if(e && Max[i] != '0') {Max[i]--;e=0;}
		else if(e) Max[i]=Max[i]+9;
		if(Max[i]-Min[i] < 0){e=1;Max[i]+=10;}
		ans+=char(Max[i]-Min[i]+'0');
	}
	for(i = Min.size(); i < Max.size(); i++)
	{
		if(e && Max[i] != '0') {Max[i]--;e=0;}
		else if(e) Max[i]=Max[i]+9;
		if(Max[i] < '0'){e=1;Max[i]+=10;}
		ans+=Max[i];
	}
	i = ans.size();
	while(ans[--i] == '0');
	if(i != ans.size()-1) ans.erase(ans.begin()+i+1, ans.end());
	if(i==-1) ans+='0';
	if(signt) cout<<'-';
	copy(ans.rbegin(), ans.rend(), iter);
	return 0;
}

