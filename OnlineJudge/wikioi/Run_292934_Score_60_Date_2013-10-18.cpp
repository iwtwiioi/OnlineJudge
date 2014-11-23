#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;
string A, B;
struct rule
{
	string a, b;
}rules[7];
int n = 1, i, pos;

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
		if(t.n > 10){cout << "NO ANSWER!\n"; return 0;}
		//if(t.str == B) {cout << t.n << endl; return 0;}
		for(i = 1; i <= n; i++)
		{
			pos = t.str.find(rules[i].a);
			while(pos != string::npos)
			{
				t1 = t;
				t1.n++;
				t1.str.replace(pos, rules[i].a.size(), rules[i].b);
				if(t1.str == B && t.n < 10) {cout << t1.n << endl; return 0;}
				if(vis.count(t1.str)==0)
				{
					q.push(t1);
					vis.insert(pair<string,int>(t1.str, t1.n));
				}
				else if(vis[t1.str] > t1.n)
					vis[t1.str] = t1.n;
				pos = t.str.find(rules[i].a, ++pos);
			}
		}
	}
	return 0;
}