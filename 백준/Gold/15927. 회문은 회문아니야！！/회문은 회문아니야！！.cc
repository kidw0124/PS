#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

string s1,s2;

int main(){
    int i,j;

    cin>>s1;
    s2=s1;
    char s=s1.back();
    while(!s1.empty()){
        if(s-s1.back()){
            goto abc;
        }
        s1.pop_back();
    }

    cout<<-1;
    return 0;

    abc:s1=s2;
    reverse(s1.begin(),s1.end());

    if(s1==s2){
        cout<<s1.size()-1;
    }else{
        cout<<s1.size();
    }

    return 0;
}
