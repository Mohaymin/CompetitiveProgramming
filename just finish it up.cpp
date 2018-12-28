#include<bits/stdc++.h>
using namespace std;
#define sz 101010

int weight[sz];
int costForNext[sz];
pair<int, int> input[sz];

int t, c, n;
int sumOfEdges;
int startPos;
int mx;
bool shouldUpdate;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        mx = -INT_MAX;
        sumOfEdges = 0;
        shouldUpdate = true;
        for(int i=0; i<n; i++)
        {
            cin >> input[i].first;
            costForNext[i] = INT_MAX;
        }
        for(int i=0; i<n; i++)
        {
            cin >> input[i].second;
            weight[i] = input[i].first-input[i].second;
            sumOfEdges+=weight[i];
        }
        costForNext[0] = 0;

        cout << "Case " << ++c << ": ";

        if(sumOfEdges<0)
        {
            cout << "Not possible\n";
            continue;
        }

        for(int i=1; i<=n; i++)
        {
            costForNext[i%n] = min(costForNext[i%n], costForNext[i-1]+weight[i-1]);
//            if(costForNext[i%n] > mx)
//            {
//                mx = costForNext[i%n];
//                startPos = i%n;
//            }
        }
        for(int i=0; i<n; i++)
        {
            if(shouldUpdate && costForNext[i] >= 0)
            {
                startPos = i;
                shouldUpdate = false;
            }
            if(!shouldUpdate && costForNext[i] < 0)
            {
                startPos = -10;
                shouldUpdate = true;
            }
        }

        if(startPos<=0)
            startPos = n;

        cout << "Possible from station " << startPos << "\n";
    }
    return 0;
}
