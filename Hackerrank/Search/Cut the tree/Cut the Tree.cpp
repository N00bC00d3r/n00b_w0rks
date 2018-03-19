// Link: https://www.hackerrank.com/challenges/cut-the-tree/problem

//solution:

#include <bits/stdc++.h>
using namespace std;
vector<int> data;
vector<bool> visited;
vector<int> sum;
int n;
struct adjlist
{
  vector<int> v;  
};
long res;
int dfs(int index,adjlist ar[],int parent[])
{
    int i;
    long ans=data[index];
    visited[index]=true;
    for(i=0;i<ar[index].v.size();i++)
    {
        if(!visited[ar[index].v[i]])
        {
            parent[ar[index].v[i]]=index;
            ans+=dfs(ar[index].v[i],ar,parent);
        }
    }
    sum[index]=ans;
    return ans;
}
int cutTheTree(adjlist ar[]) {
    int parent[n],j,i;
    memset(parent,-1,sizeof(parent));
   int totalsum=dfs(0,ar,parent);
   /* for(int i=0;i<n;i++)
    {
        cout<<parent[i]<<" ";
    }*/
    int res=INT_MAX;
    for(i=0;i<n;i++)
    {
        for(j=0;j<ar[i].v.size();j++)
        {
            if(ar[i].v[j]!=parent[i])
            {
                int t1=totalsum-sum[ar[i].v[j]];
                res=min(res,abs(t1-sum[ar[i].v[j]]));
            }
        }
    }
    return res;

}

int main() {
    int i,x,y;
    cin >> n;
    adjlist ar[n];
    data.reserve(n);
    sum.reserve(n);
    visited.reserve(n);
    for(i=0;i<n;i++) visited[i]=false;
    for(int data_i = 0; data_i < n; data_i++){
       cin >> data[data_i];
    }
    for(i=0;i<n-1;i++)
    {
        cin>>x>>y;
        x--;y--;
        ar[x].v.push_back(y);
        ar[y].v.push_back(x);
    }
    
    int result = cutTheTree(ar);
    cout << result << endl;
    return 0;
}

