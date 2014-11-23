#include <iostream>
using namespace std;
int main(){int a,n[3]={1,1,2};cin>>a;for(int i=0;i<a-3;i++) n[i%3]=n[(i+1)%3]+n[(i+2)%3];cout<<n[(a-1)%3]<<endl;return 0;}