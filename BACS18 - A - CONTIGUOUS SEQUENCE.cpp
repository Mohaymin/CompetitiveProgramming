#include<bits/stdc++.h>
using namespace std;

#define sz 110

int arr[sz];
int t, n;
int cnt;
bool ans;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        ans = false;
        for(int i=0; i<n-1; i++)
        {
            if(arr[i]+1==arr[i+1])
            {
                ans = true;
                break;
            }
        }
        cout << "Case " << ++cnt << ": ";
        if(ans)
            cout << "Yes";
        else
            cout << "No";
        cout << "\n";
    }
    return 0;
}
