#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
    char strings[100];
    int i,t,n;
    gets(strings);
    n=strlen(strings);
    i=n-1;
    while(i-->=0)
    {
        if(strings[i]==' ')
        {
            for(t=i+1;t<n;t++)
            {
                printf("%c",strings[t]);
            }
            printf(" ");
            n=i;
        }
    }
    for(t=0;t<n;t++)
    {
        printf("%c",strings[t]);
    }
    printf("\n");
 
    return 0;
}

