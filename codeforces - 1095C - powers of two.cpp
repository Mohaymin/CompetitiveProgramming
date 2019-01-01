#include<bits/stdc++.h>
using namespace std;

const int sz = 2e5+3;

int arr[sz];
int cnt, dummy, tmp;

long long sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i=0; i<k; i++)
    {
        arr[i] = 1;
    }
    sum = k;
    for(int i=0; i<k; i++)
    {
        //cout << i << endl;
        while(sum + arr[i] <= n)
        {
            sum += arr[i];
            arr[i] = (arr[i]<<1);
            //cout << sum << '\t' << arr[i] << endl;
        }
    }
    if(sum != n)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        for(int i=0; i<k; i++)
        {
            cout << arr[i] << ' ';
        }
    }
    return 0;
}
