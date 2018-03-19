// Link: https://www.hackerrank.com/challenges/minimum-loss/problem

//solution:

#include <bits/stdc++.h>

using namespace std;
struct m{
  long long p,y;  
};
bool compare(m a,m b)
{
    if(a.p<b.p) return true;
    else return false;
}
long long  minimumLoss(vector <long long > price) {
    int len=price.size();
    m ar[len];
    long long i;
    for(i=0;i<len;i++)
    {
        ar[i].p=price[i];
        ar[i].y=i+1;
    }
    sort(ar,ar+len,compare);
    long long mini=LONG_MAX;
    for(i=0;i<len-1;i++)
    {
        if(ar[i].y>ar[i+1].y && mini>ar[i+1].p-ar[i].p)
            mini=ar[i+1].p-ar[i].p;
    }
    return mini;
}

int main() {
    long n;
    cin >> n;
    vector<long long> price(n);
    for(long price_i = 0; price_i < n; price_i++){
       cin >> price[price_i];
    }
    long long result = minimumLoss(price);
    cout << result << endl;
    return 0;
}

