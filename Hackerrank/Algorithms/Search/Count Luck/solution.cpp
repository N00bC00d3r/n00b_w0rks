#include <bits/stdc++.h>

using namespace std;
pair<int,int>s,e;
int count1=0,n,m;
bool issafe(pair<int,int> in){
    if(in.first<0 or in.first>=n or in.second<0 or in.second>=m)
        return false;
    
    return true;
}
pair<int,int> move(pair<int,int> in,int d){
    if(d==0)
        in.first--;
    if(d==1)
        in.first++;
    if(d==2)
        in.second++;
    if(d==3)
        in.second--;
    
    return in;
}
void dfs(pair<int,int> in,vector<string> arr,vector<bool> visit[],int v){
    if(!issafe(in) or visit[in.first][in.second] or arr[in.first][in.second]=='X')
        return;
    
  // cout<<in.first<<" "<<in.second<<endl;
    
    if(in==e){
        count1=max(count1,v);
        return;
    }
    
    visit[in.first][in.second]=true;
    pair<int,int> u=move(in,0);
    pair<int,int> d=move(in,1);
    pair<int,int> r=move(in,2);
    pair<int,int> l=move(in,3);
    int c1=0;
    if(issafe(u) and arr[in.first-1][in.second]!='X' and !visit[in.first-1][in.second]){
        c1++;
    //    cout<<"u "<<in.first<<" "<<in.second<<" "<<c1<<endl;
    }
    if(issafe(d) and arr[in.first+1][in.second]!='X' and !visit[in.first+1][in.second]){
        c1++;
   //     cout<<"d "<<in.first<<" "<<in.second<<" "<<c1<<endl;
    }
    if(issafe(r) and arr[in.first][in.second+1]!='X' and !visit[in.first][in.second+1]){
        c1++;
    //    cout<<"r "<<in.first<<" "<<in.second<<" "<<c1<<endl;
    }
    if(issafe(l) and arr[in.first][in.second-1]!='X' and !visit[in.first][in.second-1]){
        c1++;
    //    cout<<"l "<<in.first<<" "<<in.second<<" "<<c1<<endl;
    }
    if(c1>1)
        v++;
    
    dfs(u,arr,visit,v);
    dfs(d,arr,visit,v);
    dfs(r,arr,visit,v);
    dfs(l,arr,visit,v);
    
    
    return;
}
string countLuck(vector <string> matrix) {
    // Complete this function
    int k;
    cin>>k;
 //   int n=matrix.size();
  //  int m=matrix[0].size();
    int s_x,s_y,e_x,e_y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             if(matrix[i][j]=='M'){
                s_x=i;s_y=j;}
             else if(matrix[i][j]=='*'){
               e_x=i;e_y=j;}
        }
    }
    s.first=s_x;s.second=s_y;
    e.first=e_x;e.second=e_y;
    vector<bool> visit[n];
    for(int i=0;i<n;i++){
        visit[i].resize(m,false);
    }
  //  visit[s_x][s_y]=true;
    count1=0;
    dfs(s,matrix,visit,0);
//    cout<<count1<<endl;
    if(count1==k)
        return "Impressed";
    else
        return "Oops!";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        cin >> n >> m;
        vector<string> matrix(n);
        for(int matrix_i = 0; matrix_i < n; matrix_i++){
           cin >> matrix[matrix_i];
        }
        string result = countLuck(matrix);
        cout << result << endl;
    }
    return 0;
}

