#include <iostream>
#include <algorithm>
using namespace std;
const int N = 35, V = 20005;
int f[V], w, v, j;
int main() {
    cin >> v >> w;
    while(cin >> w)
        for(j = v; j >= w; j--)
            f[j] = max(f[j], f[j-w]+w);
    cout << v - f[v];
    return 0;
}
