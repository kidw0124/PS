#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int now=0,cnt=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        now+=x;
        now=max(0,now);
        if(now>=m)cnt++;
    }
    cout<<cnt;
}