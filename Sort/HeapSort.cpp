#include<iostream>
#include<vector>
#define nul -1
using namespace std;
vector< int > nums;
int listNum;

//这里构建小顶堆
void swap(int i,int j){
    int temp = nums[i];
    nums[i]= nums[j];
    nums[j] = temp;
}

void upAdjust(int i){//向上调整,维护小顶堆
    int fa ;
    while(i/2 >= 1){
        fa = i/2;
        if(nums[fa] > nums[i]){//如果有父节点比子节点大,就交换
            swap(fa,i);
            i = fa;
        }else break;
    }
}

void downAdjust(int i,int size){
    int ch;
    while(i*2 <= size){
        ch = i*2;
        if(ch+1 < size && nums[ch] > nums[ch+1]) ch++;
        if(nums[ch] < nums[i]){
            swap(ch,i);
            i = ch;
        }else break;
    }
}

int main(){
    cin >> listNum;
    nums.push_back(nul);//这里用数组保存二叉树必须保证下标从1开始,首位用-1占位
    int num;
    for(int i = 1;i <= listNum;i++){
        cin >> num;
        nums.push_back(num);
        upAdjust(i);//边插入边维护
    }

    for(int i = listNum;i >= 1;i--){
        cout << nums[1] << " ";
        swap(1,i);
        downAdjust(1,i-1);
    }
    cout << endl;
    return 0;
}
/*
7
19 10 43 76 50 20 3
*/