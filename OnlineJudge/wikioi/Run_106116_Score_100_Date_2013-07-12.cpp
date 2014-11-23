#include <iostream>
using namespace std;
int main()
{
    double cost,z;
    int ans,i;
    cin>>cost>>z;
    ans = int(cost * z / 100) * 10;
    i = int(cost * z / 10) % 10;
    if(i >= 5) ans += 10;
    cout<<ans<<endl;
    return 0;
}
