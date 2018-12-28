#include<bits/stdc++.h>
using namespace std;
stack<int> visitedNodes;

void printConnectedComponents(vector<int> adjacentNodesOf[], bool visited[], int node)
{
    if(visited[node])
    {
        return;
    }
    visited[node] = true;
    for(int i=0; i<adjacentNodesOf[node].size(); i++)
    {
        printConnectedComponents(adjacentNodesOf, visited, adjacentNodesOf[node][i]);
    }
    cout << " " << node;
}

void doDFS(vector<int> adjNodesOf[], bool visited[], int node)
{
    if(visited[node])
    {
        return;
    }
    visited[node] = true;
    for(int i=0; i<adjNodesOf[node].size(); i++)
    {
        doDFS(adjNodesOf, visited, adjNodesOf[node][i]);
    }
    visitedNodes.push(node);
}

int main()
{
    int cnt=0;
    int topNode;
    int node1, node2;
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    bool visited[noOfNodes];
    vector<int> adjList[noOfNodes];
    vector<int> revAdjList[noOfNodes];
    for(int i=0; i<noOfEdges; i++)
    {
        cin >> node1 >> node2;
        adjList[node1].push_back(node2);
        revAdjList[node2].push_back(node1);
    }
    memset(visited, false, sizeof(visited));
    for(int i=0; i<noOfNodes; i++)
    {
        doDFS(adjList, visited, i);
    }
    memset(visited, false, sizeof(visited));
    while(visitedNodes.empty()!=true)
    {
        topNode = visitedNodes.top();
        if(visited[topNode] == false)
        {
            printf("Component %d:", ++cnt);
            printConnectedComponents(revAdjList, visited, topNode);
            cout << endl;
        }
        visitedNodes.pop();
    }
    return 0;
}
