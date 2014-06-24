#include <stdio.h>

//Given the problem requirements, one string is a permutation of
//the other if this 2 conditions are met :
//- has the exact same characters
//- the characters are in different order.

//One way to do it is to sort the 2 strings first and then compare
//them

int getSize(char *str){
    int size = 0;

    while(*str++ != '\0')
        size++;
    return size;
}

int isStringDifferent(char *str1,char *str2){
    while(*str1 != '\0' ){
        if(*str1 != *str2)
            return 1;
        str1++;
        str2++;
    }

    return 0;
}

int sortString(char str[]){
    int i=0;
    int j=0;
    int count=0;
    char tmp;
//    char str[]="543125";
    //printf("Before sort %s \n",str);
    for(i=0;str[i+1] != '\0'; i++){
        for(j=0;str[j+1] != '\0'; j++){
            if(str[j] > str[j+1]){
                //swap
                tmp=str[j];
                str[j]=str[j+1];
                str[j+1]=tmp;
            }
        }
    }
    //printf("After sort %s \n",str);
}

int isPermutation(char * str1, char * str2){
    int size1=getSize(str1);
    int size2=getSize(str2);

    //checking first requirement
    if(size1 != size2){
        printf("Sizes of strings differ, no chance of permutation \n");
        return 0;
    }

    //Once this requirement has been fullfilled, check that they are different
    if(!isStringDifferent(str1,str2)){
        printf("Strings are exactly same, so no permutation\n");
        return 0;
    }

    sortString(str1);
    sortString(str2);

    return !isStringDifferent(str1,str2);

}


int main(){

    char str1[] = "123654Hello";
    char str2[] = "5H4l1e2l3o6";

    printf("Comparing %s against %s \n",str1,str2);
    if(isPermutation(str1,str2)){
        printf(" is a permutation  \n");
    }else{
        printf(" is NOT a permutation  \n");
    }

    return 0;

}
