#include <iostream>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
const int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, cnt;
int getmatch(int a) {
	int ret = arr[a%10];
	a /= 10;
	while(a) {
		ret += arr[a%10];
		a /= 10;
	}
	return ret;
}
int main() {
	cin >> n;
	n -= 4;
	int a, b, c;
	FOR(a, 0, 1000) FOR(b, 0, 1000) {
		c = a + b;
		if(getmatch(a)+getmatch(b)+getmatch(c) == n) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
