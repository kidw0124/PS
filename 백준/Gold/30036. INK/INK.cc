#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll i,j,k;
    ll n,m,r,p=0;
    string ink;
    cin>>m>>n>>r;
    ll nowx,nowy;
    cin>>ink;
    vector<string>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i].find('@')!=string::npos){
            nowx=i;
            nowy=arr[i].find('@');
            arr[i][nowy]='.';
        }
    }
    ll now=0;
    for(i=0;i<r;i++){
        char c;
        cin>>c;
        switch(c){
        case 'U':
            if(nowx&&arr[nowx-1][nowy]=='.')nowx--;
            break;
        case 'D':
            if(nowx+1<n&&arr[nowx+1][nowy]=='.')nowx++;
            break;
        case 'L':
            if(nowy&&arr[nowx][nowy-1]=='.')nowy--;
            break;
        case 'R':
            if(nowy+1<n&&arr[nowx][nowy+1]=='.')nowy++;
            break;
        case 'j':
            now++;break;
        case 'J':
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    if(abs(nowx-j)+abs(nowy-k)<=now&&arr[j][k]!='.'){
                        arr[j][k]=ink[p%m];
                    }
                }
            }
            now=0;p++;
        }
    }
    arr[nowx][nowy]='@';
    for(auto k:arr){
        cout<<k<<'\n';
    }
}