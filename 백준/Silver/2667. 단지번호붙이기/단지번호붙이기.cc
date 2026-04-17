#include<bits/stdc++.h>
using namespace std;
#define visit vvissit
int n;
int arr[30][30];
stack<pair<int,int> >s;
int visit[30][30];
vector<int>pq;
 
void func(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(arr[i][j]&&!visit[i][j]){
                while(!s.empty())s.pop();
                int c=1;
                visit[i][j]=1;
                if(arr[i+1][j]&&!visit[i+1][j])s.push(make_pair(i+1,j));
                if(arr[i-1][j]&&!visit[i-1][j])s.push(make_pair(i-1,j));
                if(arr[i][j+1]&&!visit[i][j+1])s.push(make_pair(i,j+1));
                if(arr[i][j-1]&&!visit[i][j-1])s.push(make_pair(i,j-1));
                while(!s.empty()){
                    pair<int,int> pp=s.top();
                    s.pop();
                    if(visit[pp.first][pp.second])continue;
                    visit[pp.first][pp.second]=1;
                    c++;
                    if(arr[pp.first+1][pp.second]&&!visit[pp.first+1][pp.second])s.push(make_pair(pp.first+1,pp.second));
                    if(arr[pp.first-1][pp.second]&&!visit[pp.first-1][pp.second])s.push(make_pair(pp.first-1,pp.second));
                    if(arr[pp.first][pp.second+1]&&!visit[pp.first][pp.second+1])s.push(make_pair(pp.first,pp.second+1));
                    if(arr[pp.first][pp.second-1]&&!visit[pp.first][pp.second-1])s.push(make_pair(pp.first,pp.second-1));
                }
                pq.push_back(c);
            }
        }
    }
}
 
int main(){
    cin>>n;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%1d",&arr[i+1][j+1]);
        }
    }
    func();
    cout<<pq.size()<<'\n';
    sort(pq.begin(),pq.end());
    for(i=0;i<pq.size();i++){
        cout<<pq[i]<<'\n';
    }
}