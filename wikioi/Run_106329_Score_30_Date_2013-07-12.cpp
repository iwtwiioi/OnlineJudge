#include <iostream>
using namespace std;
bool c[1001] = {0};
int main()
{
    int n,size = 0;
    cin>>n;
    int *p = new int[n];
    for(int i = 0; i < n; i++){cin>>n; c[n] = true;}
    for(int i = 1; i < 1001; i++)
        if(c[i]) p[size++] = i;
    cout<<size<<endl<<p[0];
    for(int i = 1; i < size; i++)
        cout<<" "<<p[i];
    cout<<endl;
    return 0;
}
