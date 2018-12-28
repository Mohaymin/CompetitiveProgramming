#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> mypair;

ll n, m;
mypair songs[101010];
ll totSize;
ll totDiff;
mypair dummy;
ll a, b;
ll ans;

bool comp(mypair a, mypair b)
{
    return fabs(a.first-a.second) > fabs(b.first-b.second);
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(ll i=0; i<n; i++)
    {
        cin >> a >> b;
        songs[i] = make_pair(a, b);
        totSize += a;
        totDiff += b;
    }
    if(totDiff>m)
    {
        cout << -1 << "\n";
        return 0;
    }
    sort(songs, songs+n, comp);
    for(ll i=0; i<n; i++)
    {
        if(totSize <= m)
            break;
        totSize -= (songs[i].first-songs[i].second);
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
