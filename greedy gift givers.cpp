#include<bits/stdc++.h>
using namespace std;

typedef map<string, int> mymap;

mymap givenBy, takenBy;
vector<string> persons;
vector<string>::iterator it;

bool b;
string name, recepient;

int totalPeople, money, noOfRecepient;
int val;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    while(cin >> totalPeople)
    {
        if(b)
            cout << "\n";
        b = true;
        for(int i=0; i<totalPeople; i++)
        {
            cin >> name;
            persons.push_back(name);
        }
        for(int i=0; i<totalPeople; i++)
        {
            cin >> name >> money >> noOfRecepient;

            if(money==0)
                val = 0;
            else if(noOfRecepient!=0)
                val = money - (money%noOfRecepient);
            else
                val = 0;

            givenBy[name] = val;
            if(noOfRecepient!=0)
            {
                val = money/noOfRecepient;
                for(int i=0; i<noOfRecepient; i++)
                {
                    cin >> name;
                    takenBy[name] += val;
                }
            }
        }
        for(it = persons.begin(); it!=persons.end(); it++)
        {
            cout << *it << " ";
            cout << takenBy[*it]-givenBy[*it] << "\n";
        }
        //cout << "\n";
        persons.clear();
        givenBy.clear();
        takenBy.clear();
    }
    return 0;
}
