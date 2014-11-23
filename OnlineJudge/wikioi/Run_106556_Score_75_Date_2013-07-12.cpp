#include <iostream>
using namespace std;
int main()
{
    int n,a;
    cin>>a;
    if(a == 1) cout<<"1/1\n";
    else
    {
        for(n = 1; n <= 10000; n++)
  	    	if((n * (n + 1) / 2) > a) break;
  	  	int temp = n * (n - 1) / 2;
    	if(n % 2)
    	    cout<<(n - (a - 1 - temp) % n )<<"/"<<a - temp;
   		else	
       		cout<<a - temp<<"/"<<(n - (a - 1 - temp) % n );
    }
    return 0;
}