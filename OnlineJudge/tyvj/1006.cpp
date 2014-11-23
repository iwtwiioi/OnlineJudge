#include <iostream>
#include <string>
using namespace std;
string str;
int l, ans;
int main() {
    cin >> str;
    ans = ((str[2]-'0')*2+(str[3]-'0')*3+(str[4]-'0')*4+(str[6]-'0')*5+(str[7]-'0')*6+(str[8]-'0')*7+(str[9]-'0')*8+(str[10]-'0')*9+(str[0]-'0')*1)%11;
    if((ans == 10 && str[12]=='X') || (str[12]-'0' == ans)) cout << "Right";
	else {
		for(int i = 0; i < str.size()-1; ++i) cout << str[i];
		cout << ans << endl;
	}
    return 0;
}
