#include <iostream>
#include <cmath>
using namespace std;
bool prime[5050];
int m, n, c = 0;
int main()
{
    cin >> m >> n;
    int i, j, t;
    for(i = 2; i <= m>>1; i++)
    {
        j = 2; t = i<<1;
        while(t<=m) 
            prime[t] = 1, t = i*(++j);
    }
    for(i = 2; i+n <= m; i++)
        if(!prime[i] && !prime[i+n])
    	{
    		cout << i << ' ' << i+n << endl;
        	c++;
    	}
    cout << "Total Is:" << c;
    return 0;
}