#include<iostream>
#include<string>
using namespace std;

int arr[200][200];
int white=0,blue=0;

void color_paper(int x, int y, int n){
    bool check = true;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[x+i][y+j]!=arr[x][y]){
                check = false;
                //break;
            }
        }
        //if(!check) break;
    }
    if(check){
        if(arr[x][y]==0) white++;
        else blue++;
    }
    else{
        color_paper(x,y,n/2);
        color_paper(x+n/2,y,n/2);
        color_paper(x,y+n/2,n/2);
        color_paper(x+n/2,y+n/2,n/2);
    }

}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    color_paper(0,0,n);
    cout<<white<<endl;
    cout<<blue<<endl;
    
}