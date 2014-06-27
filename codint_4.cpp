#include <stdio.h>

//replace all spaces with %20

void shiftStr(char str[]){
    int i=0;
    //goto end plus 2
    for(i = 0; str[i] != '\0'; i++){
    }
    i=i+2;
    for(;i>1; i--){
        //printf("str[%d] =  %c and str[%d ] = %c  \n",i,str[i],i-2,str[i-2]);
        str[i]=str[i-2];
    }
}

void replace(char str[]){
    int i=0;
    for(i = 0; str[i] != '\0'; i++){
        //printf("inside for %c \n",str[i]);
        if(str[i] == ' '){
            //printf("replacing\n");
            shiftStr(str+i);
            str[i]='%';
            str[i+1]='2';
            str[i+2]='20';
            i=i+2;
        }
    }
}

int main(){
    char str[200]="My name is Mr. Smith";

    printf("Before %s \n",str);
    replace(str);
    //shiftStr(str);
    printf("After %s \n",str);
}
