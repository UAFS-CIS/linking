#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "mylib.h"

int main(){
   int array[]={10,20,30,40,50};
   int total;
   void *handle;
   int (*sum)(int *, int);
   void (*show)(int *, int);
   char *error;

   /**** Dynamically Load the Shared Library - libmylib.so ****/
   printf("Load Shared Library\n");
   handle=dlopen("/usr/lib/libmylib.so",RTLD_LAZY);
   if(!handle){
      fprintf(stderr,"%s\n",dlerror());
      exit(1);
   }

   /*** Get Pointers to the Two Functions ****/
   sum=dlsym(handle,"sum");
   error=dlerror();
   if(error!=NULL){
      fprintf(stderr,"%s\n",error);
      exit(1);
   }

   show=dlsym(handle,"show");
   error=dlerror();
   if(error!=NULL){
      fprintf(stderr,"%s\n",error);
      exit(1);
   }

   total=sum(array,SIZE);
   show(array,SIZE);
   printf("Total: %d\n",total);

   /*** Unload the Shared Library ***/
   printf("Unload Shared Library\n");
   if(dlclose(handle)<0){
      fprintf(stderr,"%s\n",error);
      exit(1);
   }

   return 0;
}
