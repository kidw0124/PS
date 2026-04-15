#include<bits/stdc++.h>
using namespace std;
using ll=long long;



void solve(ll tc){
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<string>arr(n);
    vector<vector<ll>>brr(n,vector<ll>(m));
    vector<vector<bool>>vis(n,vector<bool>(m));
    ll rx,ry;
    for(i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i].find('P')!=-1){
            rx=i,ry=arr[i].find('P');
        }
    }
    ll dx[]={1,-1,0,0},dy[]={0,0,1,-1};
    function<void(ll, ll)>dfs=[&](ll nx, ll ny){
        vis[nx][ny]=1;
//        cout<<nx<<" "<<ny<<"\n";
        if(arr[nx][ny]=='P'||arr[nx][ny]=='#'){
            for(int k=0;k<4;k++){
                ll nex=nx+dx[k],ney=ny+dy[k];
                if(nex<0||ney<0||nex>=n||ney>=m||arr[nex][ney]=='.'||vis[nex][ney])continue;
                dfs(nex,ney);
                brr[nx][ny]=brr[nex][ney];
            }
        }
        else if(isdigit(arr[nx][ny])){
            brr[nx][ny]=arr[nx][ny]-'0';
        }
        else{
            vector<ll>a;
            for(int k=0;k<4;k++){
                ll nex=nx+dx[k],ney=ny+dy[k];
                if(nex<0||ney<0||nex>=n||ney>=m||arr[nex][ney]=='.'||vis[nex][ney])continue;
                dfs(nex,ney);
                a.push_back(brr[nex][ney]);
            }
            sort(a.begin(), a.end(),greater<>());
            switch (arr[nx][ny]) {
                case'+':brr[nx][ny]=a[0]+a[1];break;
                case'-':brr[nx][ny]=a[0]-a[1];break;
                case'*':brr[nx][ny]=a[0]*a[1];break;
                case'/':brr[nx][ny]=a[0]/a[1];break;
            }
            return;
        }
    };
    dfs(rx,ry);
//    for(i=0;i<n;i++){
//        for(j=0;j<m;j++){
//            cout<<setw(4)<<brr[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
    cout<<brr[rx][ry];
}

void setup(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
#endif
}
void preprocess(){
    ll i,j;
}
int main(){
    setup();
    ll t=1;
//    cin>>t;
    for(ll tc=0;tc<t;tc++){
        solve(tc+1);
    }
}
