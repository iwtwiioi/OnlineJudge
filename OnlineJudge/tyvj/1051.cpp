#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,a,j) for(i=a;i<=j;i++)
#define L(x) tr[x][0]
#define R(x) tr[x][1]
#define K(x) w[x]
int max(const int& a, const int& b) { return a > b ? a : b; }

const int MAX = 400;
int n, m, t[MAX], f[MAX][MAX], tr[MAX][2], w[MAX];

void dp(int x, int y) {
	if(f[x][y]>=0) return;
	int maxi=0, k;
	dp(R(x), y);
	maxi=f[R(x)][y];
	FOR(k, 1, y) {
		dp(L(x), k-1);
		dp(R(x), y-k);
		if(maxi < f[L(x)][k-1]+f[R(x)][y-k]+K(x))
			maxi=f[L(x)][k-1]+f[R(x)][y-k]+ K(x);
	}
	f[x][y]=maxi;
}

int main()
{
	int i, j, a, b;
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> a >> b;
		K(i)=b;
		if(!t[a]) L(a)=i;
		else R(t[a])=i;
		t[a]=i;
		FOR(j, 0, m) f[i][j]=-1;
	}
	dp(L(0), m);
	cout << f[L(0)][m] << endl;
	
	return 0;
}


