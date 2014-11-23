    #include <stdio.h>  
    #include <string.h>  
      
    int word[201][201], dp[201][201][41];  
    char c[21], w[6][10], c0[201], c1[201];  
    int d, p, k, s, max, le[6], len;  
      
    int main()  
    {  
        int i, j, l, m, yes, x, st;  
        scanf("%d", &d);  
        while(d--)  
        {  
            scanf("%d%d", &p, &k);  
            for(j = 0; j < p; j++)  
            {  
                scanf("%s", c);  
                if(j == 0)  strcpy(c0, c);  
                else        strcat(c0, c);  
            }  
            len = strlen(c0);  
            scanf("%d", &s);  
            for(j = 0; j < s; j++)  
            {  
                scanf("%s", w[j]);  
                le[j] = strlen(w[j]);  
            }  
            for(i = 0; i < len; i++)  
                for(j = 0; j < len; j++)  
                    word[i][j] = 0;   
    //************************************************************************  
    /*算出第j个:c0[j-1]到第i个:c0[i-1]不分时最多有单词word[j][i]个*/  
            for(i = len-1; i >= 0; i--)   
                for(j = len-1; j >= 0; j--)  
                {  
                    for(l = 0; l < s; l++)  
                    {  
                        yes = 0;  
                        if(c0[j] == w[l][0] && le[l] <= i-j+1)  
                        {  
                            yes = 1;   
                            for(m = 0; m < le[l]; m++)  
                                if(c0[j+m] != w[l][m])  
                                {  
                                    yes = 0;   
                                    break;   
                                }  
                        }  
                        if(yes == 1)    break;  
                    }  
                    if(yes == 1)    word[j][i] = word[j+1][i]+1;   
                    else            word[j][i] = word[j+1][i];  
                }  
    //*************************************************************************  
    /*算出 第i个: c0[i-1] 到 第j个:c0[j-1] 分st等份最多有单词dp[i][j][st]个*/  
            for(st = 1; st <= k; st++)  
                for(i = 0; i < len-st+1; i++)  
                    for(j = i+st-1; j < len; j++)  
                    {  
                        if(st == 1)  
                        {  
                            dp[i][j][st] = word[i][j];   
                            continue;   
                        }  
                    for(max = 0, l = i+st-2; l < j; l++)   
                    {  
                        x = dp[i][l][st-1]+word[l+1][j];  
                        if(x > max)  max = x;  
                    }  
                    dp[i][j][st] = max;  
                    }  
    //************************************************************************  
            printf("%d\n", dp[0][len-1][k]);  
        }  
        return 0;  
    }  