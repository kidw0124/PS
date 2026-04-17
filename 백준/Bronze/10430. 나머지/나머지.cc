#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C;
    cin>>A>>B>>C;
    cout<<(A+B)%C<<endl<<(A%C+B%C)%C<<endl<<(A*B)%C<<endl<<((A%C)*(B%C))%C;
}