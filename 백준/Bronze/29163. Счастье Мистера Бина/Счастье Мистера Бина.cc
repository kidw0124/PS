#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    cin>>n;
    int arr[2]={};
    while(n--){
        cin>>a;
        arr[a&1]++;
    }
    if(arr[0]>arr[1])cout<<"Happy";
    else cout<<"Sad";
}