#include<bits/stdc++.h>
using namespace std;
int n;
int arr[10001]={0};
int main(){
    int i,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&temp);
        arr[temp]++;
    }
    for(i=0;i<10001;i++)
        for(int j=0;j<arr[i];j++)
            printf("%d\n",i);
}
