#include<bits/stdc++.h>
using namespace std;
int main(){
    set<char>st;
    for(int i=0;i<26;i++)st.insert(i+'A');
    string str;
    cin>>str;
    for(auto k:str)st.erase(k);
    cout<<*st.begin();
}