#include<bits/stdc++.h>
using namespace std;
#define sz 1010
#define negInfinity -999999

typedef pair<int, int> mypair;
// mypair->first = node
// mypair->second = weight

vector<mypair> adjList[sz];
int predecessorOf[sz];
vector<int> pseudoHeap;
int keyOf[sz];
bool isExtracted[sz];

int extractMax()
{
    int dummy;
    int mn = negInfinity;
    for(int i=0; i<pseudoHeap.size(); i++)
    {
        if(keyOf[pseudoHeap[i]] > mn)
        {
            mn = keyOf[pseudoHeap[i]];
            dummy = i;
        }
    }
    return dummy;
}

int main()
{
    freopen("_in.txt", "r", stdin);
    int root;
    mypair dummy;
    int extractedNode;
    int node1, node2, weight;
    int noOfNodes, noOfEdges;

    cin >> noOfNodes >> noOfEdges;

    for(int i=0; i<noOfEdges; i++)
    {
        cin >> node1 >> node2 >> weight;
        // all predecessor NIL
        predecessorOf[node1] = predecessorOf[node2] = 0;
        // all key infinite
        keyOf[node1] = keyOf[node2] = negInfinity;
        adjList[node1].push_back(make_pair(node2, weight));
        adjList[node2].push_back(make_pair(node1, weight));
    }
    //cout << "Enter root: ";
    //cin >> root;
    // key of root 0
    // considering root as 1
    root = 1;
    keyOf[root] = 0;
    for(int i=0; i<noOfNodes; i++)
    {
        pseudoHeap.push_back(i+1);
    }
    while(pseudoHeap.size()>0)
    {
        //printf("Heap size: %d\n", pseudoHeap.size());
        int pos = extractMax();
        extractedNode = pseudoHeap[pos];
        pseudoHeap.erase(pseudoHeap.begin()+pos);
        isExtracted[extractedNode] = true;
        // first -> node  second -> weight
        for(int i=0; i<adjList[extractedNode].size(); i++)
        {
            dummy = adjList[extractedNode][i];
            if(isExtracted[dummy.first]==false && dummy.second<keyOf[dummy.first])
            {
                predecessorOf[dummy.first] = extractedNode;
                keyOf[dummy.first] = dummy.second;
            }
        }
    }
    for(int i=1; i<=noOfNodes; i++)
    {
        cout << "Predecessor of " << i << " is " << predecessorOf[i] << endl;
    }
    return 0;
}
