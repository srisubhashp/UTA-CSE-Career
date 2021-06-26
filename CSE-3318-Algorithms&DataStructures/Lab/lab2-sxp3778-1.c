// Sri Subhash Pathuri , CSE 3318-003
// UTA Id : 1001733778

// Compiling Statements : 
//gcc lab2-sxp3778.c
//./a.out < lab2fall20.a.dat

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int subSequencecheck(int arrayBig[],int actArray[],int lenSmall,int lenBig,int factor) // the function that checks the subsequence 
{
    int result=0;  // equal to bool, 0 for false & 1 for true;
    int i=0,j=0,tempLimit=0;   // tempLimit is for the each multiplication factor

    int newArraySize=factor*lenSmall;
    int intSeq[newArraySize];

    for(i=0;i<lenSmall;i++)
    {
        tempLimit=(i+1)*factor;  // defines the limit for the number of times each value can be duplicated
        while(j<tempLimit)  
        {
            intSeq[j]=actArray[i];
            j++;
        }
    }
    i=0;  // counter for the created interleaved seuqnece based on the factor
    j=0;  // counter for the Array X to check the presence of a subsequence 

    while(i<newArraySize&&j<lenBig)   // loops through array A
    {
        if(intSeq[i]==arrayBig[j])
        {
            i++;   // if the values are equal then both i & j are incremented, otherwise only j is incremented
        }
        j++;
    }

    if(i==(newArraySize))   // checking if all the elements of the interleaved sequence are present in the array X
        return 1;
    return 0;
}


int main(void) {
    
    int sizeA=0,i=0;
    int sizeX=0,j=0;

    long a=0;
    
    scanf("%d",&sizeA);  //Taking in the size of Array A
    int *arrayA,* arrayX;
    arrayA=(int *)malloc(sizeA*sizeof(int)); // initializing array A values

    scanf("%d",&sizeX);   //Taking in the size of array X 

    // Entering the large array A values
    for(i=0;i<sizeA;i++){
        scanf("%d",&arrayA[i]);
    }

    scanf("%ld",&a);//-999999

    arrayX=(int *)malloc(sizeX*sizeof(int)); // initializing the array X
    
    /// Entering the small array X values
    for(j=0;j<sizeX;j++){
        scanf("%d",&arrayX[j]);
    }
    scanf("%ld",&a);//9999 

    int subSequenceNum=0;
    int factor=sizeA/sizeX; // determining the highest interleaved sequence factor 
    
    int low=0;int high=factor;int mid=0;
    int max=0; // initializing the max var to 0 which further checks the value. 


     while(low<=high) //implementing Binary Search
    {
        mid=(low+high)/2;

        if(subSequencecheck(arrayA, arrayX, sizeX, sizeA, mid)==true)// checking if that interleaved sequence is present 
        {
            printf("\nlow %d mid %d high %d passed",low,mid,high); 
            max=mid; // assigning the current highest interleaved sequence
            low=mid+1;  
        }
        else if(subSequencecheck(arrayA, arrayX, sizeX, sizeA, mid)==false) // otherwise printing failed 
        {
            printf("\nlow %d mid %d high %d failed",low,mid,high);
            high=mid-1; 
        }
    }
    printf("\nMaximum repeats is %d\n",max);  

    return 0;
}





