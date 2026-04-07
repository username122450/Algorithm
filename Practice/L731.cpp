#include<vector>
#include<iostream>
#include<map>

using namespace std;

class MyCalendarTwo {
    
public:
    
    map<int,int> m;
    MyCalendarTwo() {
    }
    
    bool book(int startTime, int endTime) {
        m[startTime] ++;
        m[endTime] --;
        int count = 0;
        for(auto& t:m){
            count+=t.second;
            if(count >=3){
                m[startTime]--;
                if (m[startTime] == 0) m.erase(startTime);
                m[endTime]++;
                if (m[endTime ] == 0) m.erase(endTime);
                return false;
            }
        }
        return true;
    }
};

int main(){

    return 0;
}