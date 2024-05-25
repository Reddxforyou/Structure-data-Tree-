#include <stdio.h>
#include <string.h>
#include <ctype.h>  
#include <stdlib.h>



int main(){
    char str[] = "sskdjskdjskd";
    printf("Before: %s\n", str);
    printf("\033[31m\033[9m%s\033[0m\033[0m\n", str);
    printf("\033[35mRed crossed-out text\033[0m\n"); // Red text with strike-through
    printf("\033[31mRed text\033[0m\n"); // Red text

    return 0;

}