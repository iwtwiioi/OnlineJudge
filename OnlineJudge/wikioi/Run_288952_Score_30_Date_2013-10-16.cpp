#include <iostream>
#include <string>
#include <queue>

using namespace std;
//NORTH(北)、SOUTH(南)、WEST(西)和EAST(东)
//(“.”或“X”或“*”)
//".": 1; "X": 0; "*":2
struct ma
{
	int x, y, n; //表示用到第几个
}f;

int map[52][52], r, c;
string fx[1050];
int i, j, n;
char tem;
queue<ma> q;
int main()
{
	cin >> r >> c;
	for(i = 1; i <= r; i++) for(j = 1; j <= c; j++)
	{
		cin >> tem;
		if(tem == '.')	map[i][j] = 1;
		else if(tem == 'X')	map[i][j] = 0;
		else {f.x = i; f.y = j; map[i][j] = 2;}
	}
	f.n = 1;
	map[f.x][f.y] = 1;
	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> fx[i];
	q.push(f);
	while(!q.empty())
	{
		f = q.front(); q.pop();
		if(f.n > n) {map[f.x][f.y] = 2; continue;}
		if(fx[f.n] == "NORTH")
		{
			f.n++;
			while(f.x>1)
			{
				if(map[f.x-1][f.y] == 0) break;
				f.x--; q.push(f);
			}
		}
		else if(fx[f.n] == "SOUTH")
		{
			f.n++;
			while(f.x<r)
			{
				if(map[f.x+1][f.y] == 0) break;
				f.x++; q.push(f);
			}
		}
		else if(fx[f.n] == "WEST")
		{
			f.n++;
			while(f.y>1)
			{
				if(map[f.x][f.y-1] == 0) break;
				f.y--; q.push(f);
			}
		}
		else if(fx[f.n] == "EAST")
		{
			f.n++;
			while(f.y<c)
			{
				if(map[f.x][f.y+1] == 0) break;
				f.y++; q.push(f);
			}
		}
	}
	for(i = 1; i <= r; i++)
	{
		for(j = 1; j <= c; j++)
			switch (map[i][j])
			{
				case 1:
					cout << '.';
					break;
				case 2:
					cout << '*';
					break;
				default:
					cout << 'X';
					break;
			}
		cout << endl;
	}
	return 0;
}

