#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s;
    int num;
    for(int i = 0;i < asteroids.size();i++){
        num = asteroids[i];
        bool exploded = false;
        while (!s.empty() && s.top() > 0 && num < 0) {  // 关键：while 循环
            if (abs(s.top()) == abs(num)) {
                s.pop();
                exploded = true;
                break;
            } else if (abs(s.top()) < abs(num)) {
                s.pop();
            } else {
                exploded = true;
                break;
            }
        }
        if (!exploded) {
            s.push(num);
        }
    }
    vector<int> ans(s.size(),0);
    while(!s.empty()){
        ans[s.size()-1] = s.top();
        s.pop();
    }
    return ans;
}

int main(){
    int n,num;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0;i < n;i++){
        cin >> num;
        nums[i] = num;
    }
    asteroidCollision(nums);
    vector<int>::iterator it = nums.begin();
    for(int i = 0;i < n;i++ ){
        cout << *(it+i)<<endl;
    }
    return 0;
}