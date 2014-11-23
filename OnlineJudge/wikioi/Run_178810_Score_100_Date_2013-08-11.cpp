#include <iostream>
using namespace std;
int n,a[100],i=0,b=0,s=0;
int main()
{
    cin>>n;
    while(i<n){cin>>a[i];s+=a[i++];}
    for(i=0,s/=n;i<n-1;i++)
        if(a[i]!=s){a[i+1]+=(a[i]-s);b++;}
    cout<<b;
    return 0;
}