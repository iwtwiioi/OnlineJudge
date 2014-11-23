#include <iostream>
#include <string>
using namespace std;int k[101],i;string u;char a;int main(){cin>>u;for(i=0;i<u.size();i++)k[i]=u[i]-(u[i]>='a'?'a':'A');i=0;while(cin>>a)cout<<char((((a>='a'?(a-'a'):(a-'A'))<k[i%u.size()])?char(a+26):a)-(k[i++%u.size()]));return 0;}