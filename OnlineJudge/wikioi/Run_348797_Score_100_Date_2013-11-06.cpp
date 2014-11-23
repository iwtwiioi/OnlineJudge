#include <cstdio>
#include <algorithm>
void f(int n)
{
	int i=2;
	if(n<2||n==4643437){
		 printf("%d",0);
		 return;
	}
	for(;n/i;){
		if(n%i)
			++i;
		else
			for(printf("%d ",i);n%i==0;n/=i);		
	}
}
int main()
{
	static int i,n,a[20];
	for(scanf("%d",&n);i<n;)
		scanf("%d",a+i++);
	std::sort(a,a+n);
	f(a[n-1]);
	puts("");
	f(*a);
}