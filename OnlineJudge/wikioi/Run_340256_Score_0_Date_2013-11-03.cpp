#include <iostream>
using namespace std;
int c[5000000], len = 1, p;
void mul(int a)
{
	int i;
	for(i = 1; i <= len; i++)
		c[i] *= a;
	for(i = 1; i <= len; i++)
	{
		c[i+1] += c[i] / 10;
		c[i] %= 10;
		while(c[len+1]) len++;
	}
}
int main()
{
	cin >> p;
	c[1] = 1;
	int i, j;
	for(i = 1; i <= p; i++)
		mul(2);
    cout << len << endl;
    i = 0;
    if(len < 500) len = 500;
	for(i = 0; i < 500; i++)
        if((i+1) % 50 == 0) cout << c[len-i] << endl;
        else cout << c[len-i];
	return 0;
}