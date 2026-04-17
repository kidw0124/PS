#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i;
    string s;
    cin>>s;
    vector<int>o;
    int l=s.size();
    for(i=0;i<l;i++){
        if(s[i]>='A')s[i]+=-'A'+10;
        else s[i]-='0';
    }
    for(i=0;i<l;i++){
        int t=s[i]*16+s[++i];
        cout<<(char)t;
    }


    return 0;
}
