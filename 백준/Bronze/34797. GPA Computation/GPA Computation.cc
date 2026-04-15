#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    char c;
    double x=0;
    cin>>n;
    int m=n;
    while(n--){
        int y=0;
        cin>>c>>y;
        x+=4+'A'-c;
        if(c<'D'){
            if(y==1)x+=0.05*m;
            if(y==2)x+=0.025*m;
        }
    }
    cout<<setprecision(10)<<fixed<<x/m;
    
}