#include<stdio.h>
#include<stdlib.h>
#define N 20
int n,dem=0,spt=0;
int Arr[N][N];
int X[8]={-2,-2,-1,-1, 1,1, 2,2};
int Y[8]={ 1,-1,-2, 2,-2,2,-1,1};
void Print()
{
	printf("\n KQ : \n");
	for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			printf("%d\t",Arr[i][j]);
			printf("\n");
		}
		getchar();
	printf("\n-->So Phep toan %d .",spt);
}
void Try(int x,int y)
{
	++spt;
	++dem;
	Arr[x][y]=dem;
	for(int i=0;i<8;++i)
	{
		if(dem==n*n)
			{
				Print();
				break;
			}
		int u=x+X[i];
		int v=y+Y[i];
		if(u>=0 &&u<n&& v>=0&&v<n && Arr[u][v]==0)
			Try(u,v);
	}
	--dem;
	Arr[x][y]=0;
}
int main()
{
	int a,b;
	printf("Nhap so n : ");
	scanf("%d",&n);
	printf("\nNhap toa do x : ");
	scanf("%d",&a);
	printf("Nhap toa do y : ");
	scanf("%d",&b);
	a-=1;
	b-=1;
	Try(a,b);
	printf("\nKhong the di het ban do !! ");
	
}
