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
        ///the node has already been visited
        return;
    }

    visited[node] = true;///the node is now colored grey
    for(int i=0; i<adjNodesOf[node].size(); i++)
    {
        doDFS(adjNodesOf, visited, adjNodesOf[node][i]);
        ///visit all the adjacent nodes
    }
    visitedNodes.push(node);
    ///the node is now colored black
}


int main()
{
    freopen("_in.txt", "r", stdin);
    int cnt=0;
    int topNode;
    int node1, node2;
    int noOfNodes, noOfEdges;

    /// read total number of nodes and edges
    cin >> noOfNodes >> noOfEdges;

    bool visited[noOfNodes];
    vector<int> adjList[noOfNodes];
    vector<int> revAdjList[noOfNodes];

    /// read the connected nodes and
    /// prepare adjacent list
    for(int i=0; i<noOfEdges; i++)
    {
        cin >> node1 >> node2;
        adjList[node1].push_back(node2);
        revAdjList[node2].push_back(node1);
    }
    /// adjacent list for both given graph
    /// and its reversed graph has been prepared

    /// now it's time to perform DFS on the given graph
    // mark all nodes as non-visited
    memset(visited, false, sizeof(visited));
    for(int i=0; i<noOfNodes; i++)
    {
        doDFS(adjList, visited, i);
        // cases with visited nodes will be
        // handled within the function
    }
    /// all the nodes has been visited and
    /// nodes with highest ending time have
    /// been stored at top of the stack 'visitedNodes'

    /// now we display the connected components
    memset(visited, false, sizeof(visited));
    // mark all nodes as non-visited again
    while(visitedNodes.empty()!=true)
    {
        topNode = visitedNodes.top();
        //
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
