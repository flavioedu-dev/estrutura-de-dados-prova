#include <stdio.h>

void copiarString(char *ent, char *sai){
    while(*ent != '\0'){
        *sai = *ent;
        ++ent;
        ++sai;
    }
    *ent = '\0';
}

int main(){

    void copiarString(char *ent, char *sai);

    char str1[] = "Teste1";
    char str2[100];

    copiarString(str1,str2);
    printf("%s\n", str2);

    printf("Digite str1: ");
    scanf("%s", &str1);

    printf("Digite str2: ");
    scanf("%s", &str2);
;
    printf("str2: %s\n", str2);
    printf("str1: %s\n", str1);

    return 0;
}