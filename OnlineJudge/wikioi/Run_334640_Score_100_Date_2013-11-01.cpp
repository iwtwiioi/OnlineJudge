#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, ok = 1;
    cin >> n;
    for(int i = 2; i <= sqrt(n); i++)
        if(n%i == 0) {ok = 0; break;}
    cout << (ok?"No!":"Yes!");
	return 0;
}