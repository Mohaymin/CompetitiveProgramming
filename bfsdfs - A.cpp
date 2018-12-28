#include<bits/stdc++.h>
using namespace std;

#define sz 20010

set<int> allInput, s1, s2;
vector<int> adjList[sz];
int a, b;
int test;
set<int>::iterator it;
bool visited[sz];
int n;
int ans;
int cnt;

void dfs(int node, bool inSet1)
{
    //cout << "Node: " << node << endl;
    if(visited[node])
    {
        return;
    }
    visited[node] = true;
    if(inSet1)
    {
        s1.insert(node);
    }
    else
    {
        s2.insert(node);
    }
    int lim = adjList[node].size();
    for(int i=0; i<lim; i++)
    {
        dfs(adjList[node][i], !inSet1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> test;
    while(test--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
            allInput.insert(a);
            allInput.insert(b);
        }
        for(int i=0; i<sz; i++)
        {
            visited[i] = false;
        }
        //memset(visited, false, sizeof(visited)*sz);
        for(it = allInput.begin(); it!=allInput.end(); it++)
        {
            dfs(*it, true);
        }
        ans = max(s1.size(), s2.size());
        cout << "Case " << ++cnt << ": " <<ans << "\n";

        for(it = allInput.begin(); it!=allInput.end(); it++)
        {
            adjList[*it].clear();
        }
        allInput.clear();
        s1.clear();
        s2.clear();
    }
    return 0;
}
