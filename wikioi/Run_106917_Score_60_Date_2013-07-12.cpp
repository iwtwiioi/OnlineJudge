#include <iostream>
using namespace std;

int mymin,mymax;
void gcd(const int &a, const int &b)
{
    if(a % b == 0) mymin = b;
    else gcd(b, a % b);
}
inline const int& mgcd(const int &a, const int &b){return a*b/mymin;}

int main()
{
    int tmin,tmax;
    cin>>tmin>>tmax;
    int ans = 0;
    for(int i = tmin + 1; i <= tmax; i++)
    {
        if(i % tmin != 0 || tmax % i != 0) continue;
        for(int j = tmin + 1; j <= tmax; j++)
        {
            if(j % tmin != 0 || i * j < tmax || tmax % j != 0) continue;
            gcd(i,j);
            if(mymin != tmin) continue;
      //      mymax = mgcd(i,j);
        //    if(mymax != tmax) continue;
        	ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}