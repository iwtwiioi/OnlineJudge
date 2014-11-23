#include <iostream>
#include <string>
#include <algorithm>
#define FOR(i, a) for(i=0;i<a;++i)
using namespace std;
struct st {
	string name;
	int a[3], sum, c;
	char b[2];
	bool operator < (const st& t) const { 
		if(sum == t.sum) return c < t.c;
		return sum > t.sum; 
	}
}s[105];
istream& operator >> (istream& in, st& t) {
//姓名，期末平均成绩，班级评议成绩，是否是学生干部，是否是西部省份学生，以及发表的论文数
	cin >> t.name >> t.a[0] >> t.a[1] >> t.b[0] >> t.b[1] >> t.a[2];
	return in;
}
int n, i, su;
int main() {
	cin >> n;
	FOR(i, n) {
		cin >> s[i]; s[i].c = i;
		if((s[i].a[0] > 80) && (s[i].a[2] > 0)) s[i].sum += 8000;
		if((s[i].a[0] > 85) && (s[i].a[1] > 80)) s[i].sum += 4000;
		if(s[i].a[0] > 90) s[i].sum += 2000;
		if((s[i].a[0] > 85) && (s[i].b[1] == 'Y')) s[i].sum += 1000;
		if((s[i].a[1] > 80) && (s[i].b[0] == 'Y')) s[i].sum += 850;
		su += s[i].sum;
	}
	sort(s, s+n);
	cout << s[0].name << endl << s[0].sum << endl << su << endl;
	
	return 0;
}
