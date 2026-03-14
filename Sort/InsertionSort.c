#include<stdio.h>
#include<stdlib.h>
#define nul -1
int *nums;
int listNum;

void swap(int i,int j){
    int temp = nums[i];
    nums[i]= nums[j];
    nums[j] = temp;
}

int main(){
    nums = (int *)malloc(sizeof(int) * 15);
    for(int i = 0;i < 15;i++){
        nums[i] = nul;
    }
    scanf(" %d",&listNum);
    for(int i = 0;i < listNum;i++){
        scanf(" %d",&nums[i]);
    }

    for(int i = 1; i < listNum;i++){
        int temp = nums[i];
        int j ;
        for(j = i-1; j >= 0;j--){
            if(nums[j+1] < nums[j] ){
                swap(j+1,j);
            }else break;
        }
        nums[j+1] = temp;
    }
    
    for(int i = 0 ;i  < listNum;i++){
        printf("%d ",nums[i]);
    }
    
    return 0;
}

/*
7
19 10 43 76 50 20 3
*/