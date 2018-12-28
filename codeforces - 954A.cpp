#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> st;
    char ch;
    int N;
    cin >> N;
    //cin >> ch;
    //st.push(ch);
    /*
    while(--N)
    {
        cin >> ch;
        if(ch!=st.top())
        {
            st.pop();
        }
        st.push(ch);
    }
    */
    string str;
    cin >> str;
    int cnt=0;
    for(int i=0; i<str.size()-1; i++)
    {
        if(str[i]!=str[i+1])
        {
            cnt++;
            i++;
        }
    }
    //cout << st.size() << endl;
    cout << N-cnt << endl;
    return 0;
}
