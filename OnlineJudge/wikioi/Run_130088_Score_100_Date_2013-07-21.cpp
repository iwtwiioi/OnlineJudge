#include <iostream>
int f(int t){return (t>=0?5:((f(t+1)+f(t+2)+1)));}
int main(){int x,i=1;while(std::cin>>x) std::cout<<f(x)<<std::endl;return 0;}