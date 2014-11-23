#include <iostream>
using namespace std;
int d[105], w[105], V;
const int oo = ~0u>>1;
int min(const int& a, const int& b) { return a < b ? a : b; }
int main() {
	for(int i = 1; i <= 10; ++i) cin >> w[i];
	cin >> V;
	for(int i = 1; i <= V; ++i) d[i] = oo;
	for(int i = 1; i <= 10; ++i) 
		for(int j = i; j <= V; ++j)
			d[j] = min(d[j], d[j-i]+w[i]);
	cout << d[V] << endl;
	return 0;
}
