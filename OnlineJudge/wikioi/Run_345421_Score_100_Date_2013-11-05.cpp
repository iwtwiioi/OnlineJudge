#include <cstdio>
using namespace std;
int ans = -1001;
inline int mmax(const int& a, const int& b){return a<b?b:a;}
int main()
{
	int n, j, t = 0, i;
	scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&j);
        t = mmax(t+j, j);
        ans = mmax(ans, t);
    }
	printf("%d", ans);
	return 0;
}