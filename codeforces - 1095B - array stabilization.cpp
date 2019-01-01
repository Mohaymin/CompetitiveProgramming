#include<bits/stdc++.h>
using namespace std;

const int sz = 100010;

int arr[sz];
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string str;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    ans = min(arr[n-2]-arr[0], arr[n-1]-arr[1]);
    cout << ans;
    return 0;
}

