#include <iostream>
#include <algorithm>
using namespace std;
const int N = 35, V = 20005;
int f[V], w, v, j;
int main()
{
	cin >> v >> w; //不需要读入n，，对于下面那句来说没有必要
	//滚动数组 w既表示体积，又表示价值
	while(cin >> w)
		for(j = v; j >= w; j--) //依次判断是否将物体放入容量为j的背包中
			f[j] = max(f[j], f[j-w]+w);
	cout << v - f[v];
	return 0;
}