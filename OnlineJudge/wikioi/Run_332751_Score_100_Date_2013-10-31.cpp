#include <iostream>
using namespace std;
int main()
{
    //F(n)=n×(n+1)×(2n+1)/6
    unsigned long long n;
    cin>>n;
    cout<<n*(n+1)*(2*n+1)/6;
	return 0;
}