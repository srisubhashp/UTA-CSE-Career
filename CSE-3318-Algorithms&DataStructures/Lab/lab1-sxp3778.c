//Lab1 - (CSE 3318-003) - Algorithms & Data Structures, UTArlington
//Sri Subhash Pathuri, Id: 1001733778, 15th-September-2020

//Terminal Statements used in Omega to run this program:
//gcc lab1-sxp3778.c
//./a.out < lab1fall20a.dat

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct arrayPair{
int index;
int value;
}arrayList;

int sortValue(const void *f1,const void *f2)// the qsort function to initially sort only the values in ascending order. 
{
    const arrayList *l1=f1;
    const arrayList *l2=f2;
    return l1->value - l2->value;
}
int sortIndex(const void *g1,const void *g2)// the qsort function to further sort the array by the indexs(key) in ascending order. 
{
    const arrayList *l1=g1;
    const arrayList *l2=g2;
    return l1->index - l2->index;
}

int removeDuplicates(arrayList *list1,arrayList *list2,int size){

    if(size==0||size==1)
        return size;
    
    int tempArr[size];

   int a=0,b=size-1,duplicateCount=0;
 
    for(a=size-1;a>0;a--) //Here we are looping the loop from last element to the first element.
    {
// if two consecutive values are equal, then I am copying the second element's value & index into a new array of structures.
        if((list1+a)->value!=(list1+a-1)->value)
            {  
                (list2+b)->value=(list1+a)->value;
                (list2+b)->index=(list1+a)->index;
                b--;
            }
    }
    
    (list2+b)->value=(list1)->value;
    (list2+b)->index=(list1)->index;

    return b;
}

int main(int argc, char **argv) 
{
  printf("Hello World\n");

  arrayList *list1;
  arrayList *finalList;
// declared the two array of Structures. 
  int i,total,startIndex=0;

  //printf("\n Enter the number of values present in the array : \n");
  scanf("%d",&total);

  list1=(arrayList *) malloc(total*sizeof(arrayList));
  finalList=(arrayList *) malloc(total*sizeof(arrayList));
// initializing the two arrays.

  for(i=0;i<total;i++)
  {
    scanf("%d",&(list1+i)->value); 
    (list1+i)->index=i;// accepting the values
  }


  qsort(list1, total, sizeof(arrayList),sortValue);

// returning the start index of the new array so that we can skip the uninitialized spaces.
  startIndex=removeDuplicates(list1,finalList,total);

  qsort(finalList, total,sizeof(arrayList),sortIndex);

int finalSize=total-startIndex;
// Final size of the struct array without duplicates.
printf("%d\n",finalSize);
// Finally displaying the size and followed by the array elements after sorting by the value and finally by index.
for(i=startIndex;i<total;i++){
      printf("%d\n",finalList[i].value);
  }
  
}
