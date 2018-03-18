#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
#include <algorithm>
const int N=1000001;
using namespace std;
vector<ll> st[4*N],arr;
vector<ll> merge(vector<ll> &a,vector<ll> &b){
    int n1=a.size();
    int n2=b.size();
    int i=0,j=0;
    vector<ll> res;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            res.push_back(a[i]);
            i++;
        }
        else{
            res.push_back(b[j]);
            j++;
        }
    }
    while(i<n1){
        res.push_back(a[i++]);
    }
    while(j<n2){
        res.push_back(b[j++]);
    }
    return res;
}
ll find_val(vector<ll> &res,ll val){
    int in=lower_bound(res.begin(),res.end(),val)-res.begin();
    if(in==0)
        return -1;
    else
        return res[in-1];
}
ll querry(int i,int s,int e,int l,int r){
   // cout<<"A";
    if(l>e or r<s){
      //  cout<<"K";
        return -1;
    }
    if(l<=s and r>=e){
        return find_val(st[i],arr[l]);
    }
    int mid=(s+e)/2;
    return max(querry(2*i+1,s,mid,l,r),querry(2*i+2,mid+1,e,l,r));
}
void build(int i,int s,int e){
  //  cout<<"B";
    if(s==e){
        st[i].push_back(arr[s]);
        return;
    }
    int mid=(s+e)/2;
    build(2*i+1,s,mid);
    build(2*i+2,mid+1,e);
    st[i]=merge(st[2*i+1],st[2*i+2]);
    return;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    ll val;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    build(0,0,n-1);
    ll res=LLONG_MAX;
    for(int i=0;i<n-1;i++){
        val=querry(0,0,n-1,i,n-1);
        if(val!=-1)
             res=min(arr[i]-val,res);
      // cout<<arr[i]<<" "<<val<<endl;
    }
    cout<<res<<endl;
    return 0;
}

