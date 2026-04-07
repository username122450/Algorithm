#include<iostream>
#include<vector>

using namespace std;

// long long minTime(vector<int>& skill, vector<int>& mana) {
//     int ssize = skill.size();
//     int msize = mana.size();
//     vector<long long> time(ssize,0);
//     time[0] = skill[0]*mana[0];
//     long long tsum;
//     for(int i = 1;i < ssize;i++){
//         tsum = skill[i]*mana[0];
//         time[i] = time[i-1]+tsum;
//     }
//     for(int i = 1;i < msize;i++){
//         time[ssize-1] = time[ssize-1] + skill[ssize-1]*mana[i];
//         for(int j = ssize-2;j >=0;j--){
//             tsum = skill[j+1]*mana[i];
//             long long endTime = time[j+1] - tsum;
//             if(endTime < time[j]+tsum){
//                 int diff = time[j]+tsum-endTime;
//                 for(int k = j+1;k < ssize;k++){
//                     time[k]+=diff;
//                 }
//             }
//             time[j] = max(endTime,time[j]+tsum);
//         }
//     }
//     return time[ssize-1];
// }

long long minTime(vector<int>& skill, vector<int>& mana) {
    int ssize = skill.size();
    int msize = mana.size();
    vector<long long> end(ssize,0),time(ssize,0);
    time[0] = skill[0]*mana[0];
    end[0] = time[0];
    for(int i = 1;i < ssize;i++){
        time[i] = skill[i]*mana[0];
        end[i] = end[i-1]+time[i];
    }
    for(int i = 1;i < msize;i++){
        time[0] = skill[0]*mana[i];
        end[0] = time[0]+end[0];
        cout << end[0] << " ";
        for(int j = 1;j <ssize;j++){
            time[j] = skill[j]*mana[i];
            end[j] = max(end[j-1]+time[j],end[j]+time[j]);
        }
        for(int j = ssize-2;j >=0;j--){
            end[j] = end[j+1]-time[j+1];
            cout << end[j] << " ";
        }
        cout << endl;
    }
    return end[ssize-1];
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> skill(n,0);
    vector<int> mana(m,0);
    for(int i = 0;i < n;i ++){
        cin >> skill[i];
    }
    for(int i = 0;i < m;i++){
        cin >> mana[i];
    }
    long long ans = minTime(skill, mana);
    cout << ans;
    return 0;
}