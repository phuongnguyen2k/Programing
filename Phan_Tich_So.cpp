#include<stdio.h>
#define Max 20
int Data[Max]={0},n;
void Print(int i)
{
	printf("\n%d = %d",n,Data[1]);
	for(int j=2;j<=i;++j)
		printf(" + %d ",Data[j]);
	Data[i]=Data[i-1];
}
int Plus(int i)
{
	int Sum=0;
	for(int j=1;j<=i;++j)
		Sum+=Data[j];
	if(Sum==n)return 1;
			else if(Sum<n)return 0;
				else return 2;
}
void Try(int i)
{
	for(int j=Data[i-1];j<=n;j++)
	{
//	printf("\n%d\t%d\t%d\n",i,j,Data[i]);
		if(j>=Data[i])
			{
				Data[i]=j;
//				printf("Lay Data[%d]= %d",i,Data[i]);
				if(Plus(i)==1)
				{
					Print(i);return;
				}
				else if(Plus(i)==2)return;
						else  Try(i+1);
			}
	}
}
int main()
{
	Data[0]=1;
	printf("Nhap N : ");
	scanf("%d",&n);
	Try(1);
}
