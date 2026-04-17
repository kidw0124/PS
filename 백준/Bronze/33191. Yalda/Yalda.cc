#include<bits/stdc++.h>
using namespace std;
int main(){
    string arr[]={"Watermelon",
                  "Pomegranates",
                  "Nuts",
                  "Nothing"};
    int n,m,a=0;
    cin>>n;
    while(cin>>m){if(n>=m)break;a++;}
    cout<<arr[a];
}