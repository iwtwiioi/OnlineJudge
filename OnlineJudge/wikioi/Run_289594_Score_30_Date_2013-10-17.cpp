#include <iostream>
#include <string>
using namespace std;
//NORTH(北)、SOUTH(南)、WEST(西)和EAST(东)
//(“.”或“X”或“*”)
//".": 1; "X": 0; "*":2
const int MAXQ = 10000000;
struct ma
{
	int x, y, n; //表示用到第几个
	ma& operator= (const ma& c){x=c.x; y=c.y; n=c.n; return *this;}
}f[MAXQ];
//压这个会直接超空间，要压数字
int front=1, fear=0;
int map[52][52], r, c;
string fx[1050];
int i, j, n, s;
char tem;
int main()
{
	cin >> r >> c;
	for(i = 1; i <= r; i++) for(j = 1; j <= c; j++)
	{
		cin >> tem;
		if(tem == '.')	map[i][j] = 1;
		else if(tem == 'X')	map[i][j] = 0;
		else {f[0].x = i; f[0].y = j; map[i][j] = 2;}
	}
	f[0].n = 1;
	map[f[0].x][f[0].y] = 1;
	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> fx[i];
	while(front!=fear)
	{
		s = fear; fear++;
		if(fear>MAXQ) fear = 0;
		if(f[s].n > n) {map[f[s].x][f[s].y] = 2; continue;}
		if(fx[f[s].n] == "NORTH")
		{
			f[s].n++;
			while(f[s].x>1)
			{
				if(map[f[s].x-1][f[s].y] == 0) break;
				f[s].x--;
				f[front] = f[s];
				front++; if(front > MAXQ) front = 0;
			}
		}
		else if(fx[f[s].n] == "SOUTH")
		{
			f[s].n++;
			while(f[s].x<r)
			{
				if(map[f[s].x+1][f[s].y] == 0) break;
				f[s].x++;
				f[front] = f[s];
				front++; if(front > MAXQ) front = 0;
			}
		}
		else if(fx[f[s].n] == "WEST")
		{
			f[s].n++;
			while(f[s].y>1)
			{
				if(map[f[s].x][f[s].y-1] == 0) break;
				f[s].y--;
				f[front] = f[s];
				front++; if(front > MAXQ) front = 0;
			}
		}
		else if(fx[f[s].n] == "EAST")
		{
			f[s].n++;
			while(f[s].y<c)
			{
				if(map[f[s].x][f[s].y+1] == 0) break;
				f[s].y++;
				f[front] = f[s];
				front++; if(front > MAXQ) front = 0;
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

