#include <stdio.h>
#include <string.h>

int main(){
/* A tesoura corta o papel;
O papel embrulha a pedra;
A pedra esmaga o lagarto;
O lagarto envenena Spock;
Spock destrói a tesoura;
A tesoura decapita o lagarto;
O lagarto come o papel;
O papel contesta Spock;
Spock vaporiza a pedra;
A pedra quebra a tesoura. */

    char sheldon[10], raj[10];

    scanf("%s %s", sheldon, raj);

    if(strcmp(sheldon, raj) == 0){
        printf("De novo!\n");
    } else if(strcmp(sheldon, "tesoura")== 0 && strcmp(raj, "papel") == 0){
        printf("Bazinga!\n");
    } else if(strcmp(sheldon, "papel")== 0 && strcmp(raj, "pedra") == 0){
        printf("Bazinga!\n");
    } else if(strcmp(sheldon, "pedra")== 0 && strcmp(raj, "lagarto") == 0){
        printf("Bazinga!\n");
    } else if(strcmp(sheldon, "lagarto")== 0 && strcmp(raj, "Spock") == 0){
        printf("Bazinga!\n");
    } else if(strcmp(sheldon, "Spock")== 0 && strcmp(raj, "tesoura") == 0){
        printf("Bazinga!\n");
    } else if(strcmp(sheldon, "tesoura")== 0 && strcmp(raj, "lagarto") == 0){
        printf("Bazinga!\n");
    } else if(strcmp(sheldon, "lagarto")== 0 && strcmp(raj, "papel") == 0){
        printf("Bazinga!\n");
    } else if(strcmp(sheldon, "papel")== 0 && strcmp(raj, "Spock") == 0){
        printf("Bazinga!\n");
    } else if(strcmp(sheldon, "Spock")== 0 && strcmp(raj, "pedra") == 0){
        printf("Bazinga!\n");
    } else if(strcmp(sheldon, "pedra")== 0 && strcmp(raj, "tesoura") == 0){
        printf("Bazinga!\n");
    } else {
        printf("Raj trapaceou!\n");
    }

    return 0;
}