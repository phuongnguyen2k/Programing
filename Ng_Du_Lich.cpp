#include<stdio.h>
#define MAX 20
int Arr[MAX][MAX],Arr_Bool[MAX],n,m;
int _Way[MAX],Best_Way[MAX],cost[MAX];
void InitArr()
{
	for(int i=1;i<=n;++i)
			Arr_Bool[i]=false;
}
void InitFile()
{
	FILE *f;
	int i,j,_Value;
	f=fopen("TOURISM.txt","r+");
	fscanf(f,"%d",&n);
	printf("%d",n);
	fscanf(f,"%d",&m);
	while(!feof(f))
	{
		fscanf(f,"%d",&i);
		fscanf(f,"%d",&j);
		fscanf(f,"%d",&_Value);
		Arr[i][j]=_Value;
		Arr[j][i]=_Value;
	}
	fclose(f);
	InitArr();
	cost[1]=0;
	_Way[1]=1;
}
void OutFile()
{
	FILE *f;
	f=fopen("OutTOURISM.txt","w+");
	for(int i=1;i<=n;++i)
		fprintf(f,"%d ->",Best_Way[i]);
	fprintf(f," 1");
	fprintf(f,"\nCost = %d",m);
	fclose(f);
}
void CoppyArr()
{
	for(int i=1;i<=n;++i)
		Best_Way[i]=_Way[i];
}
void Try(int i)
{
	for(int j=2;j<=n;++j)
	{
		if(!Arr_Bool[j])
		{
			_Way[i]=j;
			cost[i]=cost[i-1]+Arr[_Way[i-1]][j];
			if(cost[i]<m)
			{
				if(i<n)
					{
						Arr_Bool[j]=true;
						Try(i+1);
						Arr_Bool[j]=false;
					}
				else 
				if((cost[n]+Arr[_Way[i]][1])<=m)
				{
					m=cost[n]+Arr[_Way[i]][1];
					CoppyArr();
				}
			}
		}
	}
}
int main()
{
	InitFile();
	Try(2);
	OutFile();
}
