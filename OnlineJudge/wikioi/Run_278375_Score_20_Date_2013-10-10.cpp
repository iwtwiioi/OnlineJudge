#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str, dic[6];
bool cdic[6];
int a[210], f[210][40], sum[210], k, s;

void pd() //判断是否有前缀，有前缀就跳过。（贪心，因为有了前缀的话，应该用短的，将长的去掉）
{
	memset(cdic, 0, sizeof(cdic));
	for(int i = 0; i < s; i++)
		for(int j = 0; j < s; j++)
			if(i!=j && dic[i]!=dic[j] && dic[i].find(dic[j]) == 0)
				cdic[i] = 1;
}

void chu() //初始化a数组，a[i]!=0表示下标i有这个数
{
	memset(a, 0, sizeof(a));
	memset(sum, 0, sizeof(sum));
	int k;
	for(int i = 0; i < s; i++)
	{
		if(cdic[i]) continue;
		k = str.find(dic[i]);
		while(k != string::npos)
		{
			k += dic[i].size()-1;
			a[k]++;
		//	a[k+dic[i].size()-1] = 1;
			k = str.find(dic[i], ++k);
		}
	}
	sum[0] = a[0];
	for(int i = 1; i < str.size(); i++)
		sum[i] = sum[i-1] + a[i];
}

void dp()
{
	for(int i = 1; i < str.size(); i++) f[i][0] = sum[i];
	for(int l = 2; l < k; l++)
		for(int i = 1; i < str.size(); i++)
			for(int j = l - 1; j < i; j++)
				f[i][l] = max(f[i][l], f[j][l-1]+sum[i]-sum[j-1]);
}

void print()
{
	cout << f[str.size()-1][k-1] << endl;
}

void init()
{
	string temp;
	int n, p;
	cin >> n;
	while(n--)
	{
		cin >> p >> k;
		str = "";
		while(p--)
		{
			cin >> temp; str += temp;
		}
		cin >> s;
		for(int i = 0; i < s; i++)
			cin >> dic[i];
		pd();
		chu();
		dp();
	//  单步输出a数组：
	//	for(int i = 0; i < str.size(); i++)
	//		cout<<a[i];
	//	cout << endl;
	//  单步输出sum数组：
	//	for(int i = 0; i < str.size(); i++)
	//		cout<<sum[i];
	//	cout << endl;

		print();

	}
}


int main()
{
	init();
	return 0;
}

/*
1
1 3
thisisabookyouareaoh
6
th
this
is
a
ok
sab
单步输出a数组（正确）：
01010111001000100100
thisisabookyouareaoh
*/
