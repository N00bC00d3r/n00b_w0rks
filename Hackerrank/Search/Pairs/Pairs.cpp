// Link: https://www.hackerrank.com/challenges/pairs/problem

//solution:

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n,k;
    cin>>n>>k;
    ll ar[n],i,maximum=LONG_MIN;
    set<ll> s;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
        s.insert(ar[i]);
        maximum=max(maximum,ar[i]);
    }
    ll count=0;
    for(i=0;i<n;i++)
    {
        if(ar[i]+k>maximum)
            continue;
        if(s.find(ar[i]+k)!=s.end()) count++;
    }
    cout<<count<<"\n";
    return 0;
}

