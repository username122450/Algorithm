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

    int p = listNum/2;

    while(p >= 1){
        for(int i = p;i < listNum; i++){
            int t = nums[i],j;
            for(j = i-p;j >=0;j-=p){
                if(nums[j]>nums[j+p]){
                    swap(j,j+p);
                }else break;
            }
            nums[j+p] = t;
        }
        p/=2;
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