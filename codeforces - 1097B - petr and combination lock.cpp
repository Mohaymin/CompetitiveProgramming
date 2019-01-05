#include<bits/stdc++.h>
using namespace std;

const int sz = 20;

int arr[20];
vector<int> v1, v2;

int n;
int sumfront, sumback;

bool getans(int val, int i)
{
    //val = (val+360)%360;
    if(i==n-1)
    {
        return ((val+360)%360==0);
    }
    if(getans(val+arr[i+1], i+1))
    {
        return true;
    }
    return getans(val-arr[i+1], i+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    bool ans = getans(0, -1);

    if(ans)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
