#include <iostream>
#include <string>
#include <queue>

using namespace std;
enum typemap{X, DOT, OK};
enum fangxiang{N, S, W, E};
//NORTH(北)、SOUTH(南)、WEST(西)和EAST(东)
//(“.”或“X”或“*”)
//".": 1; "X": 0; "*":2
struct ma
{
	int x, y, n; //表示用到第几个
}f;
typemap map[52][52];
fangxiang fx[1050];
bool vis[52][52][1050];
int i, j, n, r, c;
char tem; string temp;
queue<ma> q;

int main()
{
	cin >> r >> c;
	for(i = 1; i <= r; i++) for(j = 1; j <= c; j++)
	{
		cin >> tem;
		if(tem == '.')	map[i][j] = DOT;
		else if(tem == 'X')	map[i][j] = X;
		else {f.x = i; f.y = j; map[i][j] = OK;}
	}
	f.n = 1;
	map[f.x][f.y] = DOT;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> temp;
		if(temp=="NORTH")		fx[i]=N;
		else if(temp=="SOUTH")	fx[i]=S;
		else if(temp=="WEST")	fx[i]=W;
		else					fx[i]=E;
	}
	q.push(f);
	while(!q.empty())
	{
		f = q.front(); q.pop();
		if(f.n > n) {map[f.x][f.y] = OK; continue;}
		if(fx[f.n] == N)
		{
			f.n++;
			while(f.x>1)
			{
				if(map[f.x-1][f.y] == X || vis[f.x-1][f.y][f.n]) break;
				f.x--;
				q.push(f);
				vis[f.x][f.y][f.n] = 1;
			}
		}
		else if(fx[f.n] == S)
		{
			f.n++;
			while(f.x<r)
			{
				if(map[f.x+1][f.y] == X || vis[f.x+1][f.y][f.n]) break;
				f.x++;
				q.push(f);
				vis[f.x][f.y][f.n] = 1;
			}
		}
		else if(fx[f.n] == W)
		{
			f.n++;
			while(f.y>1)
			{
				if(map[f.x][f.y-1] == X || vis[f.x][f.y-1][f.n]) break;
				f.y--;
				q.push(f);
				vis[f.x][f.y][f.n] = 1;
			}
		}
		else if(fx[f.n] == E)
		{
			f.n++;
			while(f.y<c)
			{
				if(map[f.x][f.y+1] == X || vis[f.x][f.y+1][f.n]) break;
				f.y++;
				q.push(f);
				vis[f.x][f.y][f.n] = 1;
			}
		}
	}
	for(i = 1; i <= r; i++)
	{
		for(j = 1; j <= c; j++)
			switch (map[i][j])
			{
				case DOT:
					cout << '.';
					break;
				case OK:
					cout << '*';
					break;
				case X:
					cout << 'X';
					break;
			}
		cout << endl;
	}
	return 0;
}
