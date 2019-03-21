#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define sizex 100
#define sizey 100
#define sizez 100

long int random_n(){

  long int arr[sizex][sizey][sizez],i,j,k;

    for(i=0;i<sizex;i++){
        for(j=0;j<sizey;j++){
	   for(k=0;k<sizez;k++){
		
            arr[i][j][k]=rand();
         
           }	
	}
    }

    int x = rand()%sizex;
    int y = rand()%sizey;
    int z = rand()%sizez;


  
       return arr[x][y][z];
     
    

}

int main(){

  srand(time(0));
  for(int i=0;i<100;i++){
 
   printf("%ld\n",random_n());
  }
}