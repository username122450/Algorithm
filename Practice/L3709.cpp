#include<iostream>
#include<vector>
#include<map>

using namespace std;

class ExamTracker {
public:
    ExamTracker() {
    }
    vector<pair<long long ,long long>> mapp;
    void record(int time, int score) {
        int pre = 0;
        if(!mapp.empty()){
            pre = mapp.back().second;
        }
        mapp.push_back({time,score+pre});
    }
    
    long long totalScore(int startTime, int endTime) {
        int l = 0,r = mapp.size()-1;
        int startsum ,endsum;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(mapp[mid].first > startTime)r = mid-1;
            else if(mapp[mid].first < startTime) l = mid+1;
            else startsum = mid-1;
        }
        l = 0,r = mapp.size()-1;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(mapp[mid].first > endTime)r = mid-1;
            else if(mapp[mid].first < endTime) l = mid+1;
            else endsum = mid;
        }
        return mapp[endsum].second - mapp[startsum].second;
    }
};

int main(){
    return 0;
}