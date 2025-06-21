#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<string> str(n);
    int i=0, no=0, nn=n;
    char s;
    while(n--){
        cin >> s >> str[i++];
        if(s=='-')no++;
    }
    sort(str.begin(), str.end());
    for(auto it : str)cout << it << endl;
    printf("Se comportaram: %d | Nao se comportaram: %d\n", nn-no, no);
    return 0;
}
