#include <iostream>
#include <string>
using namespace std;
int k[101]={0}, i;
string key;
char a;
int main()
{
	cin>>key;
	for(i = 0; i < key.size(); i++)
		k[i] = (key[i] - (key[i]>='A'&&key[i]<='Z'?'A':'a'));
	i=0;
    while(cin>>a)
        cout<<(char)(((((a>='A'&&a<='Z')?(a-'A'):(a-'a'))<k[i%key.size()])?(char)(a+26):a) -(k[i++%key.size()]));
	return 0;
}