#include<stdio.h>
#include<stdlib.h>
#define MAX 10



 int l,s,r;



int func(int arr[],int l ,int s,int r){
   
  return (1*arr[s]+3*arr[r]+5*arr[l])%10 ;

}



int random_n( int arr[] ){
    
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
  
   for(int s=0;s<MAX;s++){
       printf("%d",a[s]);    
   } 
   printf("\n");

   for(int s=0;s<MAX;s++){
    arr[s]=a[s];
   }
}


int main(){

  int arr[MAX]={1,5,6,3,5,3,9,3,4,5};

  for(int i=0;i<100;i++){ 
  random_n(arr);
  }
}