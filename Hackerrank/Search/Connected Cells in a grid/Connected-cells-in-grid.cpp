// Link: https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem

//solution:

#include <bits/stdc++.h>
int n,m;
using namespace std;
bool visited[10][10];
int matrix[10][10];
vector<pair<int,int>> v;
bool isSafe(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    else return true;
}
void dfs(pair<int,int> p,int *count)
{
   // cout<<"x:"<<p.first<<" "<<p.second<<"\n";
    visited[p.first][p.second]=true;
    int x=p.first;
    int y=p.second;
    pair<int,int> q;
    if(isSafe(x+1,y))
    {   
       if( matrix[x+1][y]==1 && !visited[x+1][y] )
       {
            q.first=x+1;
            q.second=y;
            (*count)=(*count)+1;
            dfs(q,count);
        }
    }
    if(isSafe(x,y+1))
    {   
       if( matrix[x][y+1]==1 && !visited[x][y+1] )
       {
            q.first=x;
            q.second=y+1;
            (*count)=(*count)+1;
            dfs(q,count);
        }
    }
    if(isSafe(x+1,y+1))
    {   
       if( matrix[x+1][y+1]==1 && !visited[x+1][y+1] )
       {
            q.first=x+1;
            q.second=y+1;
            (*count)=(*count)+1;
            dfs(q,count);
        }
    }
    if(isSafe(x-1,y))
    {   
       if( matrix[x-1][y]==1 && !visited[x-1][y] )
       {
            q.first=x-1;
            q.second=y;
            (*count)=(*count)+1;
            dfs(q,count);
        }
    }
    if(isSafe(x,y-1))
    {   
       if( matrix[x][y-1]==1 && !visited[x][y-1] )
       {
            q.first=x;
            q.second=y-1;
            (*count)=(*count)+1;
            dfs(q,count);
        }
    }
    if(isSafe(x-1,y-1))
    {   
       if( matrix[x-1][y-1]==1 && !visited[x-1][y-1] )
       {
            q.first=x-1;
            q.second=y-1;
            (*count)=(*count)+1;
            dfs(q,count);
        }
    }
    if(isSafe(x+1,y-1))
    {   
       if( matrix[x+1][y-1]==1 && !visited[x+1][y-1] )
       {
            q.first=x+1;
            q.second=y-1;
            (*count)=(*count)+1;
            dfs(q,count);
        }
    }
    if(isSafe(x-1,y+1))
    {   
       if( matrix[x-1][y+1]==1 && !visited[x-1][y+1] )
       {
            q.first=x-1;
            q.second=y+1;
            (*count)=(*count)+1;
            dfs(q,count);
        }
    }
}
int connectedCell() {
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            visited[i][j]=false;
            if(matrix[i][j]==1)
                v.push_back(make_pair(i,j));
        }
    }
    int count,res=0;
    for(i=0;i<v.size();i++)
    {
        if(visited[v[i].first][v[i].second]==false)
        {
            count=1;
            pair<int,int> p;
            p.first=v[i].first;
            p.second=v[i].second;
           // cout<<"i:"<<p.first<<" "<<"j:"<<p.second<<"\n";
            dfs(p,&count);
          // cout<<res<<":res\n";
            res=max(res,count);
        }
    }
    
    return res;
}

int main() {
    cin >> n;
    cin >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    int result = connectedCell();
    cout << result << endl;
    return 0;
}

