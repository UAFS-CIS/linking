#include "mylib.h"


void show(int *array, int size){
   /*******************************
    * Show Array Contents         *
    *******************************/
   int index;

   for(index=0;index<size;index++){
      if(index==0){
         printf("[");
      }else{
	 printf(",");
      }
      printf("%d",array[index]);
   }
   printf("]\n");
}
