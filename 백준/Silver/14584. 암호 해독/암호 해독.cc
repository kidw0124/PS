#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string operator++(string&str){
    for(int i=0;i<str.size();i++){
        if(str[i]=='z')str[i]='a';
        else str[i]++;
    }
    return str;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    string s;
    cin>>s;
    ll n;
    cin>>n;
    vector<string>vec(n);
    for(i=0;i<n;i++){
        cin>>vec[i];
    }
    for(i=0;i<26;i++){
        for(i=0;i<n;i++){
            if(s.find(vec[i])!=string::npos){
                cout<<s;
                return 0;
            }
        }
        ++s;
    }
}
