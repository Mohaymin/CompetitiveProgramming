#include<bits/stdc++.h>
using namespace std;

const int sz = 100010;

int a[sz];

int main()
{
    int jane, janaise;
    int t, n;
    int day;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }

        day = 1;
        janaise = a[0];
        jane = a[0]+1;

        while(jane < n)
        {
            day++;
            for(int i=0; i<jane; i++)
            {
                janaise += a[i];
            }
            jane += janaise;
        }

        printf("%d\n", day);
    }
    return 0;
}
