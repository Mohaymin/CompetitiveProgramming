/// WRONG ANSWER
#include<bits/stdc++.h>
using namespace std;

const int sz = 2e5+10;

int arr[sz];

int n, diff, diff1, diff2;

bool ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    ans = true;
    for(int i=0; i<n-1; i++)
    {
        diff = fabs(arr[i]-arr[i+1]);
        if(diff%2==1)
        {
            diff1 = diff2 = 1;
            if(i+2<n)
            {
                diff1 = fabs(arr[i+1]-arr[i+2]);
            }
            else
            {
                diff1 = 0;
            }
            if(i-1>=0)
            {
                diff2 = fabs(arr[i]-arr[i-1]);
            }
            if(diff1%2==0 || diff2%2==0)
            {
                continue;
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if(ans)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << "\n";
    return 0;
}

