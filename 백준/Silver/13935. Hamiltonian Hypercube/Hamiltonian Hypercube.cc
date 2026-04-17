#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

ll t=0;
string s1,s2;

ll func(string s){
    ll x;
    if(s=="0")return 1;
    if(s=="1")return 2;
    if(s=="00")return 1;
    if(s=="01")return 2;
    if(s=="10")return 4;
    if(s=="11")return 3;
    else{
        if(s[0]=='0'&&s[1]=='0')x=1;
        if(s[0]=='0'&&s[1]=='1')x=2;
        if(s[0]=='1'&&s[1]=='1')x=3;
        if(s[0]=='1'&&s[1]=='0')x=4;
        if(n==2) return x;
        else{
            for(int i=2;i<n;i++){
                if(x%2){
                    if(s[i]=='0')x=2*x-1;
                    else x=2*x;
                }
                else{
                    if(s[i]=='1')x=2*x-1;
                    else x=2*x;

                }
            }
            return x;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>s1>>s2;
    if(s1==s2){
        cout<<"0";
        return 0;
    }
    cout<<func(s2)-func(s1)-1;
    long long i,j;
}
