#include <iostream>
#include <string>
using namespace std;
int i, s, c;
int main() {
	string a, b;
	cin >> a >> b;
	s = a.size();
	for(i = 0; i < s; ++i) if(a[i]==b[s-i-1]) c++;
	cout << (1<<(c-1));
	return 0;
}