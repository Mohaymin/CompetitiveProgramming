#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> mypair;

// constant for max size of an array
const int MSIZE = 100100;

int n, m;
int a, b, w;
int parent_of[MSIZE];

mypair adjacent_node;
mypair extracted_node;

stack<int> path;

vector<mypair> adjList[MSIZE];

bool visited[MSIZE];

ll node, dist;
ll distanceOf[MSIZE];

priority_queue<ll, vector<mypair> > pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    // form an adjacency list
    for(int i=0; i<m; i++)
    {
        cin >> a >> b >> w;
        adjList[a].push_back(make_pair(w, b));
        adjList[b].push_back(make_pair(w, a));
    }
    // initialize the distance of the node
    for(int i=2; i<=n; i++)
    {
        distanceOf[i] = numeric_limits<ll>::max();
    }
    // extraction and relaxation
    pq.push(make_pair(0, 1));
    while(pq.empty()!=true)
    {
        extracted_node = pq.top();
        pq.pop();
        for(int i=0; i<adjList[extracted_node.second].size(); i++)
        {
            adjacent_node = adjList[extracted_node.second][i];
            node = adjacent_node.second;
            dist = adjacent_node.first;
            if(distanceOf[node] > distanceOf[extracted_node.second]+dist)
            {
                distanceOf[node] = distanceOf[extracted_node.second]+dist;
                parent_of[node] = extracted_node.second;
                pq.push(make_pair(-distanceOf[node], node));
            }
        }
    }
    // output
    if(parent_of[n]==0)
    {
        cout << -1;
    }
    else
    {
        node = n;
        while(parent_of[node]!=node)
        {
            path.push(node);
            node = parent_of[node];
        }
        while(path.size()>1)
        {
            cout << path.top() << " ";
            path.pop();
        }
        cout << path.top();
        path.pop();
    }
    cout << "\n";
    return 0;
}
