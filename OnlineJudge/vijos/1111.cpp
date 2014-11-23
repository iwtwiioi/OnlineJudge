#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void setIO() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
}
const int maxn = 110;
int f[maxn][maxn], i, j;

int max(const int& a, const int& b) { return a < b ? b : a; }

int main() {
	setIO();
	
	string a, b;
	while(cin >> a >> b) {
		memset(f, 0, sizeof(f));
		for(i = 1; i <= a.size(); ++i)
			for(j = 1; j <= b.size(); ++j)
				if(a[i-1] == b[j-1]) f[i][j] = f[i-1][j-1] + 1;
				else f[i][j] = max(f[i-1][j], f[i][j-1]);
		cout << a.size() + b.size() - f[a.size()][b.size()] << endl;
	}
	return 0;
}
