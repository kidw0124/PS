#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[100'000+5];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int st=0,en=n-1;
        int x;
        cin>>x;
        while(st<=en){
            int mid = (st+en)/2;
            if(arr[mid]<x){
                st=mid+1;
            }
            else if(arr[mid]>x){
                en=mid-1;
            }
            else{
                cout<<1<<'\n';
                break;
            }
        }
        if(st>en){
            cout<<0<<'\n';
        }
    }
    
}