#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k, k--;
    int i=0;
    vector<string> nm(n);
    while(n--){
        cin >> nm[i++];
    }
    sort(nm.begin(), nm.end());
    cout << nm[k] << endl;
    return 0;
}
