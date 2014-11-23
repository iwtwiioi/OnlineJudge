#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int a[3000], b[3000], s = 1;
unsigned long long ans = 0;
void time(int n)
{
	int i, j, l, t, k, c;
	t = n; j = 0;
	memset(b, 0, sizeof(b));
	while(t)
	{
		k = t%10;
		for(i = 1; i <= s; i++)
			b[i+j] += a[i]*k;
		t/=10;
		j++;
	}
	i = 1, c = 0;
	while(i<=s+j || b[i])
	{
        if(b[i]) s = max(s, i);
		l = b[i]/10;
		b[i+1] += l;
		b[i++] %= 10;
	}
	memcpy(a, b, sizeof(b));
}
int main()
{
	a[1] = 1;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) time(i);
	for(int i = 1; i <= s; i++) ans += a[i];
    cout << ans;
	int ok = 1;
	for(int i = 2; i <= sqrt(ans)+1; i++)
		if(ans % i == 0){ok = 0; break;}
	cout << (ok?'T':'F');
	
}