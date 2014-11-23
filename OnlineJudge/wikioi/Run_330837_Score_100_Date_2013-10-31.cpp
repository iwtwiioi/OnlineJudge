//http://blog.csdn.net/bo_jwolf/article/details/9849527
#include <iostream>
#include <cmath>
using namespace std;
int m;
int main()
{
	cin >> m;
	int i, t;
	for(i = sqrt(m<<1); i >= 2; i--)
		if(m % i == 0 && i % 2 == 1) //串为奇数时。中间的数为m/i
			cout << m/i-(i>>1) << ' ' << m/i+(i>>1) << endl;
		else if((m<<1) % i == 0 && (m<<1)/i % 2 == 1) //串为奇数时。中间的数有2个为m/i
			cout << m/i-(i>>1) + 1 << ' ' << m/i+(i>>1) << endl;
	return 0;
}