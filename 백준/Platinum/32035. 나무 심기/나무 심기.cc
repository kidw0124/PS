#include<bits/stdc++.h>
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

void solve(){
    int i,j,k;
    int n,m;
    cin>>n>>m;
    vector<string> arr(200,string(200,'.'));
    if(m==0){
        if(n%3==1){
            arr[0][0]='O';
            i=1;
            for(j=0;j<(n-1)/3;j++){
                arr[i][i-1]='O';
                arr[i][i]='O';
                arr[i-1][i]='O';
                i++;
            }
        }
        else{
            if(n%2==1&&n<11){
                cout<<"NO\n";
                return;
            }
            if(n<8){
                cout<<"NO\n";
                return;
            }
            int x=n%2;
            if(x)n-=3;
            for(i=0;i<(n-2)/2;i++){
                arr[i][0]=arr[i][2]='O';
            }
            arr[0][1]='O';
            arr[i-1][1]='O';
            if(x){
                arr[i][2]=arr[i][3]=arr[i-1][3]='O';
            }
        }
    }
    else if(m&1){
        cout<<"NO\n";
        return;
    }
    else{
        arr[0][2]='O';
        i=1;
        for(j=0;j<(m-1)/2;j++){
            arr[i][2]='O';
            if(j&1){
                arr[i][1]='O';
            }
            else{
                arr[i][3]='O';
            }
            i++;
        }
        for(j=0;j<n;j++){
            arr[i][2]='O';
            i++;
        }
        arr[i][2]='O';
    }
    cout<<"YES\n";
    cout<<"200 200\n";
    for(i=0;i<200;i++) {
        cout << arr[i] << '\n';
    }
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t st=clock();
#else
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
    int t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}