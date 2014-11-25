#include<cstdio>
#include<stack>
#include<algorithm>
#define MAX 505
#define INF 0x0FFFFFFF

using namespace std;

int map[MAX][MAX];
int Station[MAX];
int visited[MAX],Length[MAX];
int FinalPath[MAX],TempPath[MAX];//Path 
int flag[MAX][MAX];//DFS flag
int c,n,s,m;
int takein=INF,takeout=INF;//takein to a station,takeout from a station
int finished;//finish flag
int shortdis;//the shortest distance from PBMC to station s
int nowstep,finalstep;

void Init(int n)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		Length[i]=INF;
		for(j=0;j<=n;j++)
			map[i][j]=INF;
	}
}

void Dijkstra(int n,int d)//计算最短路径
{
	int min=INF;
	int i,j,k;
	int num;
	for(i=0;i<=n;i++)
	{
		Length[i]=map[0][i];
		visited[i]=0;
	}
	Length[0]=0;
	visited[0]=1;
	for(i=1;i<=n;i++)
	{
		min=INF;
		for(j=0;j<=n;j++)
		{
			if(!visited[j]&&Length[j]<min)
			{
				min=Length[j];
				k=j;
			}
		}
		visited[k]=1;
		for(j=0;j<=n;j++)
		{
			if(!visited[j]&&Length[j]>min+map[k][j])
			{
				Length[j]=min+map[k][j];
			}
		}
	}
	shortdis=Length[d];
}

void Compute()//计算从PBMC到该站需要带来和带走多少辆自行车
{
	int in=INF,out=INF;
	int i;
	int sum=0;
	for(i=1;i<=nowstep;i++)
	{
		sum+=Station[TempPath[i]]-c/2;
		if(sum<in)//in表示的是从PBMC到该站的路径时要达到最佳状态需要带来
			in=sum;           //的自行车数目
	}
	if(in>0)//不需要带来自行车
		in=0;
	else
		in=-in;
	out=sum+in;//需要带出自行车
	if(in<takein||(in==takein&&out<takeout))
	{
		takein=in;
		takeout=out;
		if(takein==0&&takeout==0)
			finished=1;
		finalstep=nowstep;
		for(i=1;i<=nowstep;i++)//拷贝路径
			FinalPath[i]=TempPath[i];
	}
}

void DFS(int step,int start,int len)
{
	int j;
	if(finished==1||len>Length[start])
		return;
	if(len==shortdis&&start==s)
	{
		nowstep=step;
		Compute();
	}
	for(j=1;j<=n;j++)
	{
		if(flag[start][j]==1||map[j][start]==INF)
			continue;
		flag[start][j]=flag[j][start]=1;
		TempPath[step+1]=j;
		DFS(step+1,j,len+map[start][j]);
		flag[start][j]=flag[j][start]=0;
	}
}

void Display()
{
	int i;
	printf("%d 0",takein);
	for(i=1;i<=finalstep;i++)
		printf("->%d",FinalPath[i]);
	printf(" %d\n",takeout);
}

int main(int argc,char *argv[])
{
	freopen("sample.in","r", stdin);
	int i;
	scanf("%d%d%d%d",&c,&n,&s,&m);
	Init(n);
	for(i=1;i<=n;i++)
		scanf("%d",&Station[i]);
	for(i=0;i<m;i++)
	{
		int x,y,len;
		scanf("%d%d%d",&x,&y,&len);
		map[x][y]=len;
		map[y][x]=len;
	}
	Dijkstra(n,s);
	DFS(0,0,0);
	Display();
	return 0;
}