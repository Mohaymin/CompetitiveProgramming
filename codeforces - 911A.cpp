#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    int arr[n];
    int distance;
    int mn;
    distance = mn = numeric_limits<int>::max();
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]==mn) v.push_back(i);
    }
    for(int i=0; i<v.size()-1; i++)
    {
        distance = min(distance, v[i+1]-v[i]);
    }
    cout<<distance<<endl;
    return 0;
}
