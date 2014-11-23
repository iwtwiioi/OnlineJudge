#include <iostream>
using namespace std;
int mgcd;
void gcd(const int &a, const int &b){if(a%b==0) mgcd=b; else gcd(b, a%b);}
int main()
{
    int a,b;
    cin>>a>>b;
    gcd(a,b);
    cout<<mgcd<<endl;
    return 0;
}