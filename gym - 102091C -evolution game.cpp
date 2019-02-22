#include<bits/stdc++.h>
using namespace std;

const int nmax = 5010;

int arr[nmax];
int power[nmax];
vector<int> adjlist[nmax];

int getpow(int n)
{
    if(power[n]!=0)
        return power[n];
    int dummy = 0;
    for(int i=0; i<adjlist[n].size(); i++)
    {
        dummy = max(dummy, getpow(adjlist[n][i])+1);
    }
    return power[n] = dummy;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, w;
    cin >> n >> w;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(i+j<n && arr[i]<arr[i+j])
            {
                adjlist[i].push_back(i+j);
            }
            else if(i+j<n && arr[i]>arr[i+j])
            {
                adjlist[i+j].push_back(i);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = max(ans, getpow(i));
    }
    cout << ans << '\n';
    return 0;
}
