#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    for(i=0;i<n;i++){
        string str;
        cin>>str;
        ll x=str.size();
        switch(str[x-1]){
        case 'a':case 'o':case'u':
            str+='s';
            break;
        case 'i':
            str+="os";
            break;
        case 'y':
            str[x-1]='i';
            str+="os";
            break;
        case 'l':case'r':case 'v':
            str+="es";
            break;
        case 't':case'w':
            str+="as";
            break;
        case 'n':
            str[x-1]='a';
            str+="nes";
            break;
        case'e':
            if(str[x-2]=='n'){
                str[x-2]='a';
                str[x-1]='n';
                str+="es";
            }
            else{
                str+="us";
            }
            break;
        default:
            str+="us";
        }
        cout<<str<<'\n';;
    }
}
