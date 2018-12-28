#include<bits/stdc++.h>
using namespace std;
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int sz = 1000010;

bool ans;

int i, j;

int pivot;
int t, n, bar;

int arr[sz];
int dummArr[sz];

void printDummyArray()
{
    for(int i=0; i<n; i++)
    {
        cout << dummArr[i] << " ";
    }
    cout << endl;
}

int main()
{
    FASTER;

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        pivot = bar = 0;
        for(i=0; i<n-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                bar++;
                pivot = i+1;
            }
        }
        if(bar > 1)
        {
            ans = false;
        }
        else
        {
            for(i=pivot; i<n; i++)
            {
                dummArr[i-pivot] = arr[i];
                //cout << i-pivot << " " << i << endl;
            }
            //cout << "_____________________________" << endl;
            for(i=0, j=n-pivot; i<pivot; i++, j++)
            {
                dummArr[j] = arr[i];
                //cout << j << " " << i << endl;
            }

            //printDummyArray();

            ans = true;
            for(i=0; i<n-1; i++)
            {
                if(dummArr[i] > dummArr[i+1])
                {
                    ans = false;
                    break;
                }
            }
        }
        if(ans)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}
