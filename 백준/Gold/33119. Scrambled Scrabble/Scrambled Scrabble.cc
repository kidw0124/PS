#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(ll tc){
    ll i,j;
    string str;
    cin>>str;
    ll c=0,v=0,y=0,n=0,g=0;
    for(auto&x:str){
        switch (x) {
            case 'A':case 'E':case 'I':case 'O':case 'U':v++;break;
            case 'Y':y++;break;
            case 'N':n++;break;
            case 'G':g++;break;
            default:c++;
        }
    }
    ll ng=min(n,g);
    c+=n+g-2*ng;
    if(c+ng>=2*(v+y)){
        if(ng>=2*(v+y)){
            cout<<5*(v+y);
        }
        else{
            cout<<3*(v+y)+ng;
        }
    }
    else if(c+2*ng>=2*(v+y)){
        cout<<str.size();
    }
    else if(2*v>=c+2*ng+y){
        ll totc=c+2*ng+y;
        if(totc&1){
            if(ng){
                cout<<totc/2*3+1;
            }
            else{
                cout<<totc/2*3;
            }
        }
        else{
            cout<<totc/2*3;
        }
    }
    else if(2*v>=c+ng+y){
        cout<<str.size();
    }
    else{
        if(c+ng>=2*v){
            if(ng==0){
                ll rem=c+ng-2*v;
                cout<<3*v+(rem+y)/3*3;
            }
            else{
                ll rem=c+ng-2*v;
                if((rem+y)%3==0){
                    cout<<str.size();
                }
                else if((rem+y)%3==1){
                    if(ng>=2){
                        cout<<str.size();
                    }
                    else{
                        cout<<str.size()-1;
                    }
                }
                else{
                    cout<<str.size();
                }
            }
        }
        else{
            if(ng==0){
                cout<<str.size()/3*3;
            }
            else if(ng==1){
                if(str.size()%3==0||str.size()%3==1){
                    cout<<str.size();
                }
                else{
                    cout<<str.size()-1;
                }
            }
            else{
                cout<<str.size();
            }
        }
    }

}

void setup(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
#endif
}

void preprocess(){

}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(int i=0;i<t;i++){
        solve(i+1);
    }
}