#include<bits/stdc++.h>

int main(){
    int i,j;
    char str[105];
    scanf("%s",str);
    int len = strlen(str);
    for(i=0;i<len;i++){
        if(islower(str[i])){
            str[i]=toupper(str[i]);
        }
        else if(isupper(str[i])){
            str[i]=tolower(str[i]);
        }
    }
    printf("%s",str);
}