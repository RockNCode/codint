#include <stdio.h>

void reverse(char *str){
    int i = 0;
    char temp;
    char *end = str;
    while(*end++){
        i++;
    }

    end--;
    while( str < end ){
        temp = *str;
        *str++ = *end;
        *end-- = temp;    
    }

}

int main(){
    char str[] = "anitalavalatina";

    printf("Before reverse = %s \n",str);

    reverse(str);

    printf("After reverse = %s \n",str);

    return 0;
}
