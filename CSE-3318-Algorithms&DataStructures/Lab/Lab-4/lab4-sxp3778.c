//Sri Subhash Pathuri; UTA Id:1001733778
//CSE 3318-003; 30-Nov-2020

//gcc lab4-sxp3778.c -lm

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void countingSort(int *size,int *k,int digitPos,int *iSet,int *count2,int *slot3)
{
    int i=0,j=0,tempDigit=0,index2=0,tempSize;

    for(i=0;i<10;i++)
    {// clearing the count2 table before being overwritten
        count2[i]=0;
    }
    for(i=0;i<*size;i++)
    {//phase2- counting elements
        tempDigit=isolateDigit(digitPos,iSet[i]);
        count2[tempDigit]++;
    }

    //Start of Phase 3- Filling up the slot table. 
    slot3[0]=0;//as the starting value will always be 0
    for(i=1;i<10;i++)
    {
        slot3[i]=count2[i-1]+slot3[i-1];
    }

    for(i=0;i<10;i++)
    {
        if((*k>slot3[i])&&(*k<=slot3[i+1]))
        {
            index2=i;//slot storing which specific digit sequence contains the K value
            tempSize=slot3[i+1]-slot3[i];
            *k=*k-slot3[i];
        }
    }

    int tempStore;
    int counter1=0;
// to store the specific isolated digit to crate the smaller sub array
    
    if(*size==1)
    {
        int tempArray[tempSize];
        int tempArrayCounter=0;//counter for incrementing pointer while adding elements
        for(i=0;i<*size;i++)
        {
            tempStore=isolateDigit(digitPos,iSet[i]);
            if(tempStore==index2)
            {
                
                tempArray[tempArrayCounter++]=iSet[i];
            }
        }
        for(i=0;i<tempSize;i++)
        {//rewriting the original sequence to make the input Array smaller.
            iSet[i]=tempArray[i];
        }

        *size=tempSize;
        counter1++;
    }
    else if(counter1==2)
    {
        counter1++;
    }
    else
    {
        int tempArray[tempSize];
        int tempArrayCounter=0;//counter for incrementing pointer while adding elements
        for(i=0;i<*size;i++)
        {
            tempStore=isolateDigit(digitPos,iSet[i]);
            if(tempStore==index2)
            {
                tempArray[tempArrayCounter++]=iSet[i];
            }
        }
        for(i=0;i<tempSize;i++)
        {//rewriting the original sequence to make the input Array smaller.
            iSet[i]=tempArray[i];
        }

        *size=tempSize;//reducing the size of the original array for the next run. 
    }
}

int isolateDigit(int pos, int num)
{
    int originNum=num;// storing the original value
    int dividend=1000000000/pow(10,pos);
    
    originNum=num%dividend;
    if(dividend/10!=0)
    {//runs this condition so that we do not divide by 0. which causes an error
        originNum=originNum/(dividend/10);
    } 
    return originNum;//returns the isolated digit
}

void readingInput(int *size,int *kValue,int **iSet)
{
    scanf("%d",size);
    scanf("%d",kValue);

    *iSet=(int *)calloc((*size)*sizeof(int),sizeof(int));

    if(!(iSet))
    {
        printf("\nUnable to open the input file..");
        exit(0);
    }
    int i=0;
    for(i=0;i<*size;i++)
    {
        scanf("%d",*iSet+i);
    }
}

int main(void) {
    int sizeI;//size of the input array
    int kValue;//
    int digitPosition=0;//to check each digit of the numbers from right to left
    
    int finalResult=0;//the final result of the Radix sort
    int slotList[10];
    int countTable[10];
    int i=0;
   

    int *inputSet;

    for(i=0;i<10;i++)
    {//intializing the count table to 0
        countTable[i]=0;
    }
    
    readingInput(&sizeI,&kValue,&inputSet);
    int origKValue=kValue;

    int counter1=0;
   do
    {   
        finalResult=inputSet[0];
        printf("\nPosition %d n %d ",(9-digitPosition),sizeI);
        countingSort(&sizeI, &kValue,digitPosition, inputSet, countTable, slotList);
        
        digitPosition++;
            

        if(sizeI==1)
            counter1++;
        if(counter1==2)
        break;
        
    }while(sizeI>=1&&digitPosition<9);
    
    printf("\n\nMSD 10 Radix: The value with rank %d is %d\n",origKValue,finalResult);
  free(inputSet);
  
  return 0;
}


