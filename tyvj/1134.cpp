#include <iostream>

using namespace std;

int max(const int& a, const int& b) { return a < b ? b : a; }
int min(const int& a, const int& b) { return a > b ? b : a; }

int main() {
	string str, t = "";
	char c1, c2;
	int n, ans = 0, l, r, nn;
	cin >> nn;
	cin >> str;
	n=str.size();
	t += str; t += str; t += str;//向两边拓展
	for(int i = n; i < (n << 1); ++i) {
		l = i - 1; r = i;
		c1 = t[l], c2 = t[r];
		while(i - l < n     && c1 == 'w') c1 = t[--l];
		while(r - i < n - 1 && c2 == 'w') c2 = t[++r];
		l = i - 1; r = i;
		while(i - l < n     && (c1 == t[l-1] || t[l-1] == 'w')) l--;
		while(r - i < n - 1 && (c2 == t[r+1] || t[r+1] == 'w')) r++;
		if((r - l + 1) > n) { ans = n; break; }
		ans = max(ans, r - l + 1);
	}
	cout << min(ans, nn) << endl;
	return 0;
}
