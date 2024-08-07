#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void preprocess() {
    ;
}

void solve() {
    ll i,j;
    ll n, m, res = 0, p;
    string s;
    cin >> n>>s;
    string arr(n,'.');
    if(count(s.begin(), s.end(),'O')==0){
        cout<<"YES\n";
        cout<<string(n,'-');
        return;
    }
    else if(count(s.begin(), s.end(),'X')==0){
        cout<<"YES\n";
        cout<<string(n,'+');
        return;
    }
    ll rot=0;
    while(s[rot]=='X')rot++;
    s=s.substr(rot)+s.substr(0,rot);
    for(i=0;i<n;i++){
        if(s[i]=='X'){
            for(j=i;j<n;j++)if(s[j]=='O')break;
            if((j-i)&1){
                ll cnt=(j-i)>>1;
                for(j=0;j<cnt;j++)arr[i+j]='+';
                for(j=0;j<cnt+1;j++)arr[i+cnt+j]='-';
                i+=cnt+j-1;
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
        else arr[i]='+';

    }
    cout<<"YES\n";
    cout<<arr.substr(n-rot)+arr.substr(0,n-rot);
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
}