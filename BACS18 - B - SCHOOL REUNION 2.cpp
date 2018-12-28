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
    int j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &p);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &arr[i].first, &arr[i].second);
//            cin >> arr[i].first;
//            cin >> arr[i].second;
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
        }
        printf("Case %d: %d\n", ++cnt, ans);
//        cout << "Case " << ++cnt;
//        cout << ": " << ans << "\n";
    }
    return 0;
}
