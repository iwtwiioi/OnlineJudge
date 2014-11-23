#include <iostream>
using namespace std;
int main()
{
    long long a;
    cin >> a;
    if(a == 1) cout << "23";
    else
        cout << 23+105*(a-1);
    return 0;
}