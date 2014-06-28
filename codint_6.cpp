#include <stdio.h>
//9 degrees array swap

int printArr(int arr[3][3],int n){
    int i = 0 ;
    int j = 0 ;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int swap90degreeArr(int arr[3][3],int n){
    int i = 0 ;
    int j = 0 ;
    int temp =0;
    int j90=0;
    int i90=n-1;
    int newArr[3][3];
    for(i=n-1;i>=0;i--){
        //j90=0;
        i90=n-1;
        for(j=n-1;j>=0;j--){
            printf(" i = %d , j =%d arr= %d   i90 = %d j90 =%d arr = %d   \n",i,j,arr[i][j],i90,j90,arr[i90][j90]);
            temp=arr[i][j];
            arr[i][j] = arr[i90][j90];
            arr[i90][j90]= temp;
            i90--;
        }
        j90++;
    }
}

int main(){
    int myarr[3][3]={
        {1,2,3,},
        {4,5,6,},
        {7,8,9,},
    };
    printf("before swap\n");
    printArr(myarr,3);

    swap90degreeArr(myarr,3);
    printf("\nafter swap\n");
    printArr(myarr,3);
    return 0;
}
