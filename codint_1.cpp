#include <stdio.h>

int checkUniqueChar(char myChar, char *arr,int size){
    int i = 0;
    while(*arr != '\0'){
        if(*arr == myChar)
            return 0;

        arr++;
    }
    *arr=myChar;
    return 1;
}

int isUnique(char *str, int size){
    char arr[size];
    int i=0;
    int check = 0;

    for(i=0 ; i < size ; i++){
        arr[i]='\0';
    }

    while(*str != '\0'){
        check = checkUniqueChar(*str,arr,size);
        if(check != 1){
            return 0;
        }
        str++;
    }

    return 1;
}

int main(){
    char mystr[] = "1234abc5678900";
    int size = sizeof(mystr)/sizeof(*mystr)-1;
    printf("size of char is %d \n",size);

    if ( isUnique(mystr, size) )
        printf("%s has all unique characters \n", mystr);
    else
        printf("%s doesn't have all unique characters \n",mystr);

  
    return 0;
}
