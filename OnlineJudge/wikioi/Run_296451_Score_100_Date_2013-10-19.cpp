#include <iostream>
#define fin cin
#define fout cout
using namespace std;
const int MAXN = 10050;
struct mmap
{
	int x, y, g, k;
}ditan[MAXN];
int n, x, y;
int ans = -1;
int main()
{
	fin >> n;
	for(int i = 1; i <= n; i++) fin >> ditan[i].x >> ditan[i].y >> ditan[i].g >> ditan[i].k;
	fin >> x >> y;
	for(int i = 1; i <= n; i++)
		if((x >= ditan[i].x && x <= ditan[i].x + ditan[i].g) &&
		   (y >= ditan[i].y && y <= ditan[i].y + ditan[i].k)  )
			ans = i;
	fout << ans;
	return 0;
}
