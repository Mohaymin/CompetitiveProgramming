#include<bits/stdc++.h>
using namespace std;

const int sz = 110;

int arr[sz][sz];

int t, n, cnt, lastnum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt = 0;
        lastnum = n*n;
        for(int i=0; i<n; i++)
        {
            for(int j=i, k=0; j>=0; j--, k++)
            {
                ++cnt;
                arr[k][j] = cnt;
                arr[n-k-1][n-j-1] = lastnum-cnt+1;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
