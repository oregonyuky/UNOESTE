#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    //freopen("input.txt", "r", stdin);
    int t, freq=0;
    cin >> t;
    while(t--){
        int ans;
        cin >> ans;
        if(ans==1)freq++;
    }
    cout << freq << endl;
    return 0;
}
