#include<iostream>
#include<vector>
#define nul -1
using namespace std;
int main(){
    int listNum;
    cin >> listNum;
    vector< int > a,b,c,d;
    for(int i = 0;i<listNum;i++){
        int a1,b1,c1,d1;
        cin >> a1 >> b1 >> c1 >> d1;
        a.push_back(a1);
        b.push_back(b1);
        c.push_back(c1);
        d.push_back(d1);
    }
    int x,y;
    cin >> x >> y;
    int index = -1;
    for(int i = listNum-1;i>=0;i--){
      if(a[i]<=x && a[i]+c[i]>=x && b[i]<=y && b[i]+d[i]>=y){
          index = i+1;
          break;
      }
    }
    cout << index;
    return 0;
}