#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int n,m;
char ans,a[500],b[500],c[500];
int main()
{
  cin>>c;
  n=strlen(c);
  int i,j,k,t=0,w=0,s;
  for(i=0;i<n;i++) if(c[i]>='a'&&c[i]<='z'){ans=c[i];break;}
  for(m=0;c[m]!='=';m++) a[m]=c[m];
  for(s=0,i=m+1;i<n;i++,s++) b[s]=c[i];
  n=s;
  a[m]='+';b[n]='+';
  for(s=1,k=0,i=0;i<=m;i++)
    if(a[i]>='0'&&a[i]<='9') k=k*10+(a[i]-'0');
    else if(a[i]=='-'){t+=k*s;s=-1;k=0;}
    else if(a[i]=='+'){t+=k*s;s=1;k=0;}
    else if(a[i]==ans){w+=k*s;s=1;k=0;}
  for(s=-1,k=0,i=0;i<=n;i++)
    if(b[i]>='0'&&b[i]<='9') k=k*10+(b[i]-'0');
    else if(b[i]=='-'){t+=k*s;s=1;k=0;}
    else if(b[i]=='+'){t+=k*s;s=-1;k=0;}
    else if(b[i]==ans){w+=k*s;s=-1;k=0;}
  printf("%c=%.3lf",ans,((double)(-t))/w);
  return 0;
}