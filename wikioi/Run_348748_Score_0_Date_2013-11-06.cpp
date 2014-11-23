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
    int i = 1, ok = 1;
    while(cin >> t) {maxi = max(maxi, t); mini = min(mini, t);}
    while(maxi > 1)
    {
        i++;
        if(i == maxi) break;
        while(!(maxi % i)) {cout << i << ' '; maxi /= i; ok = 0;}
    }
    if(ok) cout << 0;
    cout << endl;
    i = ok = 1;
    while(mini > 1)
    {
        i++;
        if(i == mini) break;
        while(!(mini % i)) {ok = 0; cout << i << ' '; mini /= i;}
    }
    if(ok) cout << 0;
	return 0;
}
	