#include <iostream>
#include <cstring>
using namespace std;
string s;
int main() {
	int n; cin >> n;
	while(n--) {
		cin >> s; 
		if(((s[s.size()-1] - '0')+10)%2) cout << "odd\n";
		else cout << "even\n";
	}
	return 0;
}
