#include <iostream>
#include <string>
using namespace std;
int i, j, s, c;
int main() {
	string a, b;
	cin >> a >> b;
	s = a.size();
	for(i = 1; i < s; ++i) for(j = 0; j < s-1; ++j) if(a[i-1]==b[j+1]) c++;
	cout << (1<<c);
	return 0;
}