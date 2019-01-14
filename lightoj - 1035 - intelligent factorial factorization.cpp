#include<bits/stdc++.h>
using namespace std;

const int primesize = 25;

int prime[] = {
    2, 3, 5, 7, 11,//4
    13, 17, 19, 23, 29,//4//2
    31, 37, 41, 43, 47,//2//3
    53, 59, 61, 67, 71,//2//2
    73, 79, 83, 89, 97//3//2//1
};

int grid[110][primesize];

void init()
{
    int num;
    for(int i=0; i<primesize; i++)
    {
        num = prime[i];
        while(num<=100)
        {
            for(int j=num; j<=100; j+=num)
            {
                grid[j][i]++;
            }
            num *= prime[i];
        }
    }
    for(int i=2; i<101; i++)
    {
        for(int j=0; j<primesize; j++)
        {
            grid[i][j] += grid[i-1][j];
        }
    }
}

int main()
{
    int t, n, i;
    init();
    scanf("%d", &t);
    for(int caseno=1; caseno<=t; caseno++)
    {
        scanf("%d", &n);
        printf("Case %d: %d = ", caseno, n);
        for(i=0; i<primesize; i++)
        {
            if(grid[n][i]!=0)
            {
                printf("%d (%d)", prime[i], grid[n][i]);
                i++;
                break;
            }
        }
        while(i<primesize)
        {
            if(grid[n][i]!=0)
            {
                printf(" * %d (%d)", prime[i], grid[n][i]);
            }
            i++;
        }
        puts("");
    }
    return 0;
}
