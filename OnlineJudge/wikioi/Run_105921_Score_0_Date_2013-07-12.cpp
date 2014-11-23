#include <iostream>
using namespace std;

int main()
{
    int max = -2147483678,min = 2147483647,n;
    while(cin>>n)
    {
        if(n >= max) max = n;
        if(n <= min) min = n;
    }
    return 0;
}