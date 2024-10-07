#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    ll t;
    cin>>t;
    string line;
    getline(cin, line);
    for(int tc=0;tc<t;tc++){
        cout<<"Case #"<<tc+1<<": ";
        getline(cin, line); /// line="this is a test"
//        stringstream ss(line); /// ss=line
        stringstream ss;
        ss<<line; /// ss에 line을 출력(line->ss)
        vector<string> tokens;
        string str;
        while(ss>>str){ /// ss에 적혀있는걸 str으로 입력(ss->str)
            tokens.push_back(str);
        }
        reverse(tokens.begin(),tokens.end());
//        for(int i=0;i<tokens.size();i++){
//            cout<<tokens[i]<<" ";
//        }
        for(string v:tokens){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
}
