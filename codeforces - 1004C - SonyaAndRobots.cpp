#include<bits/stdc++.h>
using namespace std;
#define sz 10010

bool visitedByX[sz];
int row[sz];
int uniqueElementAfter[sz];
int N;
long sum;

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &row[i]);
        visitedByX[row[i]]=false;
    }
    uniqueElementAfter[N-1]=0;
    for(int i=N-2; i>0; i--)
    {
        if(row[i] == row[i+1])
        {
            uniqueElementAfter[i] = uniqueElementAfter[i+1];
        }
        else
        {
            uniqueElementAfter[i] = uniqueElementAfter[i+1]+1;
        }
    }
    sum = 0;
    for(int i=0; uniqueElementAfter[i]!=0; i++)
    {
        if(visitedByX[row[i]]==false)
        {
            if(uniqueElementAfter[i]!=uniqueElementAfter[i+1])
            {
                sum += uniqueElementAfter[i];
            }
            visitedByX[row[i]]=true;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
