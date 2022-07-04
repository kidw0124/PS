#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    string s;
//    while(1){
//        cin>>s;
//        if(s=="."){
//            break;
//        }
//        vector<int>pi(s.size());
//        vector<int>divisor;
//        for(i=1;i*i<=s.size();i++){
//            if(s.size()%i)continue;
//            else divisor.push_back(i),divisor.push_back(s.size()/i);
//        }
//        pi[0]=0;
//        for(i=1;i<s.size();i++){
//            j=pi[i-1];
//            while(j&&(s[i]!=s[j]))j=pi[j-1];
//            if(s[i]==s[j])pi[i]=j+1;
//        }
//        for(i=0;i<s.size();i++){
//         //   cout<<pi[i]<<' ';
//        }
//        //cout<<endl;
//        int ans=1;
//        for(auto k:divisor){
//            for(i=k;i<s.size();i+=k){
//                if(pi[i+k-1]%k==0&&pi[i+k-1]>=k)continue;
//                else break;
//            }
//            if(i==s.size())ans=max(ans,(int)s.size()/k);
//        }
//        cout<<ans<<'\n';
//
//    }
    int n;
    cin>>n;
    cin>>s;
    vector<int>pi(s.size());
    pi[0]=0;
    for(i=1;i<s.size();i++){
        j=pi[i-1];
        while(j&&(s[i]!=s[j]))j=pi[j-1];
        if(s[i]==s[j])pi[i]=j+1;
    }
    ll ans=0,now=0;
    for(i=1;i<s.size();i++){
        if(pi[i]){
            if(pi[pi[i]-1])pi[i]=pi[pi[i]-1];
            ans+=i+1-pi[i];
        }
    }

    cout<<ans;
}
