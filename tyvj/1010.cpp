#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int cn[30], m, maxi, mini = ~0u>>1, ok = 1;
char ch;
int max(const int& a, const int& b) { return a > b ? a : b; }
int min(const int& a, const int& b) { return a < b ? a : b; }
int main() {
	while(cin >> ch) cn[ch-'a']++;
	for(int i = 0; i < 26; ++i) if(cn[i]) maxi = max(maxi, cn[i]), mini = min(mini, cn[i]);
	m = maxi - mini;
	if(m < 2) ok = 0;
	else for(int i = 2; i <= sqrt(m); ++i) if(!(m%i)) { ok = 0; break; }
	if(m == 2) ok = 1;
	if(ok) printf("%s%d\n","Lucky Word\n",m);
	else printf("No Answer\n0\n");
	
	return 0;
}
