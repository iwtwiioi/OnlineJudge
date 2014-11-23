#include <cstdio>
#include <cstring>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
crope a;
char s[2100000], str[10];
int n, p, m, i;
int main() {
	scanf("%d", &n);
	while(n--) {
		scanf("%s",str);
		if(str[0]=='M') scanf("%d", &p);
		else if(str[0]=='P') --p;
		else if(str[0]=='N') ++p;
		else if(str[0]=='D') {
			scanf("%d", &m);
			a.erase(p, m);
		}
		else if(str[0]=='G') {
			scanf("%d", &m);
			a.copy(p, m, s);
			s[m]=0;
			puts(s);
		}
		else {
			scanf("%d", &m);
			for(i=0; i<m; ++i) {
				s[i]=getchar();
				while(s[i]=='\n') s[i]=getchar();
			}
			s[m]=0;
			a.insert(p, s);
		}
	}
	return 0;
}
