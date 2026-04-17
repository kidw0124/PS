#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main(){
    string n;
    cin >> n;
    ll i;
    ld a=0;
    if(n.size()<=10 && stoll(n)<=720*7*8*9*10){
        ll b=1;
        for(i=1;i<=10;i++){
            b*=i;
            if(b>=stoll(n)){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    for(i=2;;i++){
        a+=log10((ld)i);
        if(a+1>=n.size()){
            cout<<i<<endl;
            return 0;
        }
    }
}