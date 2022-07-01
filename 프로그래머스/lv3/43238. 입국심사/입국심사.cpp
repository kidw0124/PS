#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long solution(int n, vector<int> times) {
    long long answer = 0;
    ll l=1,r=1'000'000'000'000'000'000;
    while(l<r){
        ll mid=(l+r)>>1;
        ll now=0;
        for(auto k:times){
            now+=mid/k;
        }
        if(now<n){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    return l;
}