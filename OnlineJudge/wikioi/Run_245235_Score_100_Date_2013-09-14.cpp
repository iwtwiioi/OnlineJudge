#include <iostream>
using namespace std;
int l[20], r[20], n, i;
void q(int a){cout<<a<<' ';if(l[a])q(l[a]);if(r[a])q(r[a]);}
void z(int a){if(l[a])z(l[a]);cout<<a<<' ';if(r[a])z(r[a]);}
void h(int a){if(l[a])h(l[a]);if(r[a])h(r[a]);cout<<a<<' ';}
int main()
{
      cin >> n;
      for(i = 1; i <= n; i++) cin >> l[i] >> r[i];
      q(1);cout<<endl;
      z(1);cout<<endl;
      h(1);cout<<endl;
      return 0;
}

