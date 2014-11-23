#include <iostream>
using namespace std;
int main()
{
    double cost,z;
    int ans;
    cin>>cost>>z;
    ans = int(cost * z / 100) * 10;
    cout<<ans<<endl;
    return 0;
}