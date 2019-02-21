#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ipair;

const int mxn = 22;

int n;

int matrix[mxn][mxn];

map< int, int > freq;
priority_queue<ipair> pq;

int rev(int i)
{
    return n-i-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int ai;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> ai;
            freq[ai]++;
        }
    }
    for(ipair keyandvalue: freq)
    {
        pq.push({keyandvalue.second, keyandvalue.first});
    }
    ipair dummy;
    int lim = n>>1;
    bool hasans = true;
    for(int i=0; i<lim; i++)
    {
        for(int j=0; j<lim; j++)
        {
            dummy = pq.top();
            pq.pop();
            if(dummy.first<4)
            {
                hasans = false;
                break;
            }
            matrix[i][j]
             = matrix[i][rev(j)]
             = matrix[rev(i)][j]
             = matrix[rev(i)][rev(j)]
             = dummy.second;
            if(dummy.first>4)
            {
                pq.push({dummy.first-4, dummy.second});
            }
        }
    }
    if(n&1) // jhamela
    {
        int i, j;
        i = lim;
        for(int j=0; j<lim; j++)
        {
            dummy = pq.top();
            pq.pop();
            if(dummy.first<2)
            {
                hasans = false;
                break;
            }
            matrix[i][j] = matrix[i][rev(j)] = dummy.second;
            if(dummy.first>2)
            {
                pq.push({dummy.first-2, dummy.second});
            }
        }
        for(int j=0; j<lim; j++)
        {
            dummy = pq.top();
            pq.pop();
            if(dummy.first<2)
            {
                hasans = false;
                break;
            }
            matrix[j][i] = matrix[rev(j)][i] = dummy.second;
            if(dummy.first>2)
            {
                pq.push({dummy.first-2, dummy.second});
            }
        }
        matrix[i][i] = pq.top().second;
    }
    if(!hasans)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
