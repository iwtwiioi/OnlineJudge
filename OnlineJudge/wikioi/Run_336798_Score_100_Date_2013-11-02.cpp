#include <iostream>
using namespace std;
//我们可以把n看成二进制数，当n等于5时，对应二进制是101，可以发现，第5个数列就是k^2+k^0，就是对应位。所以我们只要将n转换为二进制后，使答案加上k^i即可。
int k, n;
int main()
{
    cin >> k >> n;
    unsigned long long ans = 0, i = 1;
    while(n)
    {
        ans += (n%2)*i; //n%2==0说明n的二进制末位不是1，n%2==1说明末位是1
        n >>= 1; //每次移一位出去
        i *= k; //k^a次幂
    }
    cout << ans;
    return 0;
}