#include<stdio.h>

void insertion(int n,int arr[]){
	int num,inx,ar[n+1];
	//Input of the number
	printf("Enter the number you want to insert: ");
	scanf("%d",&num);
	
	//Input of the index at which we want to insert
	printf("Enter the index at which you want to insert: ");
	scanf("%d",&inx);
	
	//Creating new array
	for(int i=0;i<n+1;i++){
		ar[i]=arr[i];
	}
	
	//Shifting the values to next index
	for(int i=n+1;i>inx;i--){
		ar[i]=ar[i-1];
	}
	
	//Overwriting the value of the required index
	ar[inx]=num;
	
	//Display of the new array
	for(int i=0;i<n+1;i++){
		printf("%d ",ar[i]);
	}
	
}

void deletion(int n,int arr[]){
	int num,inx;
	
	//Input of the index at which we want to delete
	printf("Enter the index at which you want to delete: ");
	scanf("%d",&inx);
	
	//Shifting the values to previous index
	for(int i=inx;i<n;i++){
		arr[i]=arr[i+1];
	}
	
	//Display of the new array
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
		n--;
	}
}

void searching(int n,int arr[]){
	int num,inx,flag=0;
	//Input of the number
	printf("Enter the number you want to search: ");
	scanf("%d",&num);
	
	for(int i=0;i<n;i++){
		if(arr[i]==num){
			printf("The specified number is at %d index of the array",i);
			flag=1;
		}
	}
	
	if(flag==0){
		printf("The specified number is not found");
	}
		
}

void sorting(int n,int arr[]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[j]<arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	//Display the new array
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}

int main(){
	int n,choice;
	int  arr[100];	
	//Input of the number of element
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	
	//Input of the each element
	for(int i=0;i<n;i++){
		printf("Enter the element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	
	//Output of the each element
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	do
	{
	printf("Choose among the following:\n 1.Insertion\n 2.Deletion\n 3.Linear Searching\n 4.Sorting\n 5.Exit\n");
	scanf("%d",&choice);
	
	//Menu
	switch(choice)
	{
		case 1: insertion(n,arr);
		        break;
		  
		case 2: deletion(n,arr);
		        break;
		        
		case 3: searching(n,arr);
		        break;
		        
		case 4: sorting(n,arr);
		        break;
		        
	}
	
	printf("\n");	                      
}while((choice<5)&&(choice>0));       	
}
