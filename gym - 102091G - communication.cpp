#include<bits/stdc++.h>
using namespace std;

const int nmax = 210;

bool visited[nmax];
vector<int> adjlist[nmax];
vector<int> revAdjList[nmax];

stack<int> visitedNodes;

void doDFS(int node, vector<int> adjlist[])
{
    if(visited[node])
    {
        return;
    }
    visited[node] = true;
    for(int i=0; i<adjlist[node].size(); i++)
    {
        doDFS(adjlist[node][i], adjlist);
    }
    visitedNodes.push(node);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t, n, e;
    int a, b;
    int tmp;
    int ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> e;
        for(int i=0; i<e; i++)
        {
            cin >> a >> b;
            adjlist[a].push_back(b);
            revAdjList[b].push_back(a);
        }
        memset(visited, false, sizeof(visited));
        for(int i=0; i<n; i++)
        {
            doDFS(i, adjlist);
        }
        memset(visited, false, sizeof(visited));
        ans = 0;
        while(visitedNodes.empty()!=true)
        {
            tmp = visitedNodes.top();
            visitedNodes.pop();
            if(!visited[tmp])
            {
                ans++;
                doDFS(tmp, revAdjList);
            }
        }
        cout << ans << '\n';
        // clear adjacency list for reuse
        for(int i=0; i<n; i++)
        {
            adjlist[i].clear();
            revAdjList[i].clear();
        }
    }
    return 0;
}
