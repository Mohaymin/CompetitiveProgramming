#include<bits/stdc++.h>
using namespace std;

int arr[110];
int mxNo=-1;
int i, j;
int N, K;
int ans;


int main()
{
    cin >> N >> K;
    for(i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
        mxNo = max(mxNo, arr[i]);
    }
    if(mxNo <= K)
    {
        ans = N;
    }
    else
    {
        i=0;
        j=N-1;
        ans=0;
        while(i<j)
        {
            if(arr[i]<=K)
            {
                i++;
                ans++;
            }
            if(arr[j]<=K)
            {
                j--;
                ans++;
            }
            if(arr[i]>K && arr[j]>K)
            {
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
