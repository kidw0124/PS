#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

LL t,n;

LL arr[405][405];

LL pre[405][405];

bool check[405][405];

LL xi,yi,xh,yh;

LL rem=1000000007,ans;

int main(){
    LL i,j,k;
    cin>>xi>>yi>>t>>xh>>yh;

    LL dx=xi-200;
    LL dy=yi-200;
    xh-=dx;
    xi-=dx;
    yh-=dy;
    yi-=dy;

    if(xh<0||xh>400||yh<0||yh>400){
        cout<<0;
        return 0;
    }

    arr[xi][yi]=1;
    cin>>n;
    for(i=0;i<n;i++){
        LL x,y;
        cin>>x>>y;
        x-=dx;
        y-=dy;
        if(x>=0&&x<=400&&y>=0&&y<=400){
            check[x][y]=1;
        }
    }

    for(i=0;i<t;i++){
        //char filename[200]={0};
       // sprintf(filename,"f%lld",i);
        //FILE*fp=fopen(filename,"w");
        for(j=0;j<405;j++){
            for(k=0;k<405;k++){
          //      fprintf(fp,"%lld ",arr[j][k]);
                pre[j][k]=arr[j][k];
            }
            //fprintf(fp,"\n");
        }
        pre[xh][yh]=0;
        //fclose(fp);
        for(j=1;j<404;j++){
            for(k=1;k<404;k++){
                if(!check[j][k]){
                    arr[j][k]=(pre[j-1][k]+pre[j+1][k]+pre[j][k-1]+pre[j][k+1])%rem;
                }
            }
        }
        for(j=1;j<404;j++){
            if(!check[0][j])arr[0][j]=(pre[0][j-1]+pre[0][j+1]+pre[1][j])%rem;
            if(!check[404][j])arr[404][j]=(pre[404][j-1]+pre[404][j+1]+pre[403][j])%rem;
            if(!check[j][0])arr[j][0]=(pre[j-1][0]+pre[j+1][0]+pre[j][1])%rem;
            if(!check[j][404])arr[j][404]=(pre[j-1][404]+pre[j+1][404]+pre[j][403])%rem;
        }
        if(!check[0][0])arr[0][0]=(pre[0][1]+pre[1][0])%rem;
        if(!check[404][0])arr[404][0]=(pre[404][1]+pre[403][0])%rem;
        if(!check[0][404])arr[0][404]=(pre[1][404]+pre[0][403])%rem;
        if(!check[404][404])pre[404][404]=(pre[403][404]+pre[404][403])%rem;
        ans+=arr[xh][yh];
        ans%=rem;
    }

    cout<<ans%rem;


    return 0;
}
