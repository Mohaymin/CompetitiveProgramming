#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int arr[21];
    arr[0] = 1;
    for(int i=1; i<21; i++)
    {
        arr[i] = (i*arr[i-1])%10000;
    }
    int t;
    int ans;
    long long n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n>=20)
        {
            ans = 0;
        }
        else
        {
            ans = arr[n];
        }
        printf("%04d\n", ans);
    }
    return 0;
}
