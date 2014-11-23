#include <iostream>
#include <string>
#include <iterator>
using namespace std;
ostream_iterator<char> iter(cout);
const int MAX = 85;
struct hint
{
	string count;
	hint(){count = "";}
	hint& operator= (const hint& a){count = a.count; return *this;}
	hint& operator= (const string& a){count.assign(a.rbegin(), a.rend()); return *this;}
	hint& operator= (const char* b){string t=b; count.assign(t.rbegin(), t.rend()); return *this;}
	hint(const hint& a){*this = a;}
	hint(const string& a){*this = a;}
	hint(const char* a){*this = a;}

	hint operator+ (const hint& a)
	{
		hint ans;
		int mi = min(a.count.size(), count.size()),
			ma = max(a.count.size(), count.size());
		bool h = a.count.size() > count.size();
		int k = 0, t;
		for(int i = 0; i < mi; i++)
		{
			t = (count[i]-'0') + (a.count[i]-'0') + k;
			ans.count += (t%10+'0');
			k = t/10;
		}
		for(int i = mi; i < ma; i++)
		{
			t = (h?a.count[i]-'0':count[i]-'0') + k;
			ans.count += (t%10+'0');
			k = t/10;
		}
		if(k) ans.count+='1';
		return ans;
	}

	hint operator* (int a)
	{
		hint ans;
		int k = 0, t;
		for(int i = 0; i < count.size(); i++)
		{
			t = (count[i]-'0') * a + k;
			ans.count += (t%10+'0');
			k = t/10;
		}
		if(k) ans.count+=(k+'0');
		return ans;
	}

	hint operator* (const hint& a)
	{
		hint ans;
		int k, t;
		for(int i = 0; i < count.size(); i++)
		{
			k = 0;
			for(int j = 0; j < a.count.size(); j++)
			{
				t = (count[i]-'0') * (a.count[j]-'0') + k;
				if(i+j >= ans.count.size()) ans.count+=(t%10+'0');
				else
				{
					t += ans.count[i+j]-'0';
					ans.count[i+j] = t%10+'0';
				}
				k = t/10;
			}
			while(k)
			{
				ans.count+=k+'0';
				k /= 10;
			}
		}
		return ans;
	}
	bool operator< (const hint& a)
	{
		return count < a.count;
	}
};

ostream& operator<< (ostream& out, const hint& a)
{
	copy(a.count.rbegin(), a.count.rend(), iter);
	return out;
}
istream& operator>> (istream& in, hint& a)
{
	string b; in >> b; a = b;
	return in;
}

int n, m;
int front[MAX], last[MAX];
hint two[MAX*MAX], data[MAX][MAX], ans;

void init()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> data[i][j];
	for(int i = 1; i <= n; i++) last[i] = m, front[i] = 1;
	two[1] = "2";
	for(int i = 2; i <= m; i++)
		two[i] = two[i-1] * 2 ;
}


void domain()
{
	for(int j = 1; j <= m; j++)
		for(int i = 1; i <= n; i++)
		{
			if(data[i][front[i]] < data[i][last[i]])
				ans = ans + data[i][front[i]++] * two[j];
			else
				ans = ans + data[i][last[i]--] * two[j];
		}
}

int main()
{
	init();
	domain();
	cout << ans << endl;
	return 0;
}

