#include "mylib.h"


int sum(int *array, int size){
   /*********************************
    * Sum the Contents of the Array *
    *********************************/
   int sum=0;
   int index;

   for(index=0;index<size;index++){
      sum =sum + array[index];
   }
   return sum;
}
