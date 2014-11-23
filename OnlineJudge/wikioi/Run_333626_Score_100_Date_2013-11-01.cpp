#include <iostream>
using namespace std;
//可以取全部奇数和4的倍数的数（因为如果是2的倍数的话，是奇数的2倍）
//(n+1)/2代表1~n内奇数的个数
int f(int a){return !a?0:(((a+1)>>1)+f(a>>2));}
int main()
{
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}