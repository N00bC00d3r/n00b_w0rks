// Link: https://www.hackerrank.com/challenges/count-luck/problem

//solution:

#include <bits/stdc++.h>
using namespace std;
#define ll long 
struct point{
    ll x,y;
};
ll k;
bool isprev(ll x1,ll y1,ll x2,ll y2)
{
    if(x1==x2 && y1==y2)
        return true;
    else return false;
}
bool isSafe(ll x,ll y,ll n,ll m)
{
    if(x>=n || x<0 || y<0 || y>=m)
        return false;
    else return true;
}
string countLuck(vector <string> matrix) {
    ll n,m,srow,scol,erow,ecol;
    n=matrix.size();m=matrix[0].size();
    int flag=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(matrix[i][j]=='*')
            {
                erow=i;ecol=j;
                if(flag) break;
                flag=1;
            }
            if(matrix[i][j]=='M')
            {
                srow=i;scol=j;
                if(flag) break;
                flag=1;
            }
        }
    }
    queue<point> q;
    point p;
    point ar[n][m];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            ar[i][j].x=-1;
            ar[i][j].y=-1;
        }
    }
    bool visited[n][m];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            visited[i][j]=false;
        }
    }
    p.x=srow;p.y=scol;
    visited[srow][scol]=true;
    q.push(p);
    while(!q.empty())
    {
        point temp=q.front();
        q.pop();
        if(temp.x==erow && temp.y==ecol)
        {
            break;
        }
            point res;
        if(isSafe(temp.x+1,temp.y,n,m) && visited[temp.x+1][temp.y]==false && matrix[temp.x+1][temp.y]!='X')
        {
              //cout<<"pushing:"<<temp.x+1<<" "<<temp.y<<"\n";
            res.x=temp.x+1;res.y=temp.y;
            q.push(res);
            visited[temp.x+1][temp.y]=true;
            ar[temp.x+1][temp.y]=temp;
        }
        if(isSafe(temp.x,temp.y+1,n,m) && visited[temp.x][temp.y+1]==false && matrix[temp.x][temp.y+1]!='X')
        {
            //cout<<"pushing:"<<temp.x<<" "<<temp.y+1<<"\n";
            res.x=temp.x;res.y=temp.y+1;
            q.push(res);
            visited[temp.x][temp.y+1]=true;
            ar[temp.x][temp.y+1]=temp;
        }        
        if(isSafe(temp.x-1,temp.y,n,m) && visited[temp.x-1][temp.y]==false && matrix[temp.x-1][temp.y]!='X')
        {
            // cout<<"pushing:"<<temp.x-1<<" "<<temp.y<<"\n";
            res.x=temp.x-1;res.y=temp.y;
            q.push(res);
            visited[temp.x-1][temp.y]=true;
            ar[temp.x-1][temp.y]=temp;
        }
        if(isSafe(temp.x,temp.y-1,n,m) && visited[temp.x][temp.y-1]==false && matrix[temp.x][temp.y-1]!='X')
        {
              //cout<<"pushing:"<<temp.x<<" "<<temp.y-1<<"\n";
            res.x=temp.x;res.y=temp.y-1;
            q.push(res);
            visited[temp.x][temp.y-1]=true;
            ar[temp.x][temp.y-1]=temp;
        }
    }
    ll count=0,path=0;
    point res;
    res.x=erow;res.y=ecol;
    //cout<<"end:("<<erow<<","<<ecol<<") ";
    while(res.x!=-1 && res.y!=-1)
    {
        //cout<<"iteration:\n";
        point prev,gd;
        prev.x=ar[res.x][res.y].x;
        prev.y=ar[res.x][res.y].y;
        gd.x=ar[prev.x][prev.y].x;
        gd.y=ar[prev.x][prev.y].y;
          //cout<<"("<<prev.x<<","<<prev.y<<") \n";
           //cout<<"("<<gd.x<<","<<gd.y<<") \n";
        if(prev.x==-1) break;
        path=0;
        if(isSafe(prev.x+1,prev.y,n,m) && matrix[prev.x+1][prev.y]!='X' && !(isprev(prev.x+1,prev.y,gd.x,gd.y))) 
        {
            //cout<<"path-D\n";
            path++;
        }
         if(isSafe(prev.x,prev.y+1,n,m) && matrix[prev.x][prev.y+1]!='X'&& !(isprev(prev.x,prev.y+1,gd.x,gd.y))) 
         {
            // cout<<"path-R\n";
             path++;
         }
         if(isSafe(prev.x-1,prev.y,n,m) && matrix[prev.x-1][prev.y]!='X' && !(isprev(prev.x-1,prev.y,gd.x,gd.y))) 
         {
             //cout<<"path-T\n";
             path++;
         }
         if(isSafe(prev.x,prev.y-1,n,m) && matrix[prev.x][prev.y-1]!='X'&& !(isprev(prev.x,prev.y-1,gd.x,gd.y))) 
         {
            // cout<<"path-L\n";
             path++;
         }
        if(path>1) count++;
        res.x=prev.x;
        res.y=prev.y;
        
    }
    if(count==k) return "Impressed";
    else return "Oops!";
    
}

int main() {
    ll t;
    cin >> t;
    for(ll a0 = 0; a0 < t; a0++){
        ll n;
        ll m;
        cin >> n >> m;
        vector<string> matrix(n);
        for(ll matrix_i = 0; matrix_i < n; matrix_i++){
           cin >> matrix[matrix_i];
        }
        cin>>k;
        string result = countLuck(matrix);
        cout << result << endl;
    }
    return 0;
}

