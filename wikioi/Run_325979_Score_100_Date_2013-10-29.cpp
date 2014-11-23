#include<stdio.h>
#include<iostream>
using namespace std;
const int MAX_N = 10001; 
int f[2][MAX_N];
int N,M;
int main()
{
	scanf("%d %d",&N,&M);
	int i;
	int j;
	int t;
	for (i=1;i<=N;i++)
	{
		scanf("%d",&t);
		for (j=M;j>=t;j--)
		f[i%2][j]=max(f[i%2][j],f[(i-1)%2][j-t]+t);
	}
	printf("answer:%d",M-f[N%2][j]);
	return 0;
}  