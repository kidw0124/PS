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

vector<string>cp({"","st","nd","rd","th","th","th","th","th","th","th","th","th","th","th","th","th","th","th","th","th"});

void print(const string&team, ll m, ll M){
    cout<<"Team "+team+" can finish as high as "+to_string(m)+cp[m]+" place and as low as "+to_string(M)+cp[M]+" place.\n";
}

void solve(ll testcase){
    ll i,j,k;
    ll n,m;
    cin>>n>>m;
    if(!n)exit(0);
    vector<string>teams(n);
    vector<ll>mp(n),min_row(n),max_row(n);
    map<string,ll> rstr;
    vector<pair<ll,ll>>arr;
    for(i=0;i<n;i++){
        cin>>teams[i];
        rstr[teams[i]]=i;
    }
    for(i=0;i<m;i++){
        string sa,b,sc;
        cin>>sa>>b>>sc;
        sc.pop_back();
        ll a=rstr[sa],c=rstr[sc];
        ll x,y;
        cin>>x>>y;
        if(x==y&&x==-1){
            arr.push_back({a,c});
        }
        else if(x>y){
            mp[a]+=3;
        }
        else if(x<y){
            mp[c]+=3;
        }
        else{
            mp[a]+=1;
            mp[c]+=1;
        }
    }
    for(i=0;i<n;i++){

        min_row[i]=INT_MAX;
        max_row[i]=INT_MIN;
    }
    vector<ll>tm({1});
    for(i=0;i<arr.size();i++)tm.push_back(tm.back()*3);
    for(i=0;i<tm[arr.size()];i++){
        for(j=0;j<arr.size();j++){
            ll p=i/tm[j]%3;
            switch (p) {
                case 0:mp[arr[j].first]+=3;break;
                case 1:mp[arr[j].second]+=3;break;
                case 2:mp[arr[j].first]+=1;mp[arr[j].second]+=1;break;
            }
        }
        for(j=0;j<n;j++){
            ll r=1;
            ll pp=mp[j];
            for(auto k:mp){
                if(pp<k)r++;
            }

            min_row[j]=min(min_row[j],r);
            max_row[j]=max(max_row[j],r);
        }
        for(j=0;j<arr.size();j++){
            ll p=i/tm[j]%3;
            switch (p) {
                case 0:mp[arr[j].first]-=3;break;
                case 1:mp[arr[j].second]-=3;break;
                case 2:mp[arr[j].first]-=1;mp[arr[j].second]-=1;break;
            }
        }
    }
    for(i=0;i<n;i++){
        print(teams[i],min_row[i],max_row[i]);
    }
    cout<<'\n';
}

int main() {
    setup();
    preprocess();
    ll t=INT_MAX;
    //cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve(testcase);
    }
    return 0;
}
