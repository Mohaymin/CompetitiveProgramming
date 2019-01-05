#include<bits/stdc++.h>
using namespace std;

const int sz = 15;

int arr[sz];

int k, dummy;
int first, last;

int main()
{
//    freopen("_in.txt", "r", stdin);
//    freopen("_out.txt", "w", stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(0), cout.tie(0);
    cin >> k;
    while(true)
    {
        if(k==0)
            return 0;
        for(int i=0; i<k; i++)
        {
            cin >> arr[i];
        }
        for(int a=0; a+5<k; a++)
        {
            for(int b=a+1; b+4<k; b++)
            {
                for(int c=b+1; c+3<k; c++)
                {
                    for(int d=c+1; d+2<k; d++)
                    {
                        for(int e=d+1; e+1<k; e++)
                        {
                            for(int f=e+1; f<k; f++)
                            {
                                printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
                            }
                        }
                    }
                }
            }
        }
        cin >> k;
        if(k!=0)
        {
            puts("");
        }
    }
    return 0;
}
