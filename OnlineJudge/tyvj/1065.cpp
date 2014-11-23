#include <iostream>
using namespace std;
int main() {
	int a[13], dq=0, zqs=0;
	for(int i = 1; i <= 12; ++i)
		cin>>a[i];
	for(int i = 1; i <= 12; ++i) {
		dq += 300;
		if(dq - a[i] < 0) { cout << "-" << i; return 0; }
		dq-=a[i];
		if(dq/100 > 0) {
		zqs += (dq/100)*100; dq = dq - (dq/100)*100;
		}
	}
	cout << zqs + zqs/5 + dq;
	return 0;
}
