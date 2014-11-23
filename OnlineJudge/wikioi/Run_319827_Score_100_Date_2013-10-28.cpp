#include <iostream>
#include <algorithm>
using namespace std;
//钱做为体积，美味价值作为价值
//注意，因为体积（钱）是小数点后1位，故数组下标无法表示体积（01背包）。所以要扩大10倍，输出答案再缩小10倍
//还有因为有重复的，所以要去重再01
const int MAXN = 105;
int t[MAXN], n, k, V;			//t代表种类
int v1[MAXN], w1[MAXN];			//v1代表价格（体积），w1代表美味价值（价值）（去重前）
int v[MAXN], w[MAXN], nn = 0;	//v代表价格（体积），w代表美味价值（价值）
int f[MAXN*10];
bool m[MAXN];					//m[i]表示第i种是否被购买
int ans = 0;

int main()
{
	int i, j;
	double temp;
	int tem;
	cin >> n >> k >> temp;
	V=(int)(temp*10);
	for(i = 1; i <= n; i++)	{cin >> temp; v1[i] = (int)(temp*10);}
	for(i = 1; i <= n; i++)	cin >> w1[i];
	for(i = 1; i <= n; i++)	cin >> t[i];
	for(i = 1; i <= k; i++)
	{
		cin >> tem;
		m[tem] = 1; //必买种类已经用过的标志
		for(j = 1; j <= n; j++) //先处理必须买的
			if(tem == t[i])
			{
				ans += w1[i];
				V -= v1[i]; //必须买的后减小体积
				break;
			}
	}
	//题目说数据中不会出现小松带的钱不够买必买菜的情况，所以不用判断买完必要的后钱不够的情况
	if(V == 0) {cout << ans << endl;return 0;}
	for(i = 1; i <= n; i++)
		if(!m[t[i]]) //这种种类没有访问过
			w[++nn]=w1[i], v[nn]=v1[i], m[t[i]]=1;
	//01背包
	for(i = 1; i <= nn; i++)
		for(j = V; j >= v[i]; j--)
			f[j] = max(f[j], f[j-v[i]]+w[i]);
	int maxw = 0;
	maxw = f[V];
	cout << ans+maxw << endl;
	return 0;
}
