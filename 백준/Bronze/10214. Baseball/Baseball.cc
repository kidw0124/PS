#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a=0,b=0;
        for(int i=0;i<9;i++){
            int j;
            cin>>j;
            a+=j;
            cin>>j;
            b+=j;
        }
        if(a>b){
            cout<<"Yonsei";
        }
        else if(a<b){
            cout<<"Korea";
        }
        else cout<<"Draw";
        cout<<"\n";
    }
}