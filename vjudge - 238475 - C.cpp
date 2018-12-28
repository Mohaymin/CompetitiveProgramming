#include<bits/stdc++.h>
using namespace std;
#define sz 101010
typedef long long ll;

int arr[sz];
int height;
int T, N, F;
ll totalPairs;
map<ll, ll> frequencyOf;
set<ll> setOfHeights;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--)
    {
        cin >> N >> F;
        for(int i=0; i<N; i++)
        {
            cin >> arr[i];
            setOfHeights.insert(arr[i]);
            frequencyOf[arr[i]]++;
        }
        sort(arr, arr+n);
    }
}
