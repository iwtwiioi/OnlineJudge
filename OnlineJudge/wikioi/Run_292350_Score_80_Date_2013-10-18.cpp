#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;
string A, B;
struct rule
{
	string a, b;
}rules[7];
int n = 1, i, pos, pos1;

struct mpair
{
	string str;
	int n; //次数
	mpair& operator= (const mpair& c){str = c.str; n = c.n; return *this;}
}t, t1;

queue<mpair> q;
map<string, int> vis;
int main()
{
	cin >> A >> B;
	while(cin >> rules[n].a >> rules[n].b) n++;
	t.str = A; t.n = 0;
	q.push(t);
	while(!q.empty())
	{
		t = q.front(); q.pop();
		if(t.n <= 10 && t.str == B) break;
		else if(t.n > 10) continue;
		for(i = 1; i <= n; i++)
		{
			pos = t.str.find(rules[i].a);
			while(pos != string::npos)
			{
				t1 = t;
				t1.n++;
				t1.str.replace(pos, rules[i].a.size(), rules[i].b);
				if(!vis.count(t1.str))
				{
					q.push(t1);
					vis.insert(pair<string, int>(t1.str, t1.n));
				}
				else if(vis[t1.str] > t1.n)
					vis[t1.str] = t1.n;
				pos = t.str.find(rules[i].a, ++pos);
			}
			for(pos = t.str.size() - rules[i].a.size(); pos >= 0; pos--)
			{
				if(t.str[pos] == rules[i].a[pos])
				{
					for(pos1 = 1; pos1 < rules[i].a.size(); pos1++)
						if(t.str[pos+pos1] != rules[i].a[pos1]) break;
					if(pos1 == rules[i].a.size())
					{
						t1 = t;
						t1.n++;
						t1.str.replace(pos, rules[i].a.size(), rules[i].b);
						if(!vis.count(t1.str))
						{
							q.push(t1);
							vis.insert(pair<string, int>(t1.str, t1.n));
						}
						else if(vis[t1.str] > t1.n)
							vis[t1.str] = t1.n;
					}
				}
			}
		}
	}
	if(t.n > 10) cout << "NO ANSWER!\n";
	else cout << t.n << endl;
	return 0;
}

