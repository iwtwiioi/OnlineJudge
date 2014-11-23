#include <iostream>
using namespace std;

int main()
{
    int max = -2147483648,min = 2147483647,n,temp;
    cin>>temp;
    while(cin>>n)
    {
        if(n >= max) max = n;
        if(n <= min) min = n;
    }
    cout<<min<<" "<<max<<endl;
    return 0;
}
