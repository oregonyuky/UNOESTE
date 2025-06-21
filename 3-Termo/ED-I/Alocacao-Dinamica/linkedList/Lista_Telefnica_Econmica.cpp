#include <iostream>
#include <algorithm>
#include <vector>
#define dbg(v) cout << #v << " = " << (v) << endl
using namespace std;
int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    while(cin >> t){
        string str;
        vector<string> lis(t);
        for(int i=0;i<t;i++){
            cin >> str;
            lis[i] = str;
        }
        sort(lis.begin(), lis.end());
        int pos=0, soma=0;
        while(pos<t-1){
            int i=0;
            while(lis[pos][i]==lis[pos+1][i] && lis[pos][i]!='\0'){
                //dbg(lis[pos][i]);
                i++;
            }
            pos++;
            soma += i;
        }
        cout << soma << endl;
    }
    return 0;
}
