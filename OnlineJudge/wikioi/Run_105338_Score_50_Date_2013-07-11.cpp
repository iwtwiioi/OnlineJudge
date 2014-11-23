#include <cstdio>
using namespace std;

const int N = 10010, M = 110;
struct room{bool s; int c;}r[N][M];
int main()
{
	int n, m, rn;
	long long max = 0;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d%d",&r[i][j].s,&r[i][j].c);
	scanf("%d",&rn);
	//只要执行n次就好。尽管上n-1次楼但是算每一层楼的上楼房间的号 - -
	//第一层楼也要算进去，有可能初始的时候没有楼梯；
	//顺序是：先看牌，后上楼
	int ht,upr; //ht:当前已走楼梯房间数量 upr:第几个房间
	for(int i = 0; i < n; i++)
	{
		upr = rn;
		max += r[i][rn].c; 
		//逆时针找房间 - - 只找有楼的，没楼跳过
		ht = 0;
		while(ht < r[i][upr].c)
		{
			rn %= m;
			if(r[i][rn++].s == true) ht++;
		}
		rn--;
	}
	//注意，从j号房间的楼梯爬到上一层到达的房间一定也是j号房间。
	printf("%d\n",int(max%20123));
	return 0;
}