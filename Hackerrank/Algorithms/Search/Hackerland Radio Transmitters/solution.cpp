#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,q,v;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int count=0;
    auto i=arr.begin();
    while(i!=arr.end()){
        auto i1=upper_bound(arr.begin(),arr.end(),*i+q);
        i1--;
        //cout<<*i1<<endl;
        count++;
        i=upper_bound(arr.begin(),arr.end(),*i1+q);
    }
    cout<<count<<endl;
    return 0;
}
