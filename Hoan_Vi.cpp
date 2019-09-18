#include<stdio.h>
#include<Windows.h>
#define max 20
int Data[max];
void Swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
int main()
{
	int n,i,k,a,b;
	printf("Nhap N : ");
	scanf("%d",&n);
	for(i=1;i<=n;++i)Data[i]=i;
	system("cls");
	gotoxy(10,2);
	printf("Dang Swap : [. . . . . . . . . . ]");
	for(int i=23;i<43;++i)
	{
		gotoxy(i,2);
		printf("%c",177);
		gotoxy(44,2);
		printf("%d%%",(i-22)*5);
		Sleep(50);
	}
	printf("\n");
	do
	{
		for(i=1;i<=n;++i)
			printf("%d ",Data[i]);
		printf("\n");
		i=n-1;
		while(i>0&&Data[i]>Data[i+1])i--;
		if(i>0)
		{
			k=n;
			while(Data[k]<Data[i])k--;
			Swap(Data[k],Data[i]);
			a=i+1;b=n;
			while(a<b)
			{
				Swap(Data[a],Data[b]);
				a++;b--;
			}
		}
	}while(i!=0);
}
