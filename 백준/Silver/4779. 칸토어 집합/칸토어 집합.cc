#include<iostream>
#include<string>
using namespace std;

string ans;

void func(int start_loc, int N){
    if(N==0)return;
    int tn = 1;
    for(int i=0;i<N-1;i++){
        tn*=3;
    }
    for(int i=start_loc+tn;i<start_loc+tn*2;i++){
        ans[i] = ' ';
    }
    func(start_loc, N-1);
    func(start_loc+tn*2, N-1);
}

int main(){
    int n;
    while(cin>>n){
        ans = "";
        int tn = 1;
        for(int i=0;i<n;i++){
            tn*=3;
        }
        for(int i=0;i<tn;i++){
            ans+='-';
        }
        func(0, n);
        cout<<ans<<'\n';
    }
}