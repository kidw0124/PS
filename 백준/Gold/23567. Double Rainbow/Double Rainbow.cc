#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, i, j, a[10010], cnt[10010], assist1[10010], assist2[10010], flag1, flag2, res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    res=n+1;
    for(i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(i=0;i<n;i++){
        flag1=0;
        flag2=0;
        for(j=1;j<=m;j++){
            assist1[j]=0;
            assist2[j]=cnt[j];
            if(cnt[j]!=0)flag2++;
        }
        if(flag2!=m){
            cout<<"0";
            return 0;
        }
        assist1[a[i]]++;
        assist2[a[i]]--;
        flag1++;
        if(assist2[a[i]]==0)flag2--;
        if(flag1==m&&flag2==m){
            if(res>1)res=1;
            continue;
        }
        for(j=i+1;j<n;j++){
            if(assist1[a[j]]==0){
                flag1++;
            }
            assist1[a[j]]++;
            if(assist2[a[j]]==1){
                flag2--;
            }
            assist2[a[j]]--;
            if(flag1==m&&flag2==m){
                if(res>j-i+1)res=j-i+1;
                continue;
            }
        }
    }
    if(res==n+1)res=0;
    cout<<res;
    return 0;
}
