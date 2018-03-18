#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
 
bool compareInterval(pair<ll,ll> &i1, pair<ll,ll> &i2)
{
    return (i1.first < i2.first);
}
 
ll mergeIntervals(vector<pair<ll,ll> > &arr)
{
    // Test if the given set has at least one interval
    ll n=arr.size();
    if (n <= 0)
        return 0;
    stack<pair<ll,ll> > s;
    sort(arr.begin(), arr.end(), compareInterval);
    s.push(arr[0]);
    for (int i = 1 ; i < n; i++)
    {
        // get interval from stack top
        pair<ll,ll> top = s.top();
        if (top.second < arr[i].first)
            s.push(arr[i]);
        else if (top.second < arr[i].second)
        {
            top.second = arr[i].second;
            s.pop();
            s.push(top);
        }
    }
    ll res=0;
    while (!s.empty())
    {
        pair<ll,ll> t = s.top();
        res+=(t.second-t.first+1);
      //  cout<<t.first<<" "<<t.second<<endl;
        s.pop();
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ll n,m,k;
    cin>>n>>m>>k;
    unordered_map<ll,vector<pair<ll,ll> > >arr;
    for(int i=0;i<k;i++){
        ll r,c1,c2;
        cin>>r>>c1>>c2;
        r--;c1--;c2--;
        vector<pair<ll,ll> >v;
        v=arr[r];
        v.pb(mp(c1,c2));
        arr[r]=v;
    }
    ll count=0;
    for(auto it:arr){
      //  r_++;
      //  cout<<it.second.size()<<endl;
        count+=mergeIntervals(it.second);
       // cout<<count<<endl;
    }
    ll ans=0;
    ans+=(n*m-count);
    cout<<ans<<endl;
    return 0;
}
