#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int n,num;
    cin >> n;
    priority_queue< int ,vector<int> ,greater<int> > q;
    for(int i = 0;i < n;i++){
        cin >> num;
        q.push(num);

    }
    int sum = 0,temp;
    for(int i = 0;i < n-1;i++){
        temp = 0;
        num = q.top();
        sum+= num;
        temp+= num;
        q.pop();
        num = q.top();
        sum+= num;
        temp+= num;
        q.pop();
        q.push(temp);
    }
    cout << sum;

    return 0;
}