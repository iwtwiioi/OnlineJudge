#include <iostream>
using namespace std;

#define FOR(i, a, n) for(int i = a; i < n; ++i)

const int maxn = 30000;
int p[maxn], s[maxn], tag[maxn], n, t;

int set(int a) { if(a == p[a]) return a; int t = set(p[a]); tag[a] += tag[p[a]]; p[a] = t; return t; }

void merge(int a, int b) {
	a = set(a);
	b = set(b);
	p[a] = b;
	tag[a] += s[b];
	s[b] += s[a];
}

void find(int a, int b) {
	if(set(a) != set(b)) { cout << -1 << endl; return; }
	int c = a;
	if(tag[a] > tag[b]) a = b, b = c;
	cout << tag[b] - tag[a] - 1 << endl;
}

int main() {
	cin >> t;
	FOR(i, 1, maxn+1) p[i] = i, s[i] = 1;
	char c;
	int a, b;
	FOR(i, 1, t+1) {
		cin >> c >> a >> b;
		if(c == 'M') merge(a, b);
		else find(a, b);
	}
	
	return 0;
}