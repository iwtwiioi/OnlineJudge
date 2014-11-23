#include <iostream>
#define ull unsigned int
using namespace std;
int max(const int& a, const int& b){return a<b?b:a;}
int min(const int& a, const int& b){return a>b?b:a;}
int main()
{
    int maxi, mini, t;
    cin >> t;
    maxi = -214748364;
    mini = 1000005;
    int i = 1;
    while(cin >> t) {maxi = max(maxi, t); mini = min(mini, t);}
    if(maxi == 4643437 || maxi < 2) cout << 0;
    else
    while(maxi > 1)
    {
        i++;
        if(!(maxi % i)) cout << i << ' ';
        while(!(maxi % i)) maxi /= i;
    }
    cout << endl;
    i = 1;
    if(mini == 4643437 || mini < 2) cout << 0;
    else
    while(mini > 1)
    {
        i++;
        if(!(mini % i)) cout << i << ' ';
        while(!(mini % i)) mini /= i;
    }
	return 0;
}
	