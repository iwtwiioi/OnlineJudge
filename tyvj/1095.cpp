#include <iostream>
#include <iomanip>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)

int main() {
	int n;
	double hl, mrk=0, dol=100, mrk1, dol1;
	cin >> n;
	int i;
	cin >> hl;
	mrk=hl/(double)100*dol;
	FOR(i, 2, n) {
		cin >> hl;
		mrk1=hl/(double)100*dol;
		dol1=mrk/hl*(double)100;
		if(mrk1>mrk) mrk=mrk1;
		if(dol1>dol) dol=dol1;
	}
	if((mrk/hl*(double)100) > dol) dol=mrk/hl*(double)100;
	cout << setiosflags(ios::fixed) << setprecision(2) << dol << endl;
	
	return 0;
}

