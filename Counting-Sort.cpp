#include<bits/stdc++.h>
using namespace std;


int totalNumberOfElements;
int maximumValue;


void printArray(int arr[], int arrLen)
{
    for(int i=0; i<arrLen; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void calculateFrequencyOf(int element[], int frequencyOf[])
{
    //initialize frequency of all elements as 0
    memset(frequencyOf, 0, (maximumValue+1)*sizeof(frequencyOf[0]));
    //calculate the frequency
    for(int i=0; i<totalNumberOfElements; i++)
    {
        frequencyOf[element[i]]++;
    }
}


void countSort(int inputArray[], int frequencyOf[], int sortedArray[])
{
    calculateFrequencyOf(inputArray, frequencyOf);
    int i=0;
    int totalOccurance;

    for(int element=0; element<=maximumValue; element++)
    {
        totalOccurance = frequencyOf[element];
        while(totalOccurance > 0)
        {
            sortedArray[i++] = element;
            totalOccurance--;
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    cout << "Enter total number of elements: ";
    cin >> totalNumberOfElements;
    cout << "Enter maximum value of the input: ";
    cin >> maximumValue;

    int inputArray[totalNumberOfElements];
    int frequencyArray[maximumValue+1];
    int sortedArray[totalNumberOfElements];

    cout << "Enter data: ";
    for(int i=0; i<totalNumberOfElements; i++)
    {
        cin >> inputArray[i];
    }

    countSort(inputArray, frequencyArray, sortedArray);

    puts("The sorted array:- ");
    printArray(sortedArray, totalNumberOfElements);

    return 0;
}
