#include<bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='y')
        return true;
    return false;
}


int main()
{
    vector<char> v;
    int N;
    char c;
    bool isChanged=true;
    scanf("%d%*c", &N);
    for(int i=0; i<N; i++)
    {
        cin >> c;
        v.push_back(c);
    }
    while(isChanged)
    {
        isChanged = false;
        for(int i=0; i<v.size()-1; i++)
        {
            //cout<<v[i];
            if(isVowel(v[i]) && isVowel(v[i+1]))
            {
                isChanged = true;
                v.erase(v.begin()+i+1);
            }
        }
    }
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i];
    }
    return 0;
}
/*
int main()
{
    int N;
    string str;
    cin >> N;
    //scanf("%*c");
    cin >> str;
    bool changed=true;
    while(changed)
    {
        changed = false;
        for(i=0; i<str.size()-1; i++)
        {
            if()
        }
    }

}
*/
