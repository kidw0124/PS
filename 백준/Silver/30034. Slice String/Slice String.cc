#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll i,j,k;
    ll n,m,r;
    set<char>st;
    cin>>n;
    for(i=0;i<n;i++){
        char c;
        cin>>c;
        st.insert(c);
    }
    cin>>n;
    for(i=0;i<n;i++){
        char c;
        cin>>c;
        st.insert(c);
    }
    cin>>n;
    for(i=0;i<n;i++){
        char c;
        cin>>c;
        st.erase(c);
    }
    vector<string>strv;
    string str;
    cin>>n;
    while(cin>>str){
        for(auto&k:str){
            if(st.find(k)!=st.end())k=' ';
        }
        stringstream ss(str);
        while(ss>>str){
            strv.push_back(str);
        }
    }
    for(string str:strv){
        cout<<str<<'\n';
    }
}