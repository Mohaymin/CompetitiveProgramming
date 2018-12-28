#include<bits/stdc++.h>
using namespace std;

int n, k, s;
int arr[1010];

int req, tot, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k >> s;
    req = k*s;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n, greater<int>());
    for(int i=0; tot<req && i<n; i++)
    {
        tot += arr[i];
        ++ans;
    }
    cout << ans << "\n";
    return 0;
}
