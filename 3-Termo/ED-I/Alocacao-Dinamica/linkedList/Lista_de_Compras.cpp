#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <sstream>
using namespace std;
set<string> x(string st){
    string wo; 
    stringstream ss(st); 
    set<string> s; 
    int i=0;
    while(ss >> wo){ 
        s.insert(wo);
    }
    return s;
}
int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string st;
        getline(cin, st);
        set<string> s = x(st);
        int i=0;
        for(auto it=s.begin();it!=s.end();++it, ++i){
            cout << (i==s.size()-1 ? *it + "\n" : *it+" ");
        }
    }
    return 0;
}
