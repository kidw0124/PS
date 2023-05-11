#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()

void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void preprocess(){

}
//vector<vector<ll>>arr;
//vector<ll>vct;
//ll m=INT_MAX,M=INT_MIN;
//void func(ll step, ll n, bitset<6>bs=bitset<6>(0)){
//    if(step==n){
//        for(ll i=0;i<(1<<n);i++){
//            if(__builtin_popcountll(i)<2){
//                ll now=1;
//                for(ll j=0;j<n-1;j++){
//                    now*=arr[vct[j]][vct[j+1]];
//                }
//                now*=arr[vct[n-1]][vct[0]];
//                m=min(m,now);
//                M=max(M,now);
//            }
//            else{
//                ll now=1;
//                vector<ll>st;
//                vector<vector<ll>>s;
//                vector<ll>tmp;
//                for(ll j=0;j<n;j++){
//                        tmp.clear();
////                        st.push_back(j);
//                    tmp.push_back(j);
//                    if(i>>j&1){
//                        s.push_back(tmp);
//                    }
//                }
//                s[0].insert(s[0].end(),tmp.begin(),tmp.end());
//                for(ll j=0;j<s.size();j++){
//                    for(ll k=0;k<s[j].size();j++){
//                        now*=arr[vct[s[j][k]]][vct[s[j][(k+1)%s[j].size()]]];
//                    }
//                }
////                ll j;
////                for(j=0;j<st.size()-1;j++){
////                    ll k;
////                    for(k=st[j];k<st[(j+1)%st.size()]-1;k++){
////                        now*=arr[vct[k]][vct[k+1]];
////                    }
////                    now*=arr[vct[k]][vct[st[j]]];
////                }
////                ll k;
////                for(k=st[j];k<n-1;k++){
////                    now*=arr[vct[k]][vct[k+1]];
////                }
////                now*=arr[vct[n-1]][vct[0]];
////                for(k=0;k<st[(j+1)%st.size()]-1;k++){
////                    now*=arr[vct[k]][vct[k+1]];
////                }
////                now*=arr[vct[k]][vct[st[j]]];
//                if(__builtin_popcountll(i)%2==0)now*=-1;
//                m=min(m,now);
//                M=max(M,now);
//
//            }
//        }
//    }
//    else{
//        for(ll i=0;i<n;i++){
//            if(!bs[i]){
//                vct.push_back(i);
//                bs[i]=1;
//                func(step+1,n,bs);
//                bs[i]=0;
//                vct.pop_back();
//            }
//        }
//    }
//}

void solve(ll testcase){
    ll i,j,k;
    ll n;
    cin>>n;
//    arr.resize(n,vector<ll>(n));
//    for(i=0;i<n;i++){
//        for(j=0;j<n;j++){
//            char x;
//            cin>>x;
//            if(isdigit(x))arr[i][j]=x-'0';
//            else arr[i][j]=-(x-'A')-1;
//        }
//    }
//    func(0,n);
//    cout<<m<<'\n'<<M;
//    vector<pll>arr(n);
//    for(i=0;i<n;i++){
//        cin>>arr[i].first>>arr[i].second;
//    }
//    sort(all(arr));
    vector<ll>arr(n);
    string str;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            str+='a';
        }
        else if(arr[i]<arr[i+1]){
            str+='b';
        }
        else str+='c';
    }
    ll cnt=0;
    for(i=0;i<n-1;i++){
        if(str[i]=='c')continue;
        else{
            j=i+1;
            while(j<n-1&&str[j]!='c'&&str[j]!=str[j-1])j++;
            cnt+=(j-i)*(j-i+1)/2;
            i=j-1;
        }
    }
    cout<<cnt<<'\n';
}

int main() {
    setup();
    preprocess();
    ll t=1;
    cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve(testcase);
    }
    return 0;
}
