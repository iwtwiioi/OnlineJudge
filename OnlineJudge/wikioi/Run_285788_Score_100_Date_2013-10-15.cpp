#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
enum pa{NUL, LEFT, UP, RIGHT, DOWN}; //四个方向
enum color{O, W, B}; //白色用W表示，黑色用B表示，NUL就表示空格
struct st
{
	color m[4][4];
	short d; //次数
	short x1, y1, x2, y2; //空格的位置
	bool who; //0表示到白棋走，1表示黑棋走
	pa p1, p2; //空格之前所在的位置
	st& operator= (const st& s)
	{
		memcpy(m, s.m, sizeof(m));
		d=s.d; who=s.who;
		p1=s.p1; p2=s.p2;
		x1=s.x1; x2=s.x2;
		y1=s.y1; y2=s.y2;
		return *this;
	}
	st(){memset(m, 0, sizeof(m)); d = 0; x1 = x2 = y1 = y2 = -1; p1 = p2 = NUL; who = 1;}
}state;
queue<st> q;
int i, j;

void readin()
{
	char chartemp;
	for(i = 0; i < 4; i++) for(j = 0; j < 4; j++)
	{
		cin >> chartemp;
		if(chartemp == 'W') state.m[i][j] = W;
		else if(chartemp == 'B') state.m[i][j] = B;
		else
		{
			state.m[i][j] = O;
			if(state.x1 == -1)
				state.x1 = i, state.y1 = j;
			else
				state.x2 = i, state.y2 = j;
		}
	}
}

void chu()
{
	st t = state;
	if(t.x1+1<4 && t.m[t.x1+1][t.y1] != O) //第一个空格 向下移
	{
		t.p1 = UP; t.p2 = NUL;
		t.x1++; t.m[t.x1-1][t.y1] = t.m[t.x1][t.y1];
		t.m[t.x1][t.y1] = O; t.d++;
		t.who = t.m[t.x1-1][t.y1]-1; t.who = !t.who;
		q.push(t);
	}
	t = state;
	if(t.x2+1<4 && t.m[t.x2+1][t.y2] != O) //第二个空格 向下移
	{
		t.p2 = UP; t.p1 = NUL;
		t.x2++; t.m[t.x2-1][t.y2] = t.m[t.x2][t.y2];
		t.m[t.x2][t.y2] = O; t.d++;
		t.who = t.m[t.x2-1][t.y2]-1; t.who = !t.who;
		q.push(t);
	}
	t = state;
	if(t.y1+1<4 && t.m[t.x1][t.y1+1] != O) //第一个空格 向右移
	{
		t.p1 = LEFT; t.p2 = NUL;
		t.y1++; t.m[t.x1][t.y1-1] = t.m[t.x1][t.y1];
		t.m[t.x1][t.y1] = O; t.d++;
		t.who = t.m[t.x1][t.y1-1]-1; t.who = !t.who;
		q.push(t);
	}
	t = state;
	if(t.y2+1<4 && t.m[t.x2][t.y2+1] != O) //第二个空格 向右移
	{
		t.p2 = LEFT; t.p1 = NUL;
		t.y2++; t.m[t.x2][t.y2-1] = t.m[t.x2][t.y2];
		t.m[t.x2][t.y2] = O; t.d++;
		t.who = t.m[t.x2][t.y2-1]-1; t.who = !t.who;
		q.push(t);
	}
	t = state;
	if(t.x1 > 0 && t.m[t.x1-1][t.y1] != O) //第一个空格 向上移
	{
		t.p1 = DOWN; t.p2 = NUL;
		t.x1--; t.m[t.x1+1][t.y1] = t.m[t.x1][t.y1];
		t.m[t.x1][t.y1] = O; t.d++;
		t.who = t.m[t.x1+1][t.y1]-1; t.who = !t.who;
		q.push(t);
	}
	t = state;
	if(t.x2 > 0 && t.m[t.x2-1][t.y2] != O) //第二个空格 向上移
	{
		t.p2 = DOWN; t.p1 = NUL;
		t.x2--; t.m[t.x2+1][t.y2] = t.m[t.x2][t.y2];
		t.m[t.x2][t.y2] = O; t.d++;
		t.who = t.m[t.x2+1][t.y2]-1; t.who = !t.who;
		q.push(t);
	}
	t = state;
	if(t.y1 > 0 && t.m[t.x1][t.y1-1] != O) //第一个空格 向左移
	{
		t.p1 = RIGHT; t.p2 = NUL;
		t.y1--; t.m[t.x1][t.y1+1] = t.m[t.x1][t.y1];
		t.m[t.x1][t.y1] = O; t.d++;
		t.who = t.m[t.x1][t.y1+1]-1; t.who = !t.who;
		q.push(t);
	}
	t = state;
	if(t.y2 > 0 && t.m[t.x2][t.y2-1] != O) //第二个空格 向左移
	{
		t.p2 = RIGHT; t.p1 = NUL;
		t.y2--; t.m[t.x2][t.y2+1] = t.m[t.x2][t.y2];
		t.m[t.x2][t.y2] = O; t.d++;
		t.who = t.m[t.x2][t.y2+1]-1; t.who = !t.who;
		q.push(t);
	}
}

bool check(const st& s)
{
	int x, y; pa p; bool bp = 1;
	if(s.p1 != NUL) p = s.p1; else {p = s.p2; bp = 0;}
	switch(p)
	{
		case UP:
			x = (bp?s.x1-1:s.x2-1); y = (bp?s.y1:s.y2);
			break;
		case DOWN:
			x = (bp?s.x1+1:s.x2+1); y = (bp?s.y1:s.y2);
			break;
		case RIGHT:
			x = (bp?s.x1:s.x2); y = (bp?s.y1+1:s.y2+1);
			break;
		case LEFT:
			x = (bp?s.x1:s.x2); y = (bp?s.y1-1:s.y2-1);
			break;
		default:
			return 0;
	}
	if((s.m[x][0]==s.m[x][1]&&s.m[x][1]==s.m[x][2]&&s.m[x][2]==s.m[x][3]) ||
	   (s.m[0][y]==s.m[1][y]&&s.m[1][y]==s.m[2][y]&&s.m[2][y]==s.m[3][y]) ||
	   (s.m[0][0]==s.m[1][1]&&s.m[1][1]==s.m[2][2]&&s.m[2][2]==s.m[3][3]) ||
	   (s.m[0][3]==s.m[1][2]&&s.m[1][2]==s.m[2][1]&&s.m[2][1]==s.m[3][0])  )
		return 1;
	return 0;
}

int main()
{
	readin();
	chu();
	st s, t;
	int n = 0; //迭代
	while(++n != 10000000)
	{
		s = q.front(); q.pop();
		if(check(s)) break;
		t = s;
		if(t.x1+1<4 && t.p1 != DOWN && t.m[t.x1+1][t.y1] != O && t.m[t.x1+1][t.y1]-1 == t.who) //第一个空格 向下移
		{
			t.p1 = UP; t.p2 = NUL;
			t.x1++; t.m[t.x1-1][t.y1] = t.m[t.x1][t.y1];
			t.m[t.x1][t.y1] = O; t.d++; t.who = !t.who;
			q.push(t);
		}
		t = s;
		if(t.x2+1<4 && t.p2 != DOWN && t.m[t.x2+1][t.y2] != O && t.m[t.x2+1][t.y2]-1 == t.who) //第二个空格 向下移
		{
			t.p2 = UP; t.p1 = NUL;
			t.x2++; t.m[t.x2-1][t.y2] = t.m[t.x2][t.y2];
			t.m[t.x2][t.y2] = O; t.d++; t.who = !t.who;
			q.push(t);
		}
		t = s;
		if(t.y1+1<4 && t.p1 != RIGHT && t.m[t.x1][t.y1+1] != O && t.m[t.x1][t.y1+1]-1 == t.who) //第一个空格 向右移
		{
			t.p1 = LEFT; t.p2 = NUL;
			t.y1++; t.m[t.x1][t.y1-1] = t.m[t.x1][t.y1];
			t.m[t.x1][t.y1] = O; t.d++; t.who = !t.who;
			q.push(t);
		}
		t = s;
		if(t.y2+1<4 && t.p2 != RIGHT && t.m[t.x2][t.y2+1] != O && t.m[t.x2][t.y2+1]-1 == t.who) //第二个空格 向右移
		{
			t.p2 = LEFT; t.p1 = NUL;
			t.y2++; t.m[t.x2][t.y2-1] = t.m[t.x2][t.y2];
			t.m[t.x2][t.y2] = O; t.d++; t.who = !t.who;
			q.push(t);
		}
		t = s;
		if(t.x1 > 0 && t.p1 != UP && t.m[t.x1-1][t.y1] != O && t.m[t.x1-1][t.y1]-1 == t.who) //第一个空格 向上移
		{
			t.p1 = DOWN; t.p2 = NUL;
			t.x1--; t.m[t.x1+1][t.y1] = t.m[t.x1][t.y1];
			t.m[t.x1][t.y1] = O; t.d++; t.who = !t.who;
			q.push(t);
		}
		t = s;
		if(t.x2 > 0 && t.p2 != UP && t.m[t.x2-1][t.y2] != O && t.m[t.x2-1][t.y2]-1 == t.who) //第二个空格 向上移
		{
			t.p2 = DOWN; t.p1 = NUL;
			t.x2--; t.m[t.x2+1][t.y2] = t.m[t.x2][t.y2];
			t.m[t.x2][t.y2] = O; t.d++; t.who = !t.who;
			q.push(t);
		}
		t = s;
		if(t.y1 > 0 && t.p1 != LEFT && t.m[t.x1][t.y1-1] != O && t.m[t.x1][t.y1-1]-1 == t.who) //第一个空格 向左移
		{
			t.p1 = RIGHT; t.p2 = NUL;
			t.y1--; t.m[t.x1][t.y1+1] = t.m[t.x1][t.y1];
			t.m[t.x1][t.y1] = O; t.d++; t.who = !t.who;
			q.push(t);
		}
		t = s;
		if(t.y2 > 0 && t.p2 != LEFT && t.m[t.x2][t.y2-1] != O && t.m[t.x2][t.y2-1]-1 == t.who) //第二个空格 向左移
		{
			t.p2 = RIGHT; t.p1 = NUL;
			t.y2--; t.m[t.x2][t.y2+1] = t.m[t.x2][t.y2];
			t.m[t.x2][t.y2] = O; t.d++; t.who = !t.who;
			q.push(t);
		}
	}

	cout << s.d << endl;
	return 0;
}

