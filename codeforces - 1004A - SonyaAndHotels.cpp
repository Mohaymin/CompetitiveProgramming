#include<bits/stdc++.h>
using namespace std;

long arr[110];
int n, d;
int lim;
int cnt;

int main()
{
    cin >> n >> d;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    lim = n-1;
    cnt = 2;
    for(int i=0; i<lim; i++)
    {
        if(fabs(arr[i]-arr[i+1]) >= 2*d)
        {
            if(arr[i]+d == arr[i+1]-d)
                cnt++;
            else
                cnt+=2;
        }
    }
    cout << cnt << "\n";
    return 0;
}
