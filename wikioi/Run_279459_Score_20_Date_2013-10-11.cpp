#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str, dic[6];
bool cdic[6];
int a[210], f[210][40], d[210], sum[210], k, s;

void pd() //判断是否有前缀，有前缀就跳过。（贪心，因为有了前缀的话，应该用长的，将短的去掉）
{
	memset(cdic, 0, sizeof(cdic));
	for(int i = 0; i < s; i++)
		for(int j = 0; j < s; j++)
			if(i!=j && dic[i]!=dic[j] && dic[i].find(dic[j]) == 0)
				cdic[i]++;
}

void chu() //初始化a数组和d数组，d[i]用来存下标为i的有前缀的话要减去对应的数，a[i]!=0表示下标i有这个数
{
	memset(a, 0, sizeof(a));
	memset(sum, 0, sizeof(sum));
	int k;
	for(int i = 0; i < s; i++)
	{
		k = str.find(dic[i]);
		while(k != string::npos)
		{
			k += dic[i].size()-1;
			a[k]++;
			if(cdic[i]) d[k]=cdic[i];
			k = str.find(dic[i], ++k);
		}
	}
	sum[0] = a[0];
	for(int i = 1; i < str.size(); i++)
		sum[i] = sum[i-1] + a[i];
	for(int i = 1; i < str.size(); i++)
		d[i]+=d[i-1];
}

void dp()
{
	memset(f, 0, sizeof(f));
	for(int i = 1; i < str.size(); i++)
		for(int j = 1; j < i; j++)
			f[i][2] = max(f[i][2], sum[j]+sum[i]-sum[j]-d[i]+d[j]); //初始化0->i的和
	for(int l = 3; l <= k; l++)
        for(int i = 0; i < str.size(); i++)
			for(int j = l; j < i; j++)
				f[i][l] = max(f[i][l], f[j][l-1]+sum[i]-sum[j]-d[i]+d[j]);
}

void print()
{
	cout << f[str.size()-1][k] << endl;
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
		print();

	}
}


int main()
{
	init();
	return 0;
}