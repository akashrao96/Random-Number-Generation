#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include <math.h>
#define MAX 101



struct ran
{
char r;
};
struct ran ob;


int l,s,r;


int func(int arr[],int l ,int s,int r){
  return (((arr[s]*arr[l])+arr[r])+2)%10 ;
}


void random_n( int arr[] ){
    
   int a[MAX];
   for(int s=0;s<MAX;s++){

     if(s==0){
          r=s+1;
          l=MAX-1;
          a[s]=func(arr,l,s,r);
     }
  
      else if(s== MAX-1){
          l=s-1;
          r=0;
          a[s]=func(arr,l,s,r);
      }
      else{
         l=s-1;
         r=s+1;
         a[s]=func(arr,l,s,r);
     }
   }
  
   /*for(int s=0;s<MAX;s++){
       printf("%d",a[s]);    
   } 
   printf("\n");
   */
   for(int s=0;s<MAX;s++){
    arr[s]=a[s];
   }
}




int main()
{
  int x,arr[MAX]={1,5,6,3,5,3,9,3,4,5,
                  3,5,6,7,9,8,8,4,2,8,
                  4,7,2,3,6,8,2,6,8,9,
                  5,4,0,1,7,8,5,4,3,6,
                  9,6,7,1,0,4,9,1,7,0,
                  8,9,8,1,0,6,9,1,5,2,
                  7,3,6,4,8,7,4,4,5,0,
                  8,6,1,7,2,6,5,4,2,7,
                  9,2,3,2,7,8,7,4,5,4,
                  0,1,2,4,6,6,2,8,9,3,1
		};

  int i,j,nd,n12mb=3145728,n125mb=32768000;
  FILE *fptr;

  if ((fptr = fopen("ran2.bin","wb")) == NULL)
  {
    printf("\nError! opening file\n");
     // Program exits if the file pointer returns NULL.
    exit(1);
  }


  printf("\nEnter no of digits in each number:(Enter value within 9 otherwise int type overflows) ");
  scanf("%d",&nd);


  for(i=0;i<(3145728*4);i++)
  { 
    x=0;
    random_n(arr);
    /*for(int s=0;s<MAX;s++)
       printf("%d",arr[s]);
    printf("\n");   
    */
    for(j=0;j<nd;j++)
    {  
      x=x+ arr[j]*pow(10,nd-1-j);
    }
    /*printf("%d",x);
    printf("\n");
    */
    if(x<256 && x>0){
    ob.r=abs(x);
    fwrite(&ob,sizeof(struct ran),1,fptr); 
    }
   else{
      ob.r=abs(256-x);
    fwrite(&ob,sizeof(struct ran),1,fptr); 
   }
  }


  fclose(fptr); 

  

  //FOR READING FROM FILE FOR CHECKING

  if ((fptr=fopen("ran2.bin","rb")) == NULL)
  {
    printf("\nError! opening file\n");
    // Program exits if the file pointer returns NULL.
    exit(1);
   }

   printf("\n");

   for(i=0;i<100;i++)
   {
      fread(&ob,sizeof(struct ran),1,fptr);
      printf("%d ",ob.r);

   }
   
   fclose(fptr); 
    
   return 0;

}