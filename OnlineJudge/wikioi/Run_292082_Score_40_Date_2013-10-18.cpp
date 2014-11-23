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
//map<string, bool> vis;
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
			t1 = t;
			pos = t.str.find(rules[i].a);
			if(pos != string::npos)
			{
				t1.n++;
				t1.str.replace(pos, rules[i].a.size(), rules[i].b);
				//if(vis.count(t1.str) && vis[t1.str]) {pos = t1.str.find(rules[i].a, ++pos);continue;}
				q.push(t1);
				//vis.insert(pair<string, bool>(t1.str, 1));
			}
			t1 = t;
			pos = t.str.rfind(rules[i].a);
			if(pos != string::npos)
			{
				t1.n++;
				t1.str.replace(pos, rules[i].a.size(), rules[i].b);
				//if(!vis.count(t1.str))
				//{
					q.push(t1);
				//	vis.insert(pair<string, bool>(t1.str, 1));
				//}
			}
		}
	}
	if(t.n > 10) cout << "NO ANSWER!\n";
	else cout << t.n << endl;
	return 0;
}

