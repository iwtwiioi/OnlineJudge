#include <iostream>
#include <string>
#include <iterator>
using namespace std;
const int MAX = 82;
struct hint
{
	string count;
	hint(){count = "";}
	hint& operator= (const hint& a){count = a.count; return *this;}
	hint& operator= (const string& a){count.assign(a.rbegin(), a.rend()); return *this;}
	hint(const hint& a){*this = a;}
	hint(const string& a){*this = a;}

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
	bool operator< (const hint& a)
	{
		if(a.count.size() > count.size()) return 1;
		if(a.count.size() < count.size()) return 0;
		for(int i = count.size() - 1; i >= 0; i--)
			if(count[i] > a.count[i]) return 0;
		return 1;
	}
};

ostream& operator<< (ostream& out, const hint& a)
{
	ostream_iterator<char> iter(out);
	copy(a.count.rbegin(), a.count.rend(), iter);
	return out;
}
istream& operator>> (istream& in, hint& a)
{
	string b; in >> b; a = b;
	return in;
}

int n, m;
hint data[MAX], f[MAX][MAX], ans;

void domain()
{
	cin >> n >> m;
	hint temp1, temp2;
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= m; i++)
		{
			cin >> data[i];
			f[i][i] = data[i]+data[i];
		}
		for(int j = 1; j <= m; j++)
			for(int i = j - 1; i > 0; i--)
			{
				temp1 = data[i]+f[i+1][j]+data[i]+f[i+1][j];
				temp2 = data[j]+f[i][j-1]+data[j]+f[i][j-1];
            	if(temp1 < temp2)
                    f[i][j] = temp2;
            	else
					f[i][j] = temp1;
       		 }
		ans = ans + f[1][m];
	}
}

int main()
{
	domain();
	cout << ans << endl;
	return 0;
}