#include <iostream>
#include <cmath>
using namespace std;void h(int a,char q,char z,char m){if(a!=1)h(a-1,q,m,z);cout<<a<<" from "<<q<<" to "<<m<<endl;if(a!=1)h(a-1,z,q,m);}int main(){int n;cin>>n;cout<<int(pow(2.0,n)-1)<<endl;h(n,'A','B','C');return 0;}