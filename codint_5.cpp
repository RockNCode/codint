#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//String compression

int getSize(char *str){
    int size = 0;

    while(*str++ != '\0')
        size++;
    return size;
}

int countUntilDiff(char str[]){
    int count=0;
    int i=0;
    char cmp = str[0];
    for(i=0; str[i] == cmp ; i++){
        count++;
    }
    return count;
}

char* compress(char str[]){
    int i=0;
    int j=0;
    int diff=0;
    char* compressedString;
    int sizeInput = getSize(str);
    int sizeResult=0;
    //Worst case scenario, resulting string is double the size
    //of the input
    char rStr[sizeInput*2];
    int numwr=0;

    for(i=0; str[i] != '\0';i++){
        diff = countUntilDiff(str+i);
        if(diff > 0){
            rStr[j]=str[i];
            numwr= sprintf((rStr+j+1),"%d",diff); //We write the number of repeats
            i=i+diff-1;
            //printf("j before shift =%d numwr =%d \n",j,numwr);
            j=j+numwr;
            //printf("j after shift =%d \n",j);
        }
        j++;
    }

    sizeResult=getSize(rStr);
    if(sizeResult>sizeInput){
        compressedString = (char*)malloc(sizeInput*sizeof(char));
        strncpy(compressedString,str,sizeInput);
    }else{
        compressedString = (char*)malloc(sizeResult*sizeof(char));
        strncpy(compressedString,rStr,sizeResult);
    }

    return compressedString;

}

int main(){
    char str[]="aabcccccaaa";
    char* compressString = compress(str);
    //result should be a2b1c5a3
    printf("input string = %s compressed string = %s \n",str,compressString);
    free(compressString);
    return 0;
}
