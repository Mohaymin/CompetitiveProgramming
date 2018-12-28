#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int sz = 10;

vector<ll> adjList[sz];
bool visited[sz];
ll amount[sz];
ll ans;
ll p, x, y;

ll getMx(int x, ll val)
{
    if(visited[x])
    {
        return val;
    }
    ll mx = -1;
    int y;
    for(int i=0; i<adjList[x].size(); i++)
    {
        y = adjList[i][x];
        mx = max(mx, getMx(y, amount[y]));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for(int i=0; i<sz; i++)
    {
        adjList[i].push_back(i);
    }
    for(int i=1; i<=8; i++)
    {
        cin >> amount[i];
    }
    ans = 0;
    cin >> p;
    while(p--)
    {
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
}
