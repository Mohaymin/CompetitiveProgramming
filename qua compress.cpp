#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char inLocation[100];
char outLocation[100];

//considering each character in the main file as a Node
struct Node
{
    char a;
    int frequency;
    int left;
    int right;
    int isNode;
};
//considering each character in the compressed file as a NodeDecompress
struct NodeDecompress
{
    char a;
    int frequency;
    int left;
    int right;
    int isNode;
};
int TRACE=0;
typedef struct Node node;
typedef struct Node NodeDec;
static int iDec = 0;
struct Encoding
{
    char encoding[36];
};
typedef struct Encoding encoding;
encoding e[255];
char finalCode[10000000];
char decompression[1000000];
int bitind=0;
int alphabets = 0;
node nodes[100000];
NodeDec nodeDec[100000];
int noOfElements = 0;
char code[10000];
int trace = 0;
int length;
int uniqueChars = 0;
unsigned char uniqueCharsC;
FILE *fp3;
int lengthOfFinalcode = 0;



void LeastFrequency()
{
    int i,least =0,index;
    static int elements =0;
    for(i=0; i<noOfElements; i++)
    {
        if(nodes[i].isNode == 0)
        {
            break;
        }
    }
    least = nodes[i].frequency;
    index = i;

    for(i=0; i<noOfElements; i++)
    {
        if(nodes[i].isNode == 0)
        {
            if(nodes[i].frequency<least)
            {
                least = nodes[i].frequency;
                index = i;
            }
        }
    }
    elements++;
    nodes[noOfElements].left = index;
    nodes[noOfElements].frequency = nodes[index].frequency;
    nodes[index].isNode = 1;
    if(elements == noOfElements)
        return;

    for(i=0; i<noOfElements; i++)
    {
        if(nodes[i].isNode == 0)
        {
            break;
        }
    }
    least = nodes[i].frequency;
    index = i;

    for(i=0; i<noOfElements; i++)
    {
        if(nodes[i].isNode == 0)
        {
            if(nodes[i].frequency<least)
            {
                least = nodes[i].frequency;
                index = i;
            }
        }
    }
    elements++;
    nodes[noOfElements].right = index;
    nodes[noOfElements].frequency+= nodes[index].frequency;
    nodes[index].isNode = 1;
    noOfElements++;
    if(elements == noOfElements)
        return;
}

void LeastFrequencyDec()
{
    int i,least =0,index;
    static int elements =0;
    for(i=0; i<noOfElements; i++)
    {
        if(nodeDec[i].isNode == 0)
        {
            break;
        }
    }
    least = nodeDec[i].frequency;
    index = i;

    for(i=0; i<noOfElements; i++)
    {
        if(nodeDec[i].isNode == 0)
        {
            if(nodeDec[i].frequency<least)
            {
                least = nodeDec[i].frequency;
                index = i;
            }
        }
    }
    elements++;
    nodeDec[noOfElements].left = index;
    nodeDec[noOfElements].frequency = nodeDec[index].frequency;
    nodeDec[index].isNode = 1;
    if(elements == noOfElements)
        return;

    for(i=0; i<noOfElements; i++)
    {
        if(nodeDec[i].isNode == 0)
        {
            break;
        }
    }
    least = nodeDec[i].frequency;
    index = i;

    for(i=0; i<noOfElements; i++)
    {
        if(nodeDec[i].isNode == 0)
        {
            if(nodeDec[i].frequency<least)
            {
                least = nodeDec[i].frequency;
                index = i;
            }
        }
    }
    elements++;
    nodeDec[noOfElements].right = index;
    nodeDec[noOfElements].frequency+= nodeDec[index].frequency;
    nodeDec[index].isNode = 1;
    noOfElements++;
    if(elements == noOfElements)
        return;
}
void generateCodes(int index,int n)
{
    int i;
    if(nodes[index].left!= -1)
    {
        code[n] ='1';
        generateCodes(nodes[index].left,n+1);
    }
    if(nodes[index].right!= -1)
    {
        code[n] = '0';
        generateCodes(nodes[index].right,n+1);
    }


    if(!(nodes[index].left!= -1) && !(nodes[index].right!= -1))
    {

        printf("%c: ",nodes[index].a);

        for(i=0; i<n; i++)
        {
            e[nodes[index].a].encoding[i]=code[i];
            printf("%c",code[i]);
        }
        printf("\n");

    }
}
void finalDecompression(int index, int n)
{
    //printf("\nIndex is %d and N is %d\n",index,n);
    char decomp;
    decomp = decompression[n];//decomp='0'
    //printf("\n INDEX IS %d AND N IS %d AND TRACE IS %d\n",index,n,TRACE);
    if(nodeDec[index].left== -1 && nodeDec[index].right==-1 && alphabets>0)
    {
        alphabets--;
        printf("%c",nodeDec[index].a);
        fprintf(fp3,"%c",nodeDec[index].a);
        index = noOfElements-1;
        finalDecompression(index,n);

    }
    if(nodeDec[index].left!= -1 && nodeDec[index].right!=-1)
    {
        if(decomp == '1' )
        {
            index = nodeDec[index].left;
            finalDecompression(index,n+1);
        }
        if(decomp == '0')
        {
            index = nodeDec[index].right;
            finalDecompression(index,n+1);
        }
    }
    if(alphabets == 0)
        return;

}

//MISSISSIPPI

void reWrite()
{
    finalCode[0]=NULL;
    FILE *fp1;
    FILE *fp2;
    char c;
    int index;

    int i,j;

    int end;
    fp1=fopen(inLocation,"r");
    if(fp1 == NULL)
    {
        printf("\nERROR");
        return;
    }
    else
    {
        while((c=fgetc(fp1))!=EOF)
        {
            index = c;
            strcat(finalCode,e[index].encoding);
        }
        /*26-32
        for(24;26;++)

        */
    }

    lengthOfFinalcode = strlen(finalCode);
    length = lengthOfFinalcode;
    printf("Inside rewrite %s\n",finalCode);

    fp2= fopen(outLocation,"wb");

    char number=0;
    char temp=0;
    char temp2=0;
    int total;
    int d=0;
    trace = length%8; //trace==5
    end = length-trace+8;//end 3
    //end 24
    //26 26%8=2 32-2=6//ektta ques

    fprintf(fp2,"%d",lengthOfFinalcode);
    uniqueCharsC = uniqueChars;
    fprintf(fp2, "%c", uniqueCharsC);
    for(i=0; i<uniqueChars; i++)
    {
        //fwrite(&nodes[i].a,sizeof(char),1,fp2);
        fprintf(fp2,"%c",nodes[i].a);
        d=nodes[i].frequency;
        //fwrite(&d,sizeof(int),1,fp2);
        fprintf(fp2,"%d",d);
    }

    for(i=0; i<length-trace; i++)
    {
        temp=number<<1;//00000000
        if(finalCode[i]=='0')
            number=temp;
        if(finalCode[i]=='1')
            number=temp|1;
        if(i%8==7)
        {
            fprintf(fp2,"%c",number);
            //fputc(number,fp2);
            number=number&0;
        }
    }
    int finalposition=i;

    if(trace>0)
    {

        char fin=0;

        int start;

        int zerotoend;
        int finaldest=length-trace+8;
        for(zerotoend=finalposition+trace; zerotoend<end; zerotoend++) //Adding 0 to last index
        {

            finalCode[zerotoend]='0';
        }

        for(; finalposition<end; finalposition++) //Last char,first known bits
        {
            temp2=fin<<1;
            //printf("bit %d = %c",finalposition,finalCode[finalposition]);
            if(finalCode[finalposition]=='0')
                fin=temp2;
            if(finalCode[finalposition]=='1')
                fin=temp2|1;
        }

        fprintf(fp2,"%c",fin);
        //fputc(fin,fp2);
        fin=fin&0;
        fclose(fp1);
        fclose(fp2);
    }
}


void showBits(char v)
{

    int i;
    int bit;
    char code[2];
    code[1] = NULL;
    static int position = 0;
    for (i=7; i >= 0; i--)
    {
        bit = (v >> i) & 1;
        printf("%d",bit);
        if(bit == 0)
        {
            decompression[position]='0';
            position++;
        }
        if(bit==1)
        {
            decompression[position]='1';
            position++;
        }
    }

}

void decompressionFunction()
{
    FILE *fp2;
    noOfElements = 0;
    int tracee[100];
    int data;
    int p=0;
    int i=0;
    int x;
    int d;
    int test;
    printf("Enter the path of compressed file: ");
    gets(inLocation);
    printf("Enter the path for decompressed file: ");
    gets(outLocation);
    fp2 = fopen(inLocation,"rb");
    if(fp2==NULL)
        printf("ERROR");
    else
    {
        fscanf(fp2,"%d",&lengthOfFinalcode);
        length = lengthOfFinalcode;
        printf("\nTHE LENGTH IS:%d\n",lengthOfFinalcode);
        fscanf(fp2,"%c",&uniqueCharsC);
        uniqueChars = uniqueCharsC;
        //noOfElements=noOfElements-'0';
        printf("\nTHE NUMBER OF UNIQUE IS:%d\n",uniqueChars);

        for(i=0; i<uniqueChars; i++)
        {
            fscanf(fp2,"%c",&nodeDec[i].a);
            fscanf(fp2,"%d",&d);
            test = nodes[i].a;
            //fread(&d,sizeof(int),1,fp2);
            nodeDec[i].frequency = d;

            alphabets+=nodeDec[i].frequency;

            printf("\nThe character %c is present %d times\n",nodeDec[i].a,nodeDec[i].frequency);
        }
        char blank;
        //fscanf(fp2,"%c",blank);
        /*fscanf(fp2,"%d",&TRACE);
         //p=p-'0';
         printf("Trace = %d",TRACE);*/
        for(i=0; i<uniqueChars; i++)
        {
            nodeDec[i].isNode = 0;
            nodeDec[i].left = -1;
            nodeDec[i].right= -1;
        }
        noOfElements = uniqueChars;
        for(i=0; i<=noOfElements/2; i++)
        {
            LeastFrequencyDec();
        }


    }

    while(fscanf(fp2,"%c",&test)==1)
    {
        showBits(test);
    }
    printf("\n");
    decompression[length] = NULL;
    for(i=0; i<length; i++)
        printf("%c",decompression[i]);
    printf("\n");
    length = strlen(decompression);
    x=0;
    fp3 = fopen(outLocation,"w");
    if(fp3 == NULL)
        printf("ERROR!");
    else
        finalDecompression(noOfElements-1,x);
    fclose(fp3);
}


void compressionFunction()
{


    char c;
    int i=0,flag,j,least,left,right,top,x=0;
    int d=0;
    char blank;
    char test;
    FILE *fp;
    FILE *fp2;

    printf("Enter the path of file to be compressed: ");
    gets(inLocation);

    fp = fopen(inLocation,"r");
    if(fp == NULL)
    {
        puts("Invalid path... :/");
        return;
    }
    printf("Please enter path for the compressed file: ");
    gets(outLocation);
    fp2 = fopen(outLocation,"wb");
    if(fp2 == NULL)
    {
        puts("Oops! could not create the compressed file");
        return;
    }
    ///exceptions handled

    ///now code in peace ^_^
    while((c=fgetc(fp))!=EOF)
    {
        flag = 0;
        printf("%c",c);
        if(noOfElements == 0)
        {
            nodes[i].a = c;
            nodes[i].frequency+=1;
            noOfElements++;
        }
        else
        {

            for(i=0; i<noOfElements; i++)
            {
                if(c == nodes[i].a)
                {
                    nodes[i].frequency++;
                    flag = 1;
                    break;
                }

            }
            if(flag == 0)
            {
                nodes[i].a = c;
                nodes[i].frequency+=1;
                noOfElements++;
            }
        }
    }
    uniqueChars = noOfElements;

    fclose(fp);
    for(i=0; i<noOfElements; i++)
    {
        nodes[i].isNode = 0;
        nodes[i].left = -1;
        nodes[i].right= -1;
    }

    printf("\nThe number of elements before least: %d\n",noOfElements);
    for(i=0; i<=noOfElements/2; i++)
        LeastFrequency();
    printf("\nNUMBER OF ELEMENTS %d\n X IS %d\n",noOfElements,x);
    generateCodes(noOfElements-1,x);
    reWrite();
}

void displayMessage()
{
    puts("Enter");
    puts("     1 to compress");
    puts("     2 to decompress");
    puts("     3 to exit the program");
    printf("Enter your choice: ");
}

int main()
{
    int choise;
    while(1)
    {
        displayMessage();
        scanf("%d",&choise);
        getchar();
        if(choise==1)
            compressionFunction();
        else if(choise == 2)
            decompressionFunction();
        else if(choise == 3)
        {
            puts("\nThanks for trying our program ^_^\n");
            return 0;
        }
        else
        {
            puts("INVALID INPUT!");
            puts("Please try again");
        }
    }
}
