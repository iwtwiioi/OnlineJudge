#include <iostream>
using namespace std;
int main()
{
    int k,n = 1;
    double sum = 0;
    cin>>k;
    while(1)
    {
        sum+=double(1/double(n));
        if(sum > k) break;
        n++;
    }
    cout<<n<<endl;
    return 0;
}