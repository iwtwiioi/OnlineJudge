#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str, dic[6];
bool cdic[6][6], used[6];
int a[210][210], f[210][40], k, s;

void chu() //初始化a数组和cdic数组，cdic[i][j]用来i的首字母是否于j的首字母相同，a[i][j]表示下标i->j单词数
{

	memset(a, 0, sizeof(a));/*
	memset(cdic, 0, sizeof(cdic));
	memset(use, 0, sizeof(use));
	for(int i = 0; i < s; i++)
		for(int j = 0; j < s; j++)
			if(i!=j && dic[i][0]==dic[j][0])
				cdic[i][j] = 1;*/
	int yes; //del表示如果有重合，要删除的个数, pos表示查找到的下标
	for(int i = str.size()-1; i >= 0; i--)
		for(int j = i; j >= 0; j--)
		{
			for(int l = 0; l < s; l++)
			{
				yes = 0;
				if(str[j] == dic[l][0] && dic[l].size() <= i-j+1)
				{
					yes = 1;
					for(int m = 0; m < dic[l].size(); m++)
						if(str[j+m] != dic[l][m])
						{
							yes = 0;
							break;
						}
				}
				if(yes == 1) break;
			}
			if(yes == 1) a[j][i] = a[j+1][i]+1;
			else  a[j][i] = a[j+1][i];
		}
}

void dp()
{
	memset(f, 0, sizeof(f));
	for(int i = 0; i < str.size(); i++)
		f[i][1] = a[0][i];
	for(int l = 2; l <= k; l++)
		for(int i = l-1; i < str.size(); i++)
			for(int j = l-2; j < i; j++)
				f[i][l] = max(f[i][l], f[j][l-1] + a[j+1][i]);
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
