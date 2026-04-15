#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll powm(ll a, ll b){
    ll r=1;
    while(b--)r*=a;
    return r;
}

void solve(ll tc){
    ll i,j;
    ll n,m,k;
    cin>>n>>m>>k;
    vector<string>str(n);
    for(i=0;i<n;i++){
        cin>>str[i];
    }
    bool b=0;
//    for(i=0;i<n-1;i++){
//        for(j=1;j<m;j++){
//            if(str[i][j]!=str[i+1][j-1])b=1;
//        }
//    }
//    if(k==1)b=0;
    ll q;
    cin>>q;
    vector<vector<ll>>arr(n,vector<ll>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(i&&!j){
                arr[i][j]=powm(str[i][j]-str[i-1][j],k)+arr[i-1][j];
            }
            else if(j&&!i){
                arr[i][j]=powm(str[i][j]-str[i][j-1],k)+arr[i][j-1];
            }
            else if(i&&j){
                if(powm(str[i][j]-str[i-1][j],k)+arr[i-1][j]!=powm(str[i][j]-str[i][j-1],k)+arr[i][j-1]){
                    b=1;
                }
                arr[i][j]=powm(str[i][j]-str[i-1][j],k)+arr[i-1][j];
            }
        }
    }
    while(q--){
        if(b){
            cout<<"INVALID\n";
            continue;
        }
        ll r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        cout<<arr[r1-1][c1-1]-arr[r2-1][c2-1]<<"\n";
    }
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

}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(int i=0;i<t;i++){
        solve(i+1);
    }
}