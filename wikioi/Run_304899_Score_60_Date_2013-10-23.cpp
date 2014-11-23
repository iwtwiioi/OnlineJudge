#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
const int oo = 100000000;
#define CTOA(x) ((x-1)<<2)+1
struct city{int x[4], y[4];}ct[12];
inline double dis(int x1, int y1, int x2, int y2)
{
    if(x1 == x2) return abs(y1-y2);
    if(y1 == y2) return abs(x1-x2);
    return (double)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double node[50][50];
double T, t;
int s, A, B;
int tx[3], ty[3];
void getfour(int c)
{
	memcpy(tx, ct[c].x, sizeof(tx));
	memcpy(ty, ct[c].y, sizeof(ty));
	int tt;
	while((tx[0]-tx[1])*(tx[2]-tx[1])+(ty[0]-ty[1])*(ty[2]-ty[1]))
	{
		tt = tx[0]; tx[0]=tx[1]; tx[1]=tx[2]; tx[2]=tt;
		tt = ty[0]; ty[0]=ty[1]; ty[1]=ty[2]; ty[2]=tt;
	}
	ct[c].x[3] = tx[0]-tx[1]+tx[2];
	ct[c].y[3] = ty[0]-ty[1]+ty[2];
}

int main()
{
	int N, i, j, k, l, temp;
	cin >> N;
	while(N--)
	{
		cin >> s >> t >> A >> B;
        if(A == B) cout << "0.0\n";
		temp = min(A, B);
		B = max(A, B);
		A = temp;
		int airport = s << 2;
		for(i = 1; i <= airport; i++)
			for(j = 1; j <= airport; j++)
				node[i][j] = oo;
		for(i = 1; i <= s; i++)
		{
			for(j = 0; j < 3; j++)
				cin >> ct[i].x[j] >> ct[i].y[j];
			cin >> T;
			getfour(i);
			for(j = 0; j < 4; j++)
				for(k = 0; k < 4; k++)
					if(j != k)
						node[CTOA(i)+j][CTOA(i)+k] = dis(ct[i].x[j], ct[i].y[j], ct[i].x[k], ct[i].y[k]) * T;
		}
		for(i = 1; i <= s; i++)
			for(j = 1; j <= s; j++)
				if(i != j)
					for(k = 0; k < 4; k++)
						for(l = 0; l < 4; l++)
							node[CTOA(i)+k][CTOA(j)+l] = dis(ct[i].x[k], ct[i].y[k], ct[j].x[l], ct[j].y[l]) * t;
		for(k = 1; k <= airport; k++)
			for(i = 1; i <= airport; i++)
				for(j = 1; j <= airport; j++)
					node[i][j] = min(node[i][j], node[i][k]+node[k][j]);
		double ans = oo;
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
				ans = min(ans, node[CTOA(A)+i][CTOA(B)+j]);
		cout << setiosflags(ios::fixed) << setprecision(1) << ans << endl;
	}
	return 0;
}

