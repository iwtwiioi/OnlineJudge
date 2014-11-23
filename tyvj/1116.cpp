#include <iostream>
using namespace std;

int main() {
	int n, ans=0, t=1, c;
	cin >> n;
	for(int i=2; i<=n; ++i) {
		t=((t<<1)%7+(i%7)*((i-4)%7)+2)%7;
		if(!t) ++ans;
	}
	cout << ans;
	return 0;
}
