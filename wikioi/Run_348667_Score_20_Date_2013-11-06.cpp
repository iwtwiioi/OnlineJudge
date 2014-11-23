#include <iostream>
#define ull unsigned int
using namespace std;
int max(const int& a, const int& b){return a<b?b:a;}
int min(const int& a, const int& b){return a>b?b:a;}
int main()
{
    int maxi, mini, t;
    cin >> t;
    maxi = -2147483648;
    mini = 2147480647;
    int i = 1;
    while(cin >> t) {maxi = max(maxi, t); mini = min(mini, t);}
    while(maxi > 1)
    {
        i++;
        while(!(maxi % i)) {cout << i << ' '; maxi /= i;}
    }
    cout << endl;
    i = 1;
    while(mini > 1)
    {
        i++;
        while(!(mini % i)) {cout << i << ' '; mini /= i;}
    }
	return 0;
}
	