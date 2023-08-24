#include<stdio.h>
#include<math.h>

int main(){
       int bin,sum=0,length=0,input;
       
       printf("Enter the binary number:\n");
       scanf("%d",&input);

       bin=input;

       for(int i=0;bin/10!=0;i++){
            length++;
            bin=bin/10;
       }

       
       for(int i=0;i<=length;i++){
       
            sum+=(input%10)*pow(2,i);
            input=input/10;
        }
        printf("The decimal number is %d\n",sum);
        
return 0;
   }
       
