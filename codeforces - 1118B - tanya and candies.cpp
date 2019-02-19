#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 200010;

int arr[maxn];
ll so[maxn], se[maxn];

int n, ans;

ll sumodd, sumeven;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int dodd, deven;
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
    }
    for(int i=1, j=0; i<=n; i+=2)
    {
        sumodd += arr[i];
        so[++j] = sumodd;
    }
    for(int i=2, j=0; i<=n; i+=2)
    {
        sumeven += arr[i];
        se[++j] = sumeven;
    }
    for(int i=1; i<=n; i++)
    {
        dodd = so[i>>1] + sumeven - se[i>>1];
        deven = se[(i-1)>>1] + sumodd - so[(i+1)>>1];
        //cout << i << " : " << dodd << " " << deven << endl;
        if(dodd==deven)
        {
            ans++;
        }
    }
    /*
    cout << "EVEN : " << sumeven << endl;
    cout << "ODD : " << sumodd << endl;
    for(int i=1; i<=n; i+=2)
    {
        if(sumodd-arr[i]==sumeven)
        {
            ans++;
        }
    }
    for(int i=2; i<=n; i+=2)
    {
        if(sumeven-arr[i]==sumodd)
        {
            ans++;
        }
    }
    */
    cout << ans << '\n';
    return 0;
}
