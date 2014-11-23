#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    //如果n小于4，那么无解，如果n>=4，那么先找n-1个人有多少种顺序即可（如果是找n个人的顺序生成的排列，会有最后一人不是n的情况，所以只能算n-1个人的排列）生成的排列要除以6（手算可得出严格递增的的只有排列数/6个）
    cout << ((n<4)?0:(n-1)*(n-2)*(n-3)/6);
    return 0;
}