#include<bits/stdc++.h>
using namespace std;

void doLeftRotation(vector<int> v, int k)
{
    int start = k%v.size();
    int i=start;
    do
    {
        cout << v[i] << " ";
        i = (i+1)%v.size();
    } while(i!=start);
}

void doRightRotation(vector<int> v, int k)
{
    int start;// = v.size()-(k%v.size());
    if(k%v.size()==0)
    {
        start = 0;
    }
    else
    {
        start = v.size() - (k%v.size());
    }
    int i=start;
    do
    {
        //cout << v[i] << " ";
        cout << i << " ";
        i = (i+1)%v.size();
    } while(i!=start);
}

int main()
{
    vector<int> v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }
    for(int i=0; i<100; i++)
    {
        //doLeftRotation(v, i);
        cout << "\t";
        doRightRotation(v, i);
        cout << endl;
    }
    return 0;
}
