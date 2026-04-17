#include<bits/stdc++.h>
using namespace std;

vector<int> z_func(string s){
    int l=0,r=0;
    vector<int> ret(s.size());
    for(int i=1;i<s.size();i++){
        if(r<i){
            l=r=i;
            while(s[r-l]==s[r]&&r<s.size())r++;
            ret[i]=r-l;
            r--;
        }
        else{
            if(i+ret[i-l]-1<r)ret[i]=ret[i-l];
            else{
                l=i;
                while(s[r-l]==s[r])r++;
                ret[i]=r-l;
                r--;
            }
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,j;
    string s;
    cin>>s;
    int ans=-1;
    vector<int>z=z_func(s);
    vector<int>z_cp=z;
    sort(z_cp.begin(),z_cp.end());
    if(z.size()>=2){
        for(i=1;i<z.size();i++){
            if(i+z[i]==z.size()&&(z_cp[z_cp.size()-1]!=z[i]||z_cp[z_cp.size()-2]==z[i])){
                ans=max(ans,z[i]);
            }
        }
    }
    if(ans==-1)cout<<-1;
    else cout<<s.substr(0,ans);
    return 0;
}
