#include <iostream>
using namespace std;
int main(){int a,n,b=0;cin>>a;for(;a>0;a--){cin>>n;b=0;while(n!=1){(n%2==0)?(n/=2):(n=3*n+1);b++;}cout<<b<<endl;}return 0;}