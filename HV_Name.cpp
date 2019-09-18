#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define Max 10
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
int Swap_Char(char Arr1[],char Arr2[])
{			char Name[50];
			strcpy(Name,Arr1);
			strcpy(Arr1,Arr2);
			strcpy(Arr2,Name);
}
int main()
{

	char* _Name[Max];
	char Name_Sub[50],choose;	
	int n=1,i=1,count=1,k,ct=1,a,b;
	do
	{
		printf("\nNhap ten : ");
		fflush(stdin);gets(Name_Sub);
		_Name[n]=(char*)malloc(sizeof(char)*50);
		strcpy(_Name[n],Name_Sub);
		++n;
		printf("\nTiep Tuc :(Y/N)  : ");
		scanf("%c",&choose);
	}while(choose=='y'||choose=='Y');
	--n;system("cls");
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
	for(i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			{
				if(strcmp(_Name[i],_Name[j])>0)
						Swap_Char(_Name[i],_Name[j]);
			}
	for(i=1;i<=n;++i)printf("\n %s",_Name[i]);
	do
	{
		printf("\nKQ : ");
		for(i=1;i<=n;++i)printf("\n%s",_Name[i]);
		i=n-1;
		while(i>0&&strcmp(_Name[i],_Name[i+1])>0)--i;
		if(i>0)
		{
			k=n;
			while(strcmp(_Name[k],_Name[i])<0)--k;
			Swap_Char(_Name[k],_Name[i]);
			a=i+1;b=n;
			while(a<b)
				{
					Swap_Char(_Name[a],_Name[b]);
					a++;b--;
				}
	}
	}while(i!=0);
//	system("pause");
}
