#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll n,k,val,count=0;
    cin>>n>>k;
    vector<ll> ele(n);
    unordered_set<ll> arr;
    for(ll i=0;i<n;i++)
        cin>>ele[i];
    
    sort(ele.begin(),ele.end());
    for(ll i=0;i<n;i++){
        val=ele[i];
        if(arr.find(val)==arr.end()){
            arr.insert(val+k);
        }
        else{
            count++;
            arr.insert(val+k);
        }
    }
    cout<<count<<endl;
    return 0;
}
