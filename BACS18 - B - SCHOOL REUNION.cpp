#include<bits/stdc++.h>
using namespace std;

#define sz 101010

pair<int, int> arr[sz];
int t, p, n;
int cnt, prsn;
int arrive, leave, diff;
int ans;
multiset<int> s;
multiset<int>::iterator it;

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int j;
    cin >> t;
    while(t--)
    {
        cin >> n >> p;
        for(int i=0; i<n; i++)
        {
            cin >> arr[i].first;
            cin >> arr[i].second;
        }
        arr[n].first = arr[n].second = diff = ans = INT_MAX;
        sort(arr, arr+n+1, compare);
        for(int i=0; i<=(n-p); i++)
        {
            arrive = arr[i].second;
            for(int j=i+1; j<n; j++)
            {
                s.insert(arr[j].first);
            }
            it = s.begin();
            for(int i=2; i<p; i++)
            {
                it++;
            }
            leave = *it;
            s.clear();
            diff = leave-arrive;
            if(diff <= 0)
            {
                ans = 0;
                break;
            }
            ans = min(ans, diff);
            /*
            sort(arr+i, arr+n);
            leave = arr[i+p-1].first;
            diff = leave-arrive;
            if(diff <= 0)
            {
                ans = 0;
                break;
            }
            ans = min(ans, diff);
            sort(arr+i, arr+n, compare);
            */
        }
        cout << "Case " << ++cnt;
        cout << ": " << ans << "\n";
    }
    return 0;
}
