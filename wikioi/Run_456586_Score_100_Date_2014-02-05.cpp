#include <cstdio>
using namespace std;
int n, a[100005];
int main() {
	scanf("%d", &n);
	int ans=-1,st = 0;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1] && st!=1){ans++;st=1;}
        else if(a[i]<a[i-1] && st!=-1){ans++;st=-1;}
	} 
    printf("%d",ans+2);
	return 0;
}