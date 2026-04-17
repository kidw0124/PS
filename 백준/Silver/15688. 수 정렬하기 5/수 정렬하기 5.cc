#include<bits/stdc++.h>
using namespace std;
int n;
int arr[5000000];
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",arr+i);
    sort(arr,arr+n);
    for(i=0;i<n;i++)printf("%d\n",arr[i]);
}
