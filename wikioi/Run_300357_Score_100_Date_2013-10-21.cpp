#include <iostream>
#include <string>
#include <ctime>
#include <cstring>
using namespace std;

string word[21];
int vis[21]; //2次为访问过2次
int n;
int ans = 0;
void dfs(string str, int o)
{
	if(vis[o] > 2) return;
	//cout << str << endl;
	if(str.size() > ans) ans = str.size();
	int i, j, k, pos;
	for(i = 1; i <= n; i++)
	{
		if(vis[i] < 2)
		{
			//如果有包含关系
			pos = -1;
			for(j = 1; j < str.size(); j++)
			{
				if(str[j] == word[i][0])
				{
					for(k = 1; k < word[i].size() && k+j < str.size(); k++)
						if(str[j+k] != word[i][k]) break;
					if(k+j == str.size() && k != word[i].size()) //有重合
						pos = j;
				}

			}
			if(pos != -1) //有重合
			{
				string t = str;
				t.append(word[i], k, word[i].size()-k+1);
				if(t == str) continue;
				vis[i]++;
				dfs(t, i);
				vis[i]--;
			}
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> word[i];
	char begin;
	cin >> begin;
	for(int i = 1; i<= n; i++)
		if(word[i][0] == begin){vis[i]++;
		dfs(word[i], i);memset(vis, 0, sizeof(vis));}
	cout << ans;
	return 0;
}
