#include<stdio.h>
#define MAX 50
int Data_Source[MAX]={2,3,1,5,2,6,4,8,5,9};
int Data[MAX],n=10,k=4;
void Print(int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",Data[i]);
	printf("\n");
}
void Try(int j,int i)
{
	for(i;i<n;i++)
	{
		if(Data[j-1]<Data_Source[i])
		{
		Data[j]=Data_Source[i];
		if(j==k-1)
			Print(k);
		else
			Try(j+1,i+1);
		}
	}
}
int main()
{
//	do{
//		printf("Nhap n (n<50) : ");
//		scanf("%d",&n);
//		if(n>50)printf("\nBan phai nhap n < 50");
//	}while(n>50);
//	printf("\nNhap k (k<n) : ");
//	scanf("%d",&k);
	Try(0,0);
	
}
