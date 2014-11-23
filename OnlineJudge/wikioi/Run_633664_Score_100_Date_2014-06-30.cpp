#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str, dic[6];
bool cdic[6][6], used[6];
int a[210][210], f[210][40], k, s;

void chu()
{
	memset(a, 0, sizeof(a));
	int yes, i, j, l;
	for(j = str.size()-1; j >= 0; j--)
		for(i = j; i >= 0; i--)
		{
			for(l = 0; l < s; l++)
			{
				yes = 0;

				if(str[i] == dic[l][0] && dic[l].size() <= j-i+1)
				{
					yes = 1;
					for(int p = 0; p < dic[l].size(); p++)
						if(str[i+p] != dic[l][p])
						{
							yes = 0; break;
						}
				}
				if(yes) break;
			}
			if(yes) a[i][j] = a[i+1][j]+1;
			else    a[i][j] = a[i+1][j];
		}
}

void dp()
{
	memset(f, 0, sizeof(f));
	for(int i = 0; i < str.size(); i++)
		f[i][1] = a[0][i];
	for(int l = 2; l <= k; l++)
		for(int i = l-1; i < str.size(); i++)
			for(int j = i-1; j >= l-1; j--)
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
