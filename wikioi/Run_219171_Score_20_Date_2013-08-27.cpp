#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
string a,b;
int main()
{
	getline(cin,a);getline(cin,b);
	transform(a.begin(),a.end(),a.begin(),(int (*)(int))toupper);
	transform(b.begin(),b.end(),b.begin(),(int (*)(int))toupper);
	int c=b.find(a),o=1;
	if(c==string::npos||c>0&&b[c-1]!=' '||c+a.size()<a.size()&&b[c+a.size()]!=' ') o=0;
	cout<<(o?c:-1);
	return 0;
}