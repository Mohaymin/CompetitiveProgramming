#include<bits/stdc++.h>
using namespace std;
#define sz 1010

int arr[sz];
int n;
int in;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> in;
        if((in&1) == 0)
        {
            in--;
        }
        arr[i] = in;
    }
    for(int i=0; i<n-1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << arr[n-1];
    return 0;
}
