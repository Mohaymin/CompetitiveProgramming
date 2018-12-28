#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i;
    int j;
    int N;
    int lim;
    int ans1;
    int ans2;

    cin >> N;
    lim = N/2;
    int arr[lim];

    for(i=0; i<lim; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+lim);
    for(i=0, j=1, ans1=0; i<lim; i++)
    {
        ans1 += abs(arr[i]-j);
        j+=2;
    }
    for(i=0, j=2, ans2=0; i<lim; i++)
    {
        ans2 += abs(arr[i]-j);
        j+=2;
    }

    cout << min(ans1, ans2) << endl;

    return 0;
}
