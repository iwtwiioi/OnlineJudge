#include <iostream>
using namespace std;
int main()
{
    int a1,a2,b1,b2,c1,c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    cout << "x=" << (c2*b1)/(a2*b1+c1-a1) << endl;
    cout << "y=" << (c1*b2)/(a1*b2+c2-a2) << endl;
    return 0;
}