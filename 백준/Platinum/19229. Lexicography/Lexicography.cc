#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int n, m, k, cnt[26], i, j, start, where, check[1010][1010];
string c;
char res[1010][1010];
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    cin>>c;
    for(i=0;i<n*m;i++){
        cnt[c[i]-'a']++;
    }
    for(i=0;i<m;i++){
        for(j=start;j<k;j++){
            while(cnt[where]==0)where++;
            res[j][i]=where+'a';
            check[j][i]=1;
            cnt[where]--;
            if(cnt[where]==0){
                if(j!=k-1)start=j+1;
            }
        }
    }
    where=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            while(cnt[where]==0)where++;
            if(check[i][j]==0){
                res[i][j]=where+'a';
                cnt[where]--;
            }
            printf("%c", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
