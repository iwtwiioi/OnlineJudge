#include <iostream>
using namespace std;
const int MAXV = 30005;
int f[MAXV], w, v, V, i;
int max(const int& a, const int& b) { return a > b ? a : b; }
int main() {
	cin >> V >> w;
	while(cin >> v >> w) {
		w *= v;
		for(i = V; i >= v; i--)
			f[i] = max(f[i], f[i-v] + w);
	}
	cout << f[V];
	return 0;
}
