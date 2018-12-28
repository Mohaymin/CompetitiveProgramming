#include<bits/stdc++.h>
using namespace std;

const int sz = 1000010;

int arr[sz];
int t, n, ans, mxno, i, dum;

void pseudosieve()
{
    int lim = sz/2;
    for(int i=2; i<=lim; i++)
    {
        for(int j=i; j<sz; j+=i)
        {
            arr[j]++;
        }
    }
    int freq = -1;
    for(int i=1; i<sz; i++)
    {
        if(arr[i] >= freq)
        {
            freq = arr[i];
            arr[i] = i;
        }
        else
        {
            arr[i] = arr[i-1];
        }
    }
}

int main()
{
    //freopen("_in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    pseudosieve();
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << arr[n] << "\n";
    }
    return 0;
}
