#include<stdio.h>
#define Max 10
void Swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
int main()
{
	int i=0,Data[Max],k,n,a,b;
	printf("Nhap N : ");
	scanf("%d",&n);
	for(i=0;i<n;++i)Data[i]=0;
	do
	{
		for(i=0;i<n;++i)printf("%d ",Data[i]);
		printf("\n");
		i=n-1;
		while(i>=0&&Data[i]!=0)--i;
		if(i>=0)
		{
			Data[i]=1;
			for(k=i+1;k<n;++k)
				Data[k]=0;
		}
	}while(i>=0);
}
