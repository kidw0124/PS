#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n,cnt,arr[20],s;

int main(){
    int i,j;
    cin>>n>>s;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int p=1<<n;
    for(i=1;i<p;i++){
        int sum=0;
        for(j=0;j<n;j++){
            if((i>>j)&1)sum+=arr[j];
        }
        if(sum==s)cnt++;
    }
    cout<<cnt;
    return 0;
}
