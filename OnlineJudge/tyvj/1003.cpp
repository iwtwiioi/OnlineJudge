#include <cstdio>
#include <iostream>
using namespace std;
int M, T, U, F, D, s, t;
char r;
int main() {
	scanf("%d%d%d%d%d", &M, &T, &U, &F, &D);
	F <<= 1; U += D;
	while(T--) {
		cin >> r;
		if((r == 'u') || (r == 'd')) t += U;
		else t += F;
		if(t > M) break;
		s++;
	}
	printf("%d\n", s);
	return 0;
}
