#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

char arr[50002][11],ans[50002][11];
int wall[50002][11],wall_cnt[11];

int r,c;

int main(){
    int i,j,k;
    cin>>r>>c;
    for(j=0;j<c;j++){
        ans[0][j]=ans[r+1][j]=arr[0][j]=arr[r+1][j]='#';
    }
    for(i=1;i<=r;i++){
        for(j=0;j<c;j++){
            scanf(" %c",arr[i]+j);
            if(arr[i][j]=='#')ans[i][j]='#';
        }
    }
    for(j=0;j<c;j++){
        int c=0;
        for(i=0;i<=r+1;i++){
            if(arr[i][j]=='#')wall[c++][j]=i;
        }
        wall_cnt[j]=i-1;
    }
    for(j=0;j<c;j++){
        for(i=0;i<wall_cnt[j];i++){
            int cc=0;
            for(k=wall[i][j]+1;k<wall[i+1][j];k++){
                if(arr[k][j]=='a')cc++;
            }
            for(k=wall[i+1][j]-1;cc>0;cc--,k--){
                ans[k][j]='a';
            }
        }
    }
    for(i=1;i<=r;i++){
        for(j=0;j<c;j++){
            printf("%c",(ans[i][j]?ans[i][j]:'.'));
        }
        puts("");
    }
    return 0;
}
