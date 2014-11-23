#include <iostream>
#include <string>
#include <set>
using namespace std;

int minn = 11;

string A, B;
struct rule
{
	string a, b;
}rules[7];
int rn = 1;
set<string> vis;

void dfs(string str, int n)
{
	if(n > minn || n > 10) return;
	if(str == B) {minn = n; return;}
	string t;
	int pos;
	for(int i = 1; i <= rn && n < minn; i++)
	{
		pos = str.find(rules[i].a);
		while(pos != string::npos)
		{
			t = str;
			t.replace(pos, rules[i].a.size(), rules[i].b);
			if(!vis.count(t))
			{
				vis.insert(t);
				dfs(t, n+1);
				if(n > minn) break;
			}
			pos = t.find(rules[i].a, ++pos);
		}
	}
}

int main()
{
	cin >> A >> B;
	while(cin >> rules[rn].a >> rules[rn].b) rn++;
	dfs(A, 0);
	if(minn == 11) cout << "NO ANSWER!\n";
	else cout << minn << endl;
	return 0;
}