#include <stdio.h>
#include <string.h>

int main() {
    
    char s[110];
    scanf("%s", s);

    if (strstr(s, "nnsz")) puts("yes");
    else puts("no");

    return 0;
}
