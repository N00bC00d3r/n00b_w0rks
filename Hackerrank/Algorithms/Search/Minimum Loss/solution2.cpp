#include <cmath>
#include <climits>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
#include <algorithm>
#define mp make_pair
#define pb push_back
using namespace std;
bool compare(pair<ll,ll> &a1,pair<ll,ll> &b1){
    return a1.first>b1.first;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll n,a;
    cin>>n;
    vector<pair<ll,ll> >arr;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.pb(mp(a,i));
    }
    ll res=LLONG_MAX;
    sort(arr.begin(),arr.end(),compare);
    for(int i=0;i<n-1;i++){
        if(arr[i].second<arr[i+1].second){
            if(arr[i].first>arr[i+1].first){
                res=min((arr[i].first-arr[i+1].first),res);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}

