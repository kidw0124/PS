#include <iostream>

int main() {
    char buf[256];
    int happy = 0, sad = 0;
    
    fgets(buf, 256, stdin);
    
    for (int i = 0; buf[i + 2] != '\0'; ++i) {
        if (buf[i] == ':' && buf[i + 1] == '-') {
            if (buf[i + 2] == ')') {
                ++happy;
            }
            else if (buf[i + 2] == '(') {
                ++sad;
            }
            else;
        }
    }
    
    if (happy == sad) {
        printf("%s", (happy == 0) ? "none" : "unsure");
    }
    else if (happy > sad) {
        printf("happy");
    }
    else {
        printf("sad");
    }
    
    return 0;
}