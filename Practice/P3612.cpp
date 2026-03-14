#include<iostream>
#include<vector>

using namespace std;
int main(){
    int listNum,num;
    cin >> listNum;
    vector< int > nums(listNum);
    for(int i = 0;i < listNum;i++){
        cin >> num;
        nums[i] = num;
    }
    for(int i = 1;i < listNum;i++){
        nums[i] = nums[i] + nums[i-1];
    }

    int m,l,r;
    cin >> m;
    vector< vector <int> > limit(m,vector< int >(2,0));
    for(int i = 0;i < m;i++){
        cin >> l >> r;
        limit[i][0] = l;
        limit[i][1] = r;
    }
    for(int i = 0;i < m;i++){
        if(limit[i][0] == 1) cout << nums[limit[i][1]-1] << endl;
        else cout << nums[limit[i][1]-1] - nums[limit[i][0]-2] << endl;
    }

    return 0;
}
