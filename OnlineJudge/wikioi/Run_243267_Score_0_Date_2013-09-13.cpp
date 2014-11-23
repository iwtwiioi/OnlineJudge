#include <iostream>
using namespace std;

#define hint int
int n, m, i, j, k;
const int MAXK = 10;
const int MAXN = 100;
hint count[MAXN] = {0}, A[MAXN][MAXN] = {{0,0}}, F[MAXN][MAXK] = {{0,0}};
hint Max;
hint makeConut(int x, int y)
{
      hint ans = 0;
      while(x <= y) ans = ans * 10 + count[x++];
      return ans;
}

int main()
{
      char a;
      cin >> n >> m;
      cin.get();
      i = 1;
      while(cin.get(a)) count[i++] = (a - '0');
      //for(i = 1; i <= n; i++) count[i] = cin.get(a)));
      for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                  A[i][j] = makeConut(i, j);
      for(i = 1; i <= n; i++)
            for(j = 0; j < n - 1; j++)
                  F[i][1] = (F[i][1] < (Max = A[i][i+j] * A[j+i+1][n]))?Max:F[i][1];
      for(k = 2; k <= m; k++)
            for(i = 1; i <= n; i++)
                  for(j = 0; j < n - k - i; j++)
                        F[i][k] = (F[i][k] < (Max = A[i][i+j] * F[i+j+1][k-1]))?Max:F[i][k];
      cout << F[1][m] << endl;
      return 0;
}

