#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

bool isQueue(vector<int> push,vector<int> pop ,int n){
    int sh = 0,op = 0;
    stack<int> s;
    while(sh < n){
        s.push(push[sh]);
        // cout << push[sh] << "入栈"<<endl;
        while(op < n && s.top() == pop[op]){
            
            s.pop();
            op++;
        }
        sh++;
    }
    if(op != n) return false;
    return true;
}

int main(){
    int q,num,n;
    cin >> q;
    vector<pair<vector<int>,vector<int>>> Nums;
    vector<int> nNums;

    for(int i = 0;i < q;i++){
        cin >> n;
        vector<int> push(n,0);
        vector<int> pop(n,0);
        for(int j = 0;j < n;j++){
            cin >> num;
            push[j] = num;
        }
        for(int j = 0;j < n;j++){
            cin >> num;
            pop[j] = num;
        }
        Nums.push_back({push,pop});
        nNums.push_back(n);
    }

    for(int i = 0;i < q;i++){
        if(isQueue(Nums[i].first,Nums[i].second,nNums[i]))cout << "Yes"<<endl;
        else cout << "No" <<endl;
    }
    return 0;
}