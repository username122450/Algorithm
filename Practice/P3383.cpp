#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

int main(){
    int n,q,num;
    cin >> n >> q;
    ios::sync_with_stdio(0);
    vector< int > indexs(q),flag(n+1,0);
    for(int i = 0;i < q;i++){
        cin >> num;
        indexs[i] = num;
    }
    int sum = 0,x;
    flag[0] = flag[1] = 1;
    for(int i = 2;i <= n;i++){
        if(flag[i] == 0){
            sum++;
            flag[sum] = i;//这里借用flag的前sum个位置保存质数,
                          //因为sum一定小于i且i只在遍历的时候有用,
                          //用完后前面的数据就没用了
        }
        for(int j = 1;j <=sum;j++){
            x = i * flag[j];
            if(x > n) break;
            flag[x] = 1;
            if(i % flag[j] == 0) break;
        }
    }

    for(int i = 0;i<q;i++){
        cout << flag[indexs[i]] << "\n";
    }

    return 0;
}