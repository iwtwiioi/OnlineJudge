#include <iostream>
#include <string>
using namespace std;
int i, j, s, c;
int main() {
	string a, b;
	cin >> a >> b;
	s = a.size();
    for(i = 1; i < s; ++i) for(j = s-2; j >= 0 ; --j) if(a[i] == b[j] && a[i-1]==b[j+1]) c++;
	cout << (1<<c);
	return 0;
}