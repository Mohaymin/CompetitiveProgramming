#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> mypair;

vector<mypair> v;
stack<mypair> s;
set<mypair> st;

mypair dummy;

int dist[4];
int a, b;

bool isEligible()
{
    if(s.top()!=dummy)
    {
        if(binary_search(st.begin(), st.end(), dummy))
        {
            return true;
        }
    }
    st.insert(dummy);
    return false;
}

void increasingX(mypair from, mypair to)
{
    for(int i=from.first; i<=to.first; i++)
    {
        dummy = make_pair(i, from.second);
        if(isEligible())
        {
            s.push(dummy);
        }
    }
}

void decreasingX(mypair from, mypair to)
{
    for(int i=from.first; i>=to.first; i--)
    {
        dummy = make_pair(i, from.second);
        if(isEligible())
        {
            s.push(dummy);
        }
    }
}

void increasingY(mypair from, mypair to)
{
    for(int i=from.second+1; i<=to.second; i++)
    {
        dummy = make_pair(from.first, i);
        if(isEligible())
        {
            s.push(dummy);
        }
    }
}

void decreasingY(mypair from, mypair to)
{
    for(int i=from.second-1; i>=to.second; i--)
    {
        dummy = make_pair(from.first, i);
        if(isEligible())
        {
            s.push(dummy);
        }
    }
}

void gofrom(mypair from, mypair to)
{

    if(from.first < to.first)
    {
        increasingX(from, to);
    }
    else
    {
        decreasingX(from, to);
    }
    from.first = to.first;
    if(from.second < to.second)
    {
        increasingY(from, to);
    }
    else
    {
        decreasingY(from, to);
    }
}

int main()
{
    //freopen("_in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int x, y;
    for(int i=0; i<3; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    int i=0;
    s.push(make_pair(-1, -1));
    st.insert(make_pair(-1, -1));
    do
    {
        a = fabs(v[i].first-v[(i+1)%3].first);
        b = fabs(v[i].second-v[(i+1)%3].second);
        dist[i] = a+b;
        i = (i+1)%3;
    } while(i!=0);
    dist[3] = dist[0];
    int k = numeric_limits<int>::max();
    int minindex;
    for(int i=0; i<3; i++)
    {
        if(dist[i]+dist[(i+1)%3] < k)
        {
            minindex = i;
            k = dist[i];
        }
    }
    int startindex = minindex;
    int endindex = (minindex+3)%3;
    do
    {
        gofrom(v[startindex], v[(startindex+1)%3]);
        startindex = (startindex+1)%3;
    } while(startindex!=endindex);
    k = s.size()-1;
    cout << k << "\n";
    while(s.size()>1)
    {
        cout << s.top().first << " " << s.top().second << "\n";
        s.pop();
    }
    return 0;
}
