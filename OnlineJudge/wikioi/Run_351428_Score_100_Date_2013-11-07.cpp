#include <iostream>
using namespace std;
int a[5010],b[5010];
int main()
{
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++){cin>>a[i];b[i]=1;}
    for(i=1;i<n;i++)
        for(j=i-1;j>=0;j--)
        	if(a[j]<a[i]&&b[j]+1>b[i])
            	b[i]=b[j]+1;
    cout<<b[n-1]<<endl;
    return 0;
}
