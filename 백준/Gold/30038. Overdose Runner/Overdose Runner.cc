#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll=pair<ll,ll>;
using tlll=tuple<ll,ll,ll>;


int main(){
    #ifdef kidw0124
//    freopen("input.txt","r",stdin);
    #endif // kidw0124
    ll i,j,k;
    ll n,m,r,c,px,py;
    bool lock=0;
    ll exp=0,atk=5,rad=1,p=1,need=10,lev=1,ovr=0;
    ll h=0,hh=0;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    map<pll,tlll>monster;
    vector<string>command;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='m')monster[{i,j}]={0,0,0};
        }
        for(j=0;j<m;j++){
            if(arr[i][j]=='p'){
                px=i,py=j;
                arr[i][j]='.';
            }
        }
    }
    cin>>r;
    for(auto&[a,b]:monster){
        cin>>get<0>(b);
    }
    for(auto&[a,b]:monster){
        cin>>get<1>(b);
    }
    for(auto&[a,b]:monster){
        cin>>get<2>(b);
    }
    cin>>c;
    command.resize(c);
    for(i=0;i<c;i++){
        cin>>command[i];
        if(command[i]=="u"){
            ll nx=px-p,ny=py;
            if(nx<0||ny<0||nx>=n||ny>=m||arr[nx][ny]=='m'||arr[nx][ny]=='*')continue;
            h++,hh++;
            px=nx,py=ny;
        }
        else if(command[i]=="d"){
            ll nx=px+p,ny=py;
            if(nx<0||ny<0||nx>=n||ny>=m||arr[nx][ny]=='m'||arr[nx][ny]=='*')continue;
            h++,hh++;
            px=nx,py=ny;
        }
        else if(command[i]=="l"){
            ll nx=px,ny=py-p;
            if(nx<0||ny<0||nx>=n||ny>=m||arr[nx][ny]=='m'||arr[nx][ny]=='*')continue;
            h++,hh++;
            px=nx,py=ny;
        }
        else if(command[i]=="r"){
            ll nx=px,ny=py+p;
            if(nx<0||ny<0||nx>=n||ny>=m||arr[nx][ny]=='m'||arr[nx][ny]=='*')continue;
            h++,hh++;
            px=nx,py=ny;
        }
        else if(command[i]=="w"){
            h++,hh++;
        }
        else if(command[i]=="au"){
            if(lock)continue;
            ll nx=px,ny=py;
            for(j=0;j<rad;j++){
                nx--;
                if(nx<0||ny<0||nx>=n||ny>=m||arr[nx][ny]=='*')break;
                if(arr[nx][ny]=='m'){
                    ll d=atk-get<1>(monster[{nx,ny}]);
                    if(d<0)continue;
                    get<0>(monster[{nx,ny}])-=d;
                    if(get<0>(monster[{nx,ny}])<=0){
                        arr[nx][ny]='.';
                        exp+=get<2>(monster[{nx,ny}]);
                    }
                }
            }
            h+=3;
        }
        else if(command[i]=="ad"){
            if(lock)continue;
            ll nx=px,ny=py;
            for(j=0;j<rad;j++){
                nx++;
                if(nx<0||ny<0||nx>=n||ny>=m||arr[nx][ny]=='*')break;
                if(arr[nx][ny]=='m'){
                    ll d=atk-get<1>(monster[{nx,ny}]);
                    if(d<0)continue;
                    get<0>(monster[{nx,ny}])-=d;
                    if(get<0>(monster[{nx,ny}])<=0){
                        arr[nx][ny]='.';
                        exp+=get<2>(monster[{nx,ny}]);
                    }
                }
            }
            h+=3;
        }
        else if(command[i]=="al"){
            if(lock)continue;
            ll nx=px,ny=py;
            for(j=0;j<rad;j++){
                ny--;
//                cout<<"[DEB] "<<nx<<' '<<ny<<'\n';
                if(nx<0||ny<0||nx>=n||ny>=m||arr[nx][ny]=='*')break;
                if(arr[nx][ny]=='m'){
                    ll d=atk-get<1>(monster[{nx,ny}]);
                    if(d<0)continue;
                    get<0>(monster[{nx,ny}])-=d;
//                    cout<<"[DEB] "<<nx<<' '<<ny<<' '<<d<<' '<<get<0>(monster[{nx,ny}])<<'\n';
                    if(get<0>(monster[{nx,ny}])<=0){
                        arr[nx][ny]='.';
                        exp+=get<2>(monster[{nx,ny}]);
                    }
                }
            }
            h+=3;
        }
        else if(command[i]=="ar"){
            if(lock)continue;
            ll nx=px,ny=py;
            for(j=0;j<rad;j++){
                ny++;
                if(nx<0||ny<0||nx>=n||ny>=m||arr[nx][ny]=='*')break;
                if(arr[nx][ny]=='m'){
                    ll d=atk-get<1>(monster[{nx,ny}]);
                    if(d<0)continue;
                    get<0>(monster[{nx,ny}])-=d;
//                    cout<<"[DEB] "<<nx<<' '<<ny<<' '<<d<<' '<<get<0>(monster[{nx,ny}])<<'\n';
                    if(get<0>(monster[{nx,ny}])<=0){
                        arr[nx][ny]='.';
                        exp+=get<2>(monster[{nx,ny}]);
                    }
                }
            }
            h+=3;
        }
        else if(command[i]=="du"){
            if(lock)continue;
            p++;
            h+=2;
            ovr++;
            if(ovr>=5){
                lock=1;
                ovr=0;
                hh=0;
            }
        }
        else if(command[i]=="dd"){
            if(lock)continue;
            if(p)p--;
            h+=2;
            ovr++;
            if(ovr>=5){
                lock=1;
                ovr=0;
                hh=0;
            }
        }
        else if(command[i]=="c"){
            if(lock)continue;
            if(arr[px][py]=='g'){
                cout<<lev<<' '<<exp<<'\n';
                cout<<h<<'\n';
                arr[px][py]='p';
                for(i=0;i<n;i++){
                    for(j=0;j<m;j++){
                        cout<<arr[i][j];
                    }
                    cout<<'\n';
                }
                for(auto [a,b]:monster){
                    if(get<0>(b)>0)cout<<get<0>(b)<<' ';
                }
                return 0;
            }
        }
        if(hh>=10){
            lock=0;
        }
        while(exp>=need){
            exp-=need;
            atk+=lev;
            rad++;
            lev++;
            need+=10;
        }
    }
    cout<<lev<<' '<<exp<<'\n';
    cout<<h<<'\n';
    arr[px][py]='p';
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
    for(auto [a,b]:monster){
        if(get<0>(b)>0)cout<<get<0>(b)<<' ';
    }
    return 0;
}
