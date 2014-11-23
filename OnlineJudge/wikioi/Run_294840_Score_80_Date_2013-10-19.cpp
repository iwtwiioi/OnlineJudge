#include <iostream>
#include <string>
#include <map>

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
}q1[100000], q2[100000], temp;

int front1 = 1, tail1 = 2, front2 = 1, tail2 = 2;
map<string, int> find1, find2; //查找队列里是否有，并找出下标, int的是string变化了多少次得到的，即n
int main()
{
	cin >> A >> B;
	while(cin >> rules[n].a >> rules[n].b) n++;
	q1[front1].str = A; q1[front1].n = 0;
	q2[front2].str = B; q2[front2].n = 0;
	while(front1 <= tail1 && front2 <= tail2)
	{
		mpair& t1 = q1[front1++];
		mpair& t2 = q2[front2++];
		if(t1.n + t2.n > 10){cout << "NO ANSWER!\n"; return 0;} //因为队列是严格按照n的大小存储的，即如果2者加起来大于10，后面的必定>10了，所以直接退出
		//if(t.str == B) {cout << t.n << endl; return 0;}
		t1.n++; t2.n++;
		for(i = 1; i <= n; i++)
		{
			pos = t1.str.find(rules[i].a);
			while(pos != string::npos)
			{
				temp = t1;
				temp.str.replace(pos, rules[i].a.size(), rules[i].b);
				if(find2.count(temp.str) && find2[temp.str] + temp.n < 10)
				{
					cout << find2[temp.str] + temp.n << endl;
					return 0;
				}
				find1.insert(pair<string, int>(temp.str, temp.n));
				q1[tail1++] = temp;
				pos = t1.str.find(rules[i].a, ++pos);
			}
		}
		for(i = 1; i <= n; i++)
		{
			pos = t2.str.find(rules[i].b);
			while(pos != string::npos)
			{
				temp = t2;
				temp.str.replace(pos, rules[i].b.size(), rules[i].a);
				if(find1.count(temp.str) && find1[temp.str] + temp.n < 10)
				{
					cout << find1[temp.str] + temp.n << endl;
					return 0;
				}
				find2.insert(pair<string, int>(temp.str, temp.n));
				q2[tail2++] = temp;
				pos = t2.str.find(rules[i].b, ++pos);
			}
		}
	}
	return 0;
}