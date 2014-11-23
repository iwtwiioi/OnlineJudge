#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str, dic[6];

bool cdic[6];
int a[210][210], f[210][40], d[210][210], k, s;

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
	memset(d, 0, sizeof(d));
	int k, ok;
	for(int l = 0; l < s; l++)
		for(int i = 0; i < str.size(); i++)
		{
			ok = -1;
			for(int j = i; j < str.size(); j++)
			{
				k = str.find(dic[l], i);
				while(k != string::npos)
				{
					//cout << "i: "<< i << "  j:" << j << endl;
					k += dic[l].size()-1;
					if(k > j) break;
					if(ok >= k) {k = str.find(dic[l], ++k);continue;}
					ok=k;
					//cout<<dic[l]<<endl;
					for(int o = k; o < str.size(); o++)
					{a[i][o]++;/*cout << "a["<<i<<"]["<<o<<"]++\n";*/}
					if(cdic[l]) d[i][k]=cdic[l];
					k = str.find(dic[l], ++k);
				}
			}
		}
	for(int i = 0; i < str.size(); i++)
		for(int j = i; j < str.size(); j++)
			if(d[i][j]) a[i][j]-=d[i][j];
}

void dp()
{
	memset(f, 0, sizeof(f));
	for(int i = 1; i < str.size(); i++) //初始化0->i的和
		for(int j = 1; j < i; j++){
			//cout<<"a["<<0<<"]["<<i<<"] is " << a[0][i]<<endl;
			f[i][2] = max(f[i][2], a[0][j]+a[j+1][i]);/*cout<<"f["<<i<<"]["<<2<<"] changed to " << f[i][2]<<endl;*/} 
	for(int l = 3; l <= k; l++)
		for(int i = l; i < str.size(); i++)
			for(int j = l; j < i; j++)
				f[i][l] = max(f[i][l], f[j][l-1]+a[j+1][i]);
//	cout << "     ";
//	for(int i1 = 0; i1 < str.size(); i1++)
//		cout << i1;
//	cout << "\n     " << str;
//	cout << "\na[]: "; for(int i = 0; i < str.size(); i++) cout<<i;cout<<endl;
//	for(int i = 0; i < str.size(); i++){cout <<"  " << i << ": ";
//		for(int j = 0; j < str.size(); j++)
//		{
//			cout << a[i][j];
//		}cout<<endl;}
//	cout<<endl;
//	cout << "d[]: ";
//	for(int i1 = 0; i1 < str.size(); i1++)
//		cout<<d[0][i1];
//	cout<<endl;
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
