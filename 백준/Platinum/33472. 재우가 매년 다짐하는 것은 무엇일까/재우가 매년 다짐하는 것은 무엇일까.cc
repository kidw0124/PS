#include<bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int>factor(10'000);

void preprocess(){
    int i,j;
    for(i=2;i<10'000;i++){
        if(!factor[i]){
            for(j=i*2;j<10'000;j+=i){
                factor[j]=i;
            }
        }
    }
}

void solve(){
    int i,j;
    vector<int>arr(10);
    auto divide=[](const string&org, int base){
        string str;
        int bias=0;
        for(auto k:org){
            int tmp=bias*10+k-'0';
            if(str.size()||tmp/base){
                str+=tmp/base+'0';
            }
            bias=tmp%base;
        }
        assert(bias==0);
        return str;
    };
    auto type_1_5=[&divide](vector<pair<int,int>>&v){
        string str;
        vector<string>rem(7);
        for(int i=0;i<5;i++){
            str+=v[3].second+'0';
            v[3].first--;
        }
        str+=v[3].second+'0';
        rem[stoi(str)%7]=str;
        str.back()=v[2].second+'0';
        v[2].first--;
        sort(str.begin(),str.end());
        do{
            rem[stoi(str)%7]=str;
        }while(next_permutation(str.begin(),str.end()));
        for(int i=0;i<7;i++){
            assert(rem[i]!="");
        }
        string str2;
        int rr=0;
        for(auto [cnt,k]:v){
            for(int i=0;i<cnt;i++){
                rr=(rr*10+k)%7;
                str2+=k+'0';
            }
        }
        rr=rr*1'000'000%7;
        rr=(7-rr)%7;
        str2+=rem[rr];
        string q=divide(str2,7);
        cout<<str2<<" = 7 X "<<q<<'\n';
    };
    auto type_2_3=[&divide](vector<pair<int,int>>&v){
        string str;
        for(int i=0;i<2;i++){
            str+=v[2].second+'0';
            v[2].first--;
        }
        for(int i=0;i<3;i++){
            str+=v[3].second+'0';
            v[3].first--;
        }
        sort(str.begin(),str.end());
        vector<string>rem(7);
        do{
            rem[stoi(str)%7]=str;
        }while(next_permutation(str.begin(),str.end()));
        for(int i=0;i<7;i++){
            assert(rem[i]!="");
        }
        string str2;
        int rr=0;
        for(auto [cnt,k]:v){
            for(int i=0;i<cnt;i++){
                rr=(rr*10+k)%7;
                str2+=k+'0';
            }
        }
        rr=rr*100'000%7;
        rr=(7-rr)%7;
        str2+=rem[rr];
        string q=divide(str2,7);
        cout<<str2<<" = 7 X "<<q<<'\n';
    };
    auto type_1_2_2=[&divide](vector<pair<int,int>>&v){
        string str;
        for(int i=0;i<1;i++){
            str+=v[1].second+'0';
            v[1].first--;
        }
        for(int i=0;i<2;i++){
            str+=v[2].second+'0';
            v[2].first--;
        }
        for(int i=0;i<2;i++){
            str+=v[3].second+'0';
            v[3].first--;
        }
        sort(str.begin(),str.end());
        vector<string>rem(7);
        do{
            rem[stoi(str)%7]=str;
        }while(next_permutation(str.begin(),str.end()));
        for(int i=0;i<7;i++){
            assert(rem[i]!="");
        }
        string str2;
        int rr=0;
        for(auto [cnt,k]:v){
            for(int i=0;i<cnt;i++){
                rr=(rr*10+k)%7;
                str2+=k+'0';
            }
        }
        rr=rr*100'000%7;
        rr=(7-rr)%7;
        str2+=rem[rr];
        string q=divide(str2,7);
        cout<<str2<<" = 7 X "<<q<<'\n';
    };
    auto type_5=[](vector<pair<int,int>>&v){
        string str(5,v[3].second+'0');
        cout<<string(5,v[3].second+'0')<<" = 41 X "<<271*v[3].second<<'\n';
    };
    auto type_3=[](vector<pair<int,int>>&v){
        string str(3,v[3].second+'0');
        cout<<string(3,v[3].second+'0')<<" = 3 X "<<37*v[3].second<<'\n';
    };
    auto type_2=[](vector<pair<int,int>>&v){
        string str(2,v[3].second+'0');
        assert(v[3].second!=1);
        cout<<string(2,v[3].second+'0')<<" = 11 X "<<v[3].second<<'\n';
    };
    for(i=0;i<10;i++){
        cin>>arr[i];
    }
    if(arr[0] || arr[2] || arr[4] || arr[6] || arr[8]){
        string str;
        for(auto k:{1,3,5,7,9,2,4,6,8,0}){
            for(i=0;i<arr[k];i++){
                str+=k+'0';
            }
        }
        string q=divide(str,2);
        cout<<str<<" = 2 X "<<q<<'\n';
    }
    else if(arr[5]){
        string str;
        for(auto k:{1,3,7,9,5}){
            for(i=0;i<arr[k];i++){
                str+=k+'0';
            }
        }
        string q=divide(str,5);
        cout<<str<<" = 5 X "<<q<<'\n';
    }
    else{
        vector<pair<int,int>>v;
        vector<int>vs;
        int cnt=0;
        for(auto k:{1,3,7,9}){
            v.push_back({arr[k],k});
            vs.push_back(arr[k]);
            cnt+=arr[k];
        }
        sort(v.begin(),v.end());
        sort(vs.begin(),vs.end());
        // 1 1 1 1
        // 0 1 1 2
        // 0 1 1 1
        // 0 0 2 2
        // 0 0 1 3
        if(v[3].first>=5){
            // * * * 5+
            type_1_5(v);
        }
        else if(v[2].first>=2 && v[3].first>=3){
            // * * 2+ 3+
            type_2_3(v);
        }
        else if(v[1].first>=1 && v[2].first>=2 && v[3].first>=2){
            // * 1+ 2+ 2+
            type_1_2_2(v);
        }
        else if(v[1].first>=1 && v[3].first>=3){
            // * 1+ 1+ 3+
            v[1].first--;
            v[2].first++;
            type_2_3(v);
        }
        else if(vs==vector{1,1,1,2}){
            // 1 1 1 2
            v[0].first--;
            v[2].first++;
            type_1_2_2(v);
        }
        else if(vs==vector{0,0,1,4}){
            // 0 0 1 4
            v[2].first--;
            v[3].first++;
            type_5(v);
        }
        else if(vs==vector{0,0,1,2}){
            // 0 0 1 2
            v[2].first--;
            v[3].first++;
            type_3(v);
        }
        else if(vs==vector{0,0,1,1}){
            // 0 0 1 1
            v[2].first--;
            v[3].first++;
            type_2(v);
        }
        else{
            assert(cnt<=4);
            string str;
            for(auto [cnt,k]:v){
                for(i=0;i<cnt;i++){
                    str+=k+'0';
                }
            }
            sort(str.begin(),str.end());
            do{
                int now=stoi(str);
                if(factor[now]){
                    cout<<str<<" = "<<factor[now]<<" X "<<now/factor[now]<<'\n';
                    break;
                }
            }while(next_permutation(str.begin(),str.end()));
        }
    }
}

int main(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}