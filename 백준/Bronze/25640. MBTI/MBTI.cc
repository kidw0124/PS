#include<stdio.h>
#include<string.h>

int main(){
    int i,j;
    char mbti[5];
    char mbti2[5];
    scanf("%s",mbti);
    int n,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",mbti2);
        if(strcmp(mbti,mbti2)==0){
            ans++;
        }
    }
    printf("%d\n",ans);
}