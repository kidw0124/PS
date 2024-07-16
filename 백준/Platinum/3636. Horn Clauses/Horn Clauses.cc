#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

void solve(){
    int i,j,k;
    string str;
    while(cin>>str){
        map<string,ll> mp;
        vector<pair<set<string>,string>> v;
        auto f=[&v](string tt){
            string str1=tt.substr(0,tt.find("=>"));
            string str2=tt.substr(tt.find("=>")+2);
            set<string> tmp;
            for(int i=0;i<str1.size();i++){
                if(str1[i]=='&'){
                    tmp.insert(str1.substr(0,i));
                    str1=str1.substr(i+1);
                    i=0;
                }
            }
            if(str1.size())tmp.insert(str1);
            v.push_back({tmp,str2});
        };
        while(str.size()){
            string tmp=str.substr(1,str.find(')')-1);
            str=str.substr(min(str.find(')')+2,str.size()));
            f(tmp);
        }
        for(auto &[s1,s2]:v){
            for(auto s:s1){
                mp[s]=0;
            }
            if(s2.size())mp[s2]=0;        }
        bool possible=true;
        while(true){
            bool flag=true;
            for(i=0;i<v.size();i++){
                if(v[i].first.empty()&&v[i].second.size()){
                    if(mp[v[i].second]!=2){
                        mp[v[i].second]=1;
                        for(auto &[s1,s2]:v){
                            if(s1.find(v[i].second)!=s1.end()){
                                s1.erase(v[i].second);
                            }
                        }
                        v.erase(v.begin()+i);
                        flag=false;
                        break;
                    }
                    else{
                        possible=false;
                        break;
                    }
                }
            }
            if(flag)break;
        }
        for(auto &[s1,s2]:v){
            if(s1.empty()&&s2.empty()){
                possible=false;
                break;
            }
        }
        if(possible){
            string stri;
            for(auto [s,val]:mp){
                stri+=s+"=";
                if(val==1)stri+="true";
                else stri+="false";
                stri+=",";
            }
            stri.pop_back();
            cout<<stri<<'\n';
        }
        else cout<<"unsatisfiable\n";


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