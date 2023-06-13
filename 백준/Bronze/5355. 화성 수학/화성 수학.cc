#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
        string str;
        getline(cin,str);
    while(t--){
        getline(cin,str);

        stringstream ss(str);
        long double x;
        ss>>x;
        char c;
        while(ss>>c){
            if(c=='@')x*=3;
            if(c=='%')x+=5;
            if(c=='#')x-=7;
        }
        cout<<setprecision(2)<<fixed<<x<<'\n';
    }
}