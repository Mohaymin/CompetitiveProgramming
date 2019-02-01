#include<bits/stdc++.h>
using namespace std;

int gettime(int tottime, int ti, int si)
{
    return tottime + (tottime-1)/ti*si;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    int a, ti, si;
    int tottime;
    int mintime;
    cin >> n >> k >> a;
    tottime = k/a;
    cin >> ti >> si;
    mintime = gettime(tottime, ti, si);
    for(int i=1; i<n; i++)
    {
        cin >> ti >> si;
        mintime = min(mintime, gettime(tottime, ti, si));
    }
    cout << mintime << '\n';
    return 0;
}
