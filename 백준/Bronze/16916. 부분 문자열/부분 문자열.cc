#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    char s11[1'000'005],s12[1'000'005];
    strcpy(s11,s1.c_str());
    strcpy(s12,s2.c_str());
    if(strstr(s11,s12))cout<<1;
    else cout<<0;
}