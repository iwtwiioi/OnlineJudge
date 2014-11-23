#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 205;
int cap[maxn][maxn], vis[maxn], inf = 1993101215;
int n, m, ans, flow;
int min(const int& a, const int& b) { return a < b ? a : b; }

//int sap(int u, int f) {
//	if(u == n) return f;
//	if(vis[u]) return 0;
//	int _f, i;
//	for(i = 1; i <= n; ++i) if((cap[u][i] > 0) && (!vis[i])) {
//		vis[i] = 1;
//		_f = sap(i, min(f, cap[u][i]));
//		if(_f > 0) {
//			cap[u][i] -= _f;
//			cap[i][u] += _f;
//			return _f;
//		}
//	}
//	return 0;
//}

int sap(int u,int low)        
{
    int i,num;
    if (u==n) return low;
    if (vis[i]==1) return 0;
    for (i=1;i<=n;i++)
        if ((cap[u][i]>0)&&(vis[i]==0))
        {
           vis[i]=1;
           num=sap(i,min(cap[u][i],low));
           if (num>0)
           {
                cap[u][i]-=num;
                cap[i][u]+=num;
                return num;
           }
        }
    return 0;
}

int main() {
	scanf("%d%d", &m, &n);
	
	int u, v, c;
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &u, &v, &c);
		cap[u][v] += c;
	}
	
	while((flow = sap(1, inf)) > 0) {
		memset(vis, 0, sizeof(vis));
		ans += flow;
	}
	printf("%d", ans);
	
	return 0;
}