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
        else if(n%3==2){
            if(n<8){
                cout<<"NO\n";
                return;
            }
            arr[0][0]=arr[0][1]=arr[0][2]
                    =arr[1][0]          =arr[1][2]
                    =arr[2][0]=arr[2][1]=arr[2][2]='O';
            i=3;
            for(j=0;j<(n-8)/3;j++){
                arr[i][i-1]='O';
                arr[i][i]='O';
                arr[i-1][i]='O';
                i++;
            }
        }
        else{
            if(n<12){
                cout<<"NO\n";
                return;
            }
            arr[0][0]=arr[0][1]=arr[0][2]=arr[0][3]
                    =arr[1][0]                  =arr[1][3]
                    =arr[2][0]                  =arr[2][3]
                    =arr[3][0]=arr[3][1]=arr[3][2]=arr[3][3]='O';
            i=4;
            for(j=0;j<(n-12)/3;j++){
                arr[i][i-1]='O';
                arr[i][i]='O';
                arr[i-1][i]='O';
                i++;
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