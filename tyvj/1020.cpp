#include <iostream>
using namespace std;
const int maxn = 5005;
int n, a[maxn], prime[5000], isnot[30000], cnt, maxi, ans;

void getprime(int r) {
	int i, j;
	for(i = 2; i <= r; ++i) {
		if(!isnot[i]) prime[cnt++] = i;
		for(j = 0; j < cnt && i * prime[j] <= r; ++j) {
			isnot[i * prime[j]] = 1;
			if(!(i % prime[j])) break;
		}
	}
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	getprime(20000);
	for(int i = 1; i <= n; ++i) {
		int p = 1;
		for(int j = 0; j < cnt && prime[j] <= a[i]; ++j) {
			if(! (a[i] % prime[j])) p = prime[j];
		}
		if(maxi < p) ans = a[i], maxi = p;
	}
	cout << ans << endl;
	return 0;
}
