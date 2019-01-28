#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int> adjlist[N];
bool visited[N];
int dist[N];

bool dfs(int node)
{
    //cout << node << endl;
    if(visited[node])
        return false;
    visited[node] = true;
    dist[node] = 1;
    for(int i=0; i<adjlist[node].size(); i++)
    {
        if(dfs(adjlist[node][i]))
        {
            dist[node] += dist[adjlist[node][i]];
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, u, v;
    cin >> n;
    if(n%2==1)
    {
        cout << -1 << '\n';
        return 0;
    }
    for(int i=1; i<n; i++)
    {
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    dfs(1);
    int ans = -1;
    for(int i=1; i<=n; i++)
    {
        //cout << dist[i] << ' ';
        if(dist[i]%2==0)
        {
            ans++;
        }
    }
    //cout << endl;
    cout << ans << '\n';
    return 0;
}
