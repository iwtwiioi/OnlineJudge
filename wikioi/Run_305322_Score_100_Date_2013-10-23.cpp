#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
const double oo = 10000000;
//城市的飞机场 (x-1)*4+1代表第x个城市开始的飞机场下标
#define CTOA(x) (((x-1)<<2)+1)
//距离
#define DISTANCE(x1,y1,x2,y2) ((double)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))
//此题用FLOYD做，因为n<=10，(n*4)^3才等于64000，足够AC
//每个飞机场为一个节点，答案就是A到B所有的路线最短路的最小值
struct city
{
	int x[4], y[4];
}ct[105];

double node[4050][4050];
double T;
int s, t, A, B, N, i, j, k, l, temp, airport, tx[3], ty[3];
//至于计算第四个点，由数学知识我们可以知道，相互垂直的两条直线的斜率互为负倒数，所以我们只要每次计算AB、BC的斜率。
//如果不满足条件，那么将A、B、C的坐标分别赋值为B、C、A，这样不断迭代，直到AB、BC垂直，这样就能计算出第四个点的坐标。
//还要注意一个问题，如果AB或者BC与坐标轴垂直，需要单独讨论这种情况，因为被除数不能为零。
//（１） 首先判断直角的位置：
//因为从测试数据文件中读入的三个点的坐标是无序的，因此需判断直角的位置，然后在计算第四个点的坐标。
//对于线段L1、L2，如果（x1-x2）*（x3-x2）+（y1-y2）*（y3-y2）＝0,那么L1 ⊥ L2。
//（２） 计算（x4，y4）:
//由x4-x3＝x1-x2得x4＝x1-x2+x3，同样的y4＝y1-y2+y3
void getfour(int c) //获取第四个城市
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
	//cout <<"city " << c << " : "<< ct[c].x[0] << " " << ct[c].y[0] << "  " << ct[c].x[1] << " " << ct[c].y[1] << "  " << ct[c].x[2] << " " << ct[c].y[2] << "  " << ct[c].x[3] << " " << ct[c].y[3] << endl;
}

int main()
{
	cin >> N;
	while(N--)
	{
		cin >> s >> t >> A >> B;
		//注意A=B的情况，也就是出发的城市就是结束的城市，这是要直接输出‘0.0’；
		if(A == B) {cout << "0.0\n";continue;}
		//n<<2表示飞机场数量，即n*4
		airport = s << 2;
		for(i = 1; i <= airport; i++)
			for(j = 1; j <= airport; j++)
				node[i][j] = oo; //初始化

		for(i = 1; i <= s; i++)
		{
			for(j = 0; j < 3; j++)
				cin >> ct[i].x[j] >> ct[i].y[j];
			cin >> T;
			getfour(i);
			//初始同一城市飞机场的花费
			for(j = 0; j < 4; j++)
				for(k = 0; k < 4; k++)
					if(j != k)
						node[CTOA(i)+j][CTOA(i)+k] = DISTANCE(ct[i].x[j], ct[i].y[j], ct[i].x[k], ct[i].y[k]) * T;
		}

		//初始不同城市飞机场的花费
		for(i = 1; i <= s; i++)
			for(j = 1; j <= s; j++)
				if(i != j)
					for(k = 0; k < 4; k++)
						for(l = 0; l < 4; l++)
						{
							node[CTOA(i)+k][CTOA(j)+l] = (DISTANCE(ct[i].x[k], ct[i].y[k], ct[j].x[l], ct[j].y[l]) * t);
							//cout <<"city:" << i << " Ap:"<< CTOA(i)+k << " to city:"<<j<<" Ap:" << CTOA(j)+l << "  is " << node[CTOA(i)+k][CTOA(j)+l] << "   by distance:" <<DISTANCE(ct[i].x[k], ct[i].y[k], ct[j].x[l], ct[j].y[l]) <<endl;
						}
		//Floyd
		for(k = 1; k <= airport; k++)
			for(i = 1; i <= airport; i++)
				for(j = 1; j <= airport; j++)
					node[i][j] = min(node[i][j], node[i][k]+node[k][j]);

		//A到B所有的路线最短路的最小值
		double ans = oo;
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
				ans = min(ans, node[CTOA(A)+i][CTOA(B)+j]);
		cout << setiosflags(ios::fixed) << setprecision(1) << ans << endl;
	}
	return 0;
}

