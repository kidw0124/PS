#include<bits/stdc++.h>
using namespace std;

int func(int a, int b, int c){
    return a*3+b*20+c*120;
}
int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    if(func(a,b,c)>func(d,e,f)){
        cout<<"Max";
    }
    else if(func(a,b,c)<func(d,e,f)){
        cout<<"Mel";
    }
    else cout<<"Draw";
}