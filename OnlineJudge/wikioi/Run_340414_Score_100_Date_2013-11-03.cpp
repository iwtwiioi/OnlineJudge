#include <cstdio>
using namespace std;
int c[11];
int main()
{
    int n, i, a;
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d",&a);
        c[a]++;
    }
    for(i = 1; i <= 10; i++)
        while(c[i]--)
        	printf("%d\n", i);
	return 0;
}