/*
Tom's guide to lab 5

some TODOS:
change types of weight from int to double.

some REQUIREMENTS:
new arrays have to be dynamically allocated (asked professor already).
*/

// Kruskal's MST using union-find trees
#include <stdio.h>
#include <stdlib.h>

int numVertices,numEdges;
int *parent,*weight,numTrees;

struct edge 
{
  int tail,head,weight;
};
typedef struct edge edgeType;
edgeType *edgeTab;

// Tom's method did not modify this for lab 5.
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

// Tom's method did not modify this for lab 5.
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
    return x->weight - y->weight;
}

// Tom's method for lab 5 requires heavy insertion of modifications here.
int main()
{
    int i,MSTweight=0;
    int root1,root2;

    // Tom says you should bring numEdges out and use the formula on PDF
    scanf("%d %d",&numVertices,&numEdges);

    // insert additional dynamic arrays here and don't forget to intialize them
    edgeTab=(edgeType*) malloc(numEdges*sizeof(edgeType));
    parent=(int*) malloc(numVertices*sizeof(int));
    weight=(int*) malloc(numVertices*sizeof(int));

    if (!edgeTab || !parent || !weight)
    {
        printf("error 2\n");
        exit(0);
    }

    // Tom says that you should probably get rid of this and replace it
    for (i=0;i<numEdges;i++)
    {
        scanf("%d %d %d",&edgeTab[i].tail,&edgeTab[i].head,&edgeTab[i].weight);
    }

    for (i=0;i<numVertices;i++)
    {
        parent[i]=i;
        weight[i]=1;
    }

    numTrees=numVertices;
    qsort(edgeTab,numEdges,sizeof(edgeType),weightAscending);

    // Tom says to change the format specifiers in printf statements
    for (i=0;i<numEdges;i++)
    {
        root1=find(edgeTab[i].tail);
        root2=find(edgeTab[i].head);
        if (root1==root2)
            printf("%d %d %d discarded\n",edgeTab[i].tail,edgeTab[i].head,
            edgeTab[i].weight);
        else
        {
            printf("%d %d %d included\n",edgeTab[i].tail,edgeTab[i].head,
            edgeTab[i].weight);
            MSTweight+=edgeTab[i].weight;
            unionFunc(root1,root2);
        }
    }

    if (numTrees!=1)
    {
        printf("MST does not exist\n");
    }

    printf("Sum of weights of spanning edges %d\n",MSTweight);

    // Tom says to free your memory, man.
    free(edgeTab);
    free(parent);
    free(weight);
}