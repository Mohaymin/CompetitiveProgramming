#include<bits/stdc++.h>
using namespace std;

string votes;
int yes, no, present, absent;
int totalVotes;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> votes)
    {
        if(votes=="#")
            return 0;
        yes = no = present = absent = 0;
        totalVotes = votes.size();
        for(int i=0; i<totalVotes; i++)
        {
            switch(votes[i])
            {
            case 'Y':
                yes++;
                break;
            case 'N':
                no++;
                break;
            case 'P':
                present++;
                break;
            case 'A':
                absent++;
                break;
            }
        } // counting done
        if(absent >= (yes+no+absent+present+1)/2)
        {
            cout << "need quorum\n";
        }
        else
        {
            if(yes == no)
            {
                cout << "tie";
            }
            else if(yes > no)
            {
                cout << "yes";
            }
            else
            {
                cout << "no";
            }
            cout << "\n";
        }
    }
}
