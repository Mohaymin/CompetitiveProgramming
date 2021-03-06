#include<bits/stdc++.h>
using namespace std;

const int sz = 100010;
int arr[sz];
int test;
int k, n;
int val;
int ans;

int binarySearch(int lo, int hi)
{
    if(lo > hi)
    {
        return 0;
    }
    else
    {
        int mid = (lo+hi)/2;
        if(arr[mid] == val)
        {
            return mid; // since we need to add mid-k to the answer
        }
        else if(arr[mid] < val)
        {
            return binarySearch(lo, mid-1);
        }
        else
        {
            return binarySearch(mid+1, hi);
        }
    }
}

int main()
{
    arr[0] = INT_MAX;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &arr[i]);
        }

        sort(arr+1, arr+n+1, greater<int>());

        ans = k;
        val = arr[k];

        int tmp = 1;
        int lo = k+1;
        int hi = n;

        do
        {
            tmp = binarySearch(lo, hi);
            if(tmp == 0)
            {
                break;
            }
            ans = tmp;
            lo = lo + tmp + 1;
        } while(true);
        printf("%d\n", ans);
    }
    return 0;
}
