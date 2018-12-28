#include<bits/stdc++.h>
using namespace std;
int N;
int graph[100][100];
int minKey(int key[], bool List[])
{

   int minn = INT_MAX, ind_num;
   int maxx = INT_MIN;

   for (int v = 0; v < N; v++)
     if (List[v] == false && key[v] > maxx)
         minn = key[v], ind_num = v;

   return ind_num;
}

int printMST(int parent[], int n, int graph[100][100])
{

   for (int i = 1; i < N; i++)
      cout<<parent[i]<<" "<<i<<" "<<graph[i][parent[i]]<<endl;
}

void prim(int graph[100][100])
{
     int parent[N];
     int key[N];
     bool List[N];

     for (int i = 0; i < N; i++)
        key[i] = INT_MAX, List[i] = false;


     key[0] = 0;
     parent[0] = -1;

     for (int count = 0; count < N-1; count++)
     {

        int u = minKey(key, List);

        List[u] = true;

        for (int v = 0; v < N; v++){

          if (graph[u][v] && List[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
        }
     }
     printMST(parent, N, graph);
}
int main()
{
   int e;
   cin>>N>>e;

   for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=c;
        graph[b][a]=c;
   }
    prim(graph);
}
