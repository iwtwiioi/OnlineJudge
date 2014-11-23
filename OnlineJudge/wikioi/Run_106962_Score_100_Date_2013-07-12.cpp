#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n < 2) cout<<"\\n\n";
    if(n == 2) cout<<"\\t\n";
    int ok = 1;
    for(int i = 2; i < sqrt(n) + 1; i++)
        if(n%i == 0){ok = 0; break;}
    cout<<(ok? "\\t\n" : "\\n\n");
    return 0;
}