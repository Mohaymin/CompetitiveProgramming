/// JACOBI ITERATION METHOD
#include<bits/stdc++.h>
using namespace std;
#define ITERATION_TIMES 100

typedef double dd;


int main()
{
    //freopen("_in.txt", "r", stdin);
    int N;
    cout << "ENTER NUMBER OF EQUATIONS = ";
    cin >> N;

    dd matrix[N][N+1];
    dd root[N];

    cout << "ENTER COEFFICENTS OF EQUATIONS = ";
    puts("");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    ////////////////////JACOBI-ITERATION METHOD
    dd oldRoot[N] = {0};
    dd sum;
    for(int k=0; k<ITERATION_TIMES; k++)
    {
        for(int i=0; i<N; i++)
        {
            sum = matrix[i][N]/matrix[i][i];
            //printf("Initial Sum: %lf\n", sum);
            for(int j=0; j<N; j++)
            {
                if(i!=j)
                {
                    //printf("x%d = %lf  coeff = %lf  denominator = %lf \n", j, oldRoot[j], matrix[i][j], matrix[i][i]);
                    sum = sum - matrix[i][j]*oldRoot[j]/matrix[i][i];
                }
            }
            root[i] = sum;
            //cout << "ROOT-" << i << ": " << root[i] << endl;
            //oldRoot[i] = root[i];
        }
        for(int i=0; i<N; i++)
        {
            oldRoot[i] = root[i];
        }
        //cout << endl;
    }
    int len = printf("SOLUTION OF THE GIVEN SYSTEM:");
    for(int i=0; i<N; i++)
    {
        cout << "x" << i+1 << " ";
        cout << root[i] << endl;
        for(int j=0; j<len; j++)
            cout << " ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ITERATION_TIMES 100

typedef double dd;


int main()
{
    //freopen("_in.txt", "r", stdin);
    int N;
    cout << "ENTER NUMBER OF EQUATIONS = ";
    cin >> N;

    dd matrix[N][N+1];
    dd root[N];

    cout << "ENTER COEFFICENTS OF EQUATIONS = ";
    puts("");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    ////////////////////JACOBI-ITERATION METHOD
    dd oldRoot[N] = {0};
    dd sum;
    for(int k=0; k<ITERATION_TIMES; k++)
    {
        for(int i=0; i<N; i++)
        {
            sum = matrix[i][N]/matrix[i][i];
            //printf("Initial Sum: %lf\n", sum);
            for(int j=0; j<N; j++)
            {
                if(i!=j)
                {
                    //printf("x%d = %lf  coeff = %lf  denominator = %lf \n", j, oldRoot[j], matrix[i][j], matrix[i][i]);
                    sum = sum - matrix[i][j]*oldRoot[j]/matrix[i][i];
                }
            }
            root[i] = sum;
            //cout << "ROOT-" << i << ": " << root[i] << endl;
            //oldRoot[i] = root[i];
        }
        for(int i=0; i<N; i++)
        {
            oldRoot[i] = root[i];
        }
        //cout << endl;
    }
    int len = printf("SOLUTION OF THE GIVEN SYSTEM:");
    for(int i=0; i<N; i++)
    {
        cout << "x" << i+1 << " ";
        cout << root[i] << endl;
        for(int j=0; j<len; j++)
            cout << " ";
    }
    return 0;
}
