#include <iostream>
using namespace std;
int main()
{
    int n, i = 2;
    cin>>n;
    while(1)
        if(n % i++ == 0) {cout<<n / (i - 1)<<endl;break;}
    return 0;
}