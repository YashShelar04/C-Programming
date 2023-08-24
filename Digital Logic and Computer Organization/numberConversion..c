#include<stdio.h>	

int main(){

   int num,bin[10],quotient,length=0;
   
   printf("Enter the decimal number: ");
   scanf("%d",&num);
   
   for(int i=0;num!=0;i++){
   
       quotient=num/2;
       bin[i]=num%2;
       num=quotient;
       length++;
   }
   
   bin[length]=num%2;
   
   for(int i=length-1;i>=0;i--){
          printf("%d",bin[i]);
          
     }
     printf("\n");
}
       
