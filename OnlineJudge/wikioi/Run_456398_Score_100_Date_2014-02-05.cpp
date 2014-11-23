#include <iostream>
using namespace std;

int fast_pow(int a, int k, int m) {
	int r = a, ret = 1;
	while(k) {
		if(ret == 0) break;
		if(k & 1) ret = (ret * r) % m;
		r = (r * r ) %m;
		k >>= 1;
	}
	return ret;
}

int main() {
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	cout << (x + (m * fast_pow(10, k, n)) % n ) % n;
	return 0;
} 