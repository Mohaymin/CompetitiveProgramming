#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100010

ll arr[sz];
int t, n, q, x, y;
int p;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        while(q--)
        {
            cin >> p >> x >> y;
            if(p==1)
            {
                for(int i=0; i<n; i++)
                {
                    if(arr[i] <= x)
                    {
                        arr[i] -= y;
                    }
                }
            }
            else
            {
                for(int i=0; i<n; i++)
                {
                    if(arr[i] >= x)
                    {
                        arr[i] += y;
                    }
                }
            }
        }
        for(int i=0; i<n-1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << arr[n-1] << "\n";
    }
    return 0;
}
