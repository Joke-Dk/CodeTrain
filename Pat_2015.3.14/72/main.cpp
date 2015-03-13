#include <iostream>
#include <string>
#include <string.h>
using namespace std;
const int MAX = 2000;
const int INF = 10000;
const float INFF = 10000.f;
int N, M, K, Ds;
int maps[MAX][MAX];
int dis[MAX];
bool visits[MAX];

int index(string str)
{
  if(str[0]=='G')
  {
    str.erase(0, 1);
    return atoi(str.c_str())+N-1;
  }
  return atoi(str.c_str())-1;
}

string id2station( int id)
{
  char chs[10];
  sprintf( chs, "%d", id-N+1);
  return string("G")+string(chs);
}


int minID = -1;
float minDis = -1.f;
float meanDis = -1.f;
void dij( int _id)
{
  memset( dis, INF, sizeof(dis));
  memset( visits, false, sizeof(visits));
  int i;
  int cur = _id;
  dis[ cur] = 0;
  for( i=0; i<N+M; ++i)
  {
    visits[ cur] = 1;
    int j;
    for( j=0; j<N+M; ++j)
    {
      if( !visits[j] && dis[cur]+maps[cur][j]<dis[j])
      {
        dis[j] = dis[cur]+maps[cur][j];
      }
    }

    //find min
    int minD = INF;
    for( j=0; j<N+M; ++j)
    {
      if( !visits[j] && dis[j]<minD)
      {
        minD = dis[j];
        cur = j;
      }
    }
  }
  
  //test
  bool isRanged = 1;
  for( i=0; i<N; ++i)
  {
    if( dis[i]>Ds)
    {
      isRanged = 0;
      break;
    }
  }
  

  if( isRanged)
  {
    float tmpMin = INFF;
    float sum = 0.f;
    for( i=0; i<N; ++i)
    {
      sum += (float)dis[i];
      if(tmpMin>(float)dis[i])
      {
        tmpMin = (float)dis[i];
      }
    }
    sum /= (float)N;
    if( tmpMin>minDis ||
      (tmpMin==minDis && sum<meanDis))
    {
      meanDis = sum;
      minDis = tmpMin;
      minID = _id;
    }
  }

}

int main()
{
  freopen( "sample.in", "r", stdin);
  cin>>N>>M>>K>>Ds;
  int i;
  memset( maps, INF, sizeof( maps));
  for( i=0; i<K; ++i)
  {
    string p1, p2;
    int d;
    cin>>p1>>p2>>d;
    int i1 = index(p1), i2 = index(p2);
    maps[i1][i2] = d;
    maps[i2][i1] = d;
  }
  
  for( i=0; i<M; ++i)
  {
    dij( N+i);
  }
  if(minID!=-1)
  {
    cout<<id2station(minID)<<endl;
    //cout<<minDis<<" "<<meanDis<<endl;
    printf( "%.1f %.1f\n", minDis, meanDis);
  }
  else
  {
    cout<<"No Solution"<<endl;
  }
  return 0;
}