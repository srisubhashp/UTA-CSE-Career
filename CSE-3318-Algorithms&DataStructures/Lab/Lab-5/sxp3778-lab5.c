/*
Sri Subhash Pathuri; UTA Id-1001733778;lab 5
7th December,2020

Compile Statement:
gcc sxp3778-lab5.c -lm

some TODOS:
change types of weight from int to double.

some REQUIREMENTS:
new arrays have to be dynamically allocated (asked professor already).
*/

// Kruskal's MST using union-find trees
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numVertices,numEdges;
int *parent,numTrees;

double* weight;

struct edge 
{
  int tail,head;
  double weight;
};
typedef struct edge edgeType;
edgeType *edgeTab;

//_______________input part 1_______________________________________

//int tempNumVertices,tempNumEdges;
int numVertices,numEdges;
struct inputTableStruct{
    int head;
    int tail;
};

typedef struct inputTableStruct inputTable; 

//________________input part1 end__________________________________


// did not modify this for lab 5.
// Find root of tree containing x
int find(int x)
{
    int i,j,root;

    // Find root
    for (i=x; parent[i]!=i; i=parent[i]);
    root=i;
    // path compression - make all nodes on path
    // point directly at the root
    for (i=x; parent[i]!=i; j=parent[i],parent[i]=root,i=j);

    return root;
}

//did not modify this for lab 5.
// i and j must be roots!
void unionFunc(int i,int j)
{
    if (weight[i]>weight[j])
    {
        parent[j]=i;
        weight[i]+=weight[j];
    }
    else
    {
        parent[i]=j;
        weight[j]+=weight[i];
    }
    numTrees--;
}

// Modification is required to make qsort work with doubles. Change what's inside here.
// Used in call to qsort()
int weightAscending(const void* xin, const void* yin)
{
    edgeType *x,*y;

    x=(edgeType*) xin;
    y=(edgeType*) yin;
    
    if(x->weight > y->weight)
    {
        return 1;
    }
    else if(x->weight < y->weight)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// for lab 5 requires heavy insertion of modifications here.
int main()
{
    int i;
    double MSTweight=0;
    int root1,root2;
    // brought numEdges out and use the formula on PDF
    scanf("%d",&numVertices);

    
    numEdges=(numVertices*(numVertices-1)/2);



    // insert additional dynamic arrays here and don't forget to intialize them
    edgeTab=(edgeType*) malloc(numEdges*sizeof(edgeType));
    parent=(int*) malloc(numVertices*sizeof(int));
    weight=(double*) malloc(numVertices*sizeof(double));

if (!edgeTab || !parent || !weight)
    {
        printf("error 2\n");
        exit(0);
    }

//____________________Reading Part Begins___________
    int size=0,k=0;
    inputTable *inputSet;
    int tempOutputSize=0;
    
    
    inputSet=(inputTable *)malloc(numVertices*sizeof(inputTable));

    for(i=0;i<numVertices;i++)
    {
        scanf("%d %d",&inputSet[i].tail,&inputSet[i].head);
    }
    int j=0;
    
    for(i=0;i<numVertices;i++)
    {
        printf("\n%d %d %d",i,inputSet[i].tail,inputSet[i].head);
    }
    for(i=0;i<numVertices;i++)
    {
        for(j=i+1;j<numVertices;j++)
        {
            edgeTab[tempOutputSize].tail=i;
            edgeTab[tempOutputSize].head=j;
            edgeTab[tempOutputSize].weight=sqrt(pow((inputSet[j].tail-inputSet[i].tail),2)+pow((inputSet[j].head-inputSet[i].head),2));
            tempOutputSize++;
        }
    }


    
//____________________End of Reading_____________


    //
    for (i=0;i<numVertices;i++)
    {
        parent[i]=i;
        weight[i]=1;
    }

    numTrees=numVertices;
    qsort(edgeTab,numEdges,sizeof(edgeType),weightAscending);

    // changed the format specifiers in printf statements
    int counter=0;
    for (i=0;i<numEdges;i++)
    {
        if(counter==numVertices-1)
            break;
        root1=find(edgeTab[i].tail);
        root2=find(edgeTab[i].head);
        if (root1==root2)
            printf("\n%d %3d      %3.3f discarded",edgeTab[i].tail,edgeTab[i].head,edgeTab[i].weight);
        else
        {   
            counter++;
            printf("\n%d %3d      %3.3f included",edgeTab[i].tail,edgeTab[i].head,edgeTab[i].weight);
            MSTweight+=edgeTab[i].weight;
            unionFunc(root1,root2);
        }
    }

    if (numTrees!=1)
    {
        printf("MST does not exist\n");
    }

    printf("\nSum of weights of spanning edges %.3f\n",MSTweight);

    //  memory, man.
    free(edgeTab);
    free(parent);
    free(weight);

    
}



