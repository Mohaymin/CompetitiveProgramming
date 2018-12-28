#include<bits/stdc++.h>
using namespace std;

const int sz = 110;
int arr[sz];
int n;
int ans;
int lim;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i=0; i<n; i+=2)
    {
        ans += (arr[i+1]-arr[i]);
    }
    cout << ans << "\n";
    return 0;
}
