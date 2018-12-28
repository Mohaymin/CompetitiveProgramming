#include<bits/stdc++.h>
using namespace std;

const int sz = 100101;

int arr[sz];
pair<int, int> data[sz];

bool ans;

int cnt;
int i, j;
int t, n, ai;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1; i<=n; i++)
        {
            cin >> ai;
            arr[i] = ai;
            data[i] = make_pair(ai, i);
        }

        sort(arr+1, arr+n+1);
        sort(data+1, data+n+1);

        ans = false;
        for(i=1; i<n; i++)
        {
            if(data[i].first==data[i+1].first)
            {
                if(!binary_search(arr+1, arr+n+1, data[i].second))
                {
                    continue;
                }
                for(j=i+1; data[i].first==data[j].first && j<=n; j++)
                {
                    if(binary_search(arr+1, arr+n+1, data[j].second))
                    {
                        ans = true;
                        break;
                    }
                }
                if(ans)
                {
                    break;
                }
                i=j-1;
            }
        }
        if(ans)
        {
            cout << "Truly Happy";
        }
        else
        {
            cout << "Poor Chef";
        }
        cout << "\n";
    }
    return 0;
}
