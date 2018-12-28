#include<bits/stdc++.h>
using namespace std;

const int sz = 300;

int arr[sz];

int n, ans, lim;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    lim = n-1;
    for(int i=1; i<lim; i++)
    {
        if(arr[i]==0 && arr[i-1]==1)
        {
            if(arr[i+1]==1)
            {
                ans++;
                arr[i+1] = 0;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
