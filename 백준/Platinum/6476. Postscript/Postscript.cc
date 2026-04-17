#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

#define debug if constexpr (xdebug) cout << "[DEBUG] "

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif


void solve(ll testcase){
    ll i,j;
    string op;
    vector<string> arr(1000,string(1000,'.'));
    vector<vector<string>>letters(128,vector<string>(5));
    /*
.***..  ****..  .****.  ****..  *****.  *****.  .****.  *...*.  *****.
*...*.  *...*.  *...*.  *...*.  *.....  *.....  *.....  *...*.  ..*...
*****.  ****..  *.....  *...*.  ***...  ***...  *..**.  *****.  ..*...
*...*.  *...*.  *.....  *...*.  *.....  *.....  *...*.  *...*.  ..*...
*...*.  ****..  .****.  ****..  *****.  *.....  .***..  *...*.  *****.
  A       B       C       D       E       F       G       H       I

..***.  *...*.  *.....  *...*.  *...*.  .***..  ****..  .***..  ****..
...*..  *..*..  *.....  **.**.  **..*.  *...*.  *...*.  *...*.  *...*.
...*..  ***...  *.....  *.*.*.  *.*.*.  *...*.  ****..  *...*.  ****..
*..*..  *..*..  *.....  *...*.  *..**.  *...*.  *.....  *..**.  *..*..
.**...  *...*.  *****.  *...*.  *...*.  .***..  *.....  .****.  *...*.
  J       K       L       M       N       O       P       Q       R

.****.  *****.  *...*.  *...*.  *...*.  *...*.  *...*.  *****.  ......
*.....  *.*.*.  *...*.  *...*.  *...*.  .*.*..  .*.*..  ...*..  ......
.***..  ..*...  *...*.  .*.*..  *.*.*.  ..*...  ..*...  ..*...  ......
....*.  ..*...  *...*.  .*.*..  **.**.  .*.*..  ..*...  .*....  ......
****..  .***..  .***..  ..*...  *...*.  *...*.  ..*...  *****.  ......
  S       T       U       V       W       X       Y       Z     blank
 */
    // 주석하고 똑같이 만들어줘
    letters['A']={".***..",
                  "*...*.",
                  "*****.",
                  "*...*.",
                  "*...*."};
    letters['B']={  "****..",
                  "*...*.",
                  "****..",
                  "*...*.",
                  "****.."};
    letters['C']={  ".****.",
                    "*...*.",
                    "*.....",
                    "*.....",
                    ".****."};
    letters['D']={"****..",
                    "*...*.",
                    "*...*.",
                    "*...*.",
                    "****.."};
    letters['E']={"*****.",
                    "*.....",
                    "***...",
                    "*.....",
                    "*****."};
    letters['F']={"*****.",
                    "*.....",
                    "***...",
                    "*.....",
                    "*....."};
    letters['G']={".****.",
                    "*.....",
                    "*..**.",
                    "*...*.",
                    ".***.."};
    letters['H']={"*...*.",
                    "*...*.",
                    "*****.",
                    "*...*.",
                    "*...*."};
    letters['I']={"*****.",
                    "..*...",
                    "..*...",
                    "..*...",
                    "*****."};
    letters['J']={"..***.",
                    "...*..",
                    "...*..",
                    "*..*..",
                    ".**..."};
    letters['K']={"*...*.",
                    "*..*..",
                    "***...",
                    "*..*..",
                    "*...*."};
    letters['L']={"*.....",
                    "*.....",
                    "*.....",
                    "*.....",
                    "*****."};
    letters['M']={"*...*.",
                    "**.**.",
                    "*.*.*.",
                    "*...*.",
                    "*...*."};
    letters['N']={"*...*.",
                    "**..*.",
                    "*.*.*.",
                    "*..**.",
                    "*...*."};
    letters['O']={".***..",
                    "*...*.",
                    "*...*.",
                    "*...*.",
                    ".***.."};
    letters['P']={"****..",
                    "*...*.",
                    "****..",
                    "*.....",
                    "*....."};
    letters['Q']={".***..",
                    "*...*.",
                    "*...*.",
                    "*..**.",
                    ".****."};
    letters['R']=  {"****..",
                    "*...*.",
                    "****..",
                    "*..*..",
                    "*...*."};
    letters['S']={".****.",
                    "*.....",
                    ".***..",
                    "....*.",
                    "****.."};
    letters['T']={"*****.",
                    "*.*.*.",
                    "..*...",
                    "..*...",
                    ".***.."};
    letters['U']={"*...*.",
                    "*...*.",
                    "*...*.",
                    "*...*.",
                    ".***.."};
    letters['V']={"*...*.",
                    "*...*.",
                    "*...*.",
                    ".*.*..",
                    "..*..."};
    letters['W']={"*...*.",
                    "*...*.",
                    "*.*.*.",
                    "**.**.",
                    "*...*."};
    letters['X']={"*...*.",
                    ".*.*..",
                    "..*...",
                    ".*.*..",
                    "*...*."};
    letters['Y']={"*...*.",
                    ".*.*..",
                    "..*...",
                    "..*...",
                    "..*..."};
    letters['Z']={"*****.",
                    "...*..",
                    "..*...",
                    ".*....",
                    "*****."};
    letters['.']={"......",
                    "......",
                    "......",
                    "......",
                    "......"};
    while(getline(cin,op)){
        if(op==".EOP"){
            for(i=0;i<60;i++)cout<<arr[i].substr(0,60)<<'\n';
            cout<<'\n'<<string(60,'-')<<'\n'<<'\n';
            arr=vector<string>(60,string(60,'.'));
        }
        else{
            stringstream ss(op);
            string ope,font,str(1000,'\0');
            ll r,c;
            ss>>ope>>font>>r;
            if(ope==".P")ss>>c;
            ss.getline((char*)str.c_str(),1000);
            r--,c--;
            str=str.substr(0,str.find_last_not_of('\0')+1);
            str.pop_back();
            str=str.substr(1);
            while(str.find(' ')!=string::npos){
                str.replace(str.find(' '),1,".");
            }
            while(str.find('|')!=string::npos){
                str.erase(str.find('|'),1);
            }
            vector<string> over;
            if(font=="C5"){
                over.resize(5);
                for(i=0;i<5;i++){
                    for(auto k:str){
                        over[i]+=letters[k][i];
                    }
                }
            }
            else{
                over={str};
            }
            ll x=r,y;
            if(ope==".L"){
                y=0;
            }
            else if(ope==".R"){
                y=60-(ll)over[0].size();
            }
            else if(ope==".C"){
                y=floor((60-(ll)over[0].size()+1)/2.0);
            }
            else{
                y=c;
            }
            for(i=0;i<over.size();i++){
                for(j=0;j<over[i].size();j++){
                    if(over[i][j]!='.' && x+i<60 && y+j<60 && x+i>=0 && y+j>=0){
                        arr[x+i][y+j]=over[i][j];
                    }
                }
            }
        }

    }
}

int main(){

#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t st = clock();
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int t = 1;
//    cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    clock_t ed = clock();
#ifdef kidw0124
    clock_t en = clock();
    cout << "Time: " << (double)(en - st) / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}
