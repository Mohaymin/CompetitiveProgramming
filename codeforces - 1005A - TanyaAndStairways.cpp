#include<bits/stdc++.h>
using namespace std;
#define sz 1010
#define inf 999999

queue<int> stepsInStairways;
int N;
int arr[sz];
int totalStairways;

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    for(int i=0; i<N; i++)
    {
        if(arr[i] >= arr[i+1])
        {
            totalStairways++;
            stepsInStairways.push(arr[i]);
        }
    }

    cout << totalStairways << endl;
    while(stepsInStairways.size()>1)
    {
        cout << stepsInStairways.front() << " ";
        stepsInStairways.pop();
    }
    cout << stepsInStairways.front() << endl;
    return 0;
}
