//Sri Subhash Pathuri
//gcc lab3.c
//./a.out < input1.txt


#include <stdio.h>
#include <stdlib.h>

void readInput(int* n,int* m,int** S,int** C)
{
    // Loads all input and allocates space
    int i;

    scanf("%d",n);
    scanf("%d",m);

    int r=(*n)+1;
    int c=(*m)+1;

    *S=(int*) calloc((*n+1)*sizeof(int),sizeof(int));
    *C=(int*) calloc((*m+1)*(*n+1)*sizeof(int),sizeof(int));
    if (!(*S) || !(*C))
    {
    printf("malloc failed %d\n",__LINE__);
    exit(0);
    }

    (*S)[0]=0;   
    (*C)[0]=0;             // Sentinel zero
    for (i=1;i<=*n;i++)
    scanf("%d",*S+i);

    for(i=1;i<c;i++)
        (*C)[i]=r;//fail case

    for(i=1;i<r;i++)
    {
        (*C)[i*c]=r;
    }
}

void subsetSum(int n,int m,int* S,int* C)
{
    int i,j,potentialSum,leftover;

    // Initialize table for DP
    C[0]=0;  // DP base case
    // For each potential sum, determine the smallest index such
    // that its input value is in a subset to achieve that sum.
    for(i=1;i<=n;i++)// cardinality
    {
        for (potentialSum=1; potentialSum<=m; potentialSum++)
        {
            for (j=1;j<=n;j++)
            {
                leftover=potentialSum-S[j];      // To be achieved with other values
                if (leftover>=0 && C[((i-1)*(m+1))+leftover]<j)                
                    break;                          
                // Possible to have a solution
                // Indices are included in
                // ascending order.
            }
            C[((i)*(m+1))+potentialSum]=j;
        }
    }
}

void writeOutput(int n,int m,int* S,int* C)
{
int i,j;

printf("\nm is %d",m);
// Output the input set
printf("  i   S\n");
printf("-------\n");
for (i=0;i<=n;i++)
  printf("%3d %3d\n",i,S[i]);

// Output the DP table
/*if (m<=50)
{
  printf("  i   C\n");
  printf("-------\n");
  for (i=0;i<=m;i++)
    for(j=1;j<=n;j++){
        printf("%3d %3d %3d\n",i,j,C[i]);
    }
    
}

// Output the backtrace
if (C[m]==n+1)
  printf("No solution\n");
else
{
  printf("Solution\n");
  printf("  i   S\n");
  printf("-------\n");
  for (i=m;i>0;i-=S[C[i]])
    printf("%3d %3d\n",C[i],S[C[i]]);
}
*/

    printf("\n     i   card    c");
    printf("\n--------------------");

    for(i=0;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("\n%6d%6d%6d ",i,j,*(C+(j*(m+1))+i));
        }
    }
    

    //backtracing
    printf("\n");

    int tempSi=0;
    int tempR=0;
    int tempC=0;
    int tempValue=0;
    for(i=1;i<=n;i++)
    {
        tempR=0;
        tempC=0;   
        tempValue=0;
        if(C[((i)*(m+1))+m]!=(n+1))
        {
            printf("\nSolution with %3d elements",i);
            tempR=i;
            tempC=m;
            tempValue=C[((i)*(m+1))+m];
            printf("\n  i   s   ");
            printf("\n-------------");
            for(j=i;j>0;j--)
            {
                tempValue=C[((tempR)*(m+1))+tempC];
                tempSi=S[tempValue];
                printf("\n%3d %3d",tempValue,tempSi);
                tempR=tempR-1;
                tempC-=tempSi;
            }
        }
        else
        {
            printf("\nNo Solution with %3d elements",i);
        }
        
    }
    
}


int main()
{
    int n;    // Size of input set
    int m;    // Target value
    int *S;   // Input set
    int *C;   // Cost table (2D- long 1D)
    int i, j;
    readInput(&n,&m,&S,&C);
    
    subsetSum(n,m,S,C);

    writeOutput(n,m,S,C);

    //Needs to verify
    
    
    free(S);
    free(C);
}
//gvv
