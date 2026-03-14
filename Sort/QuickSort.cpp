#include<iostream>
#include<vector>
#define nul -1
using namespace std;
vector< int > nums;
int listNum;

void sort(int l,int r){
    if(l >= r)return ;
    int t = nums[l];
    int i = l,j = r;
    while(i<j){
        while(i<j && nums[j]>=t)j--;//找到第一个比t小的数的下标
        if(i<j){
            nums[i] = nums[j];//i位置的数已经保存,将j位置的数放在基准值的左边
        }
        while(i<j && nums[i]<= t)i++;
        if(i<j){
            nums[j] = nums[i];
        }
    }
    nums[i] = t;//此时i=j将t放在这个找到的正确位置
    sort(l,i-1);
    sort(i+1,r);
}

int main(){
    cin >> listNum;
    int num;
    for(int i = 0;i < listNum;i++){
        cin >> num;
        nums.push_back(num);
    }

    sort(0,listNum-1);

    vector< int >::iterator it = nums.begin();
    for(int i = 0;i<listNum;i++){
        cout << *(it+i) << " ";
    }
    cout << endl;

    return 0;
}

/*
7
19 10 43 76 50 20 3
*/