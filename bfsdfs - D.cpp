#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const long sz = 30010;

ll mxdist;
int test;
int n;
ll u, v, w, s;
int cnt;
queue<ll> q;
bool visited[sz];
ll distOf[sz];
vector< pair<ll, ll> > adjList[sz];

void init(int n)
{
    mxdist = -1;
    for(int i=0; i<n; i++)
    {
        distOf[i] = 0;
        visited[i] = false;
        adjList[i].clear();
    }
}

void mxDistFrom(ll source)
{
    int u, v, w;
    q.push(source);
    while(q.empty()!=true)
    {
        u = q.front();
        q.pop();
        for(int i=0; i<adjList[u].size(); i++)
        {
            v = adjList[u][i].first;
            w = adjList[u][i].second;
            if(visited[v])
            {
                continue;
            }
            q.push(v);
            distOf[v] = distOf[u] + w;
            mxdist = max(distOf[v], mxdist);
        }
        visited[u] = true;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

//    freopen("_in.txt", "r", stdin);
    cin >> test;
    while(test--)
    {
        init(n);
        cin >> n;
        for(int i=1; i<n; i++)
        {
            cin >> u >> v >> w;
            adjList[u].push_back(make_pair(v, w));
            adjList[v].push_back(make_pair(u, w));
        }
        s = 0;
        mxDistFrom(s);
        for(int i=0; i<n; i++)
        {

//            init(n);
//            mxDistFrom(i);
        }
        cout << "Case " << ++cnt << ": " << mxdist << "\n";
    }
    return 0;
}
