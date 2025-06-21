#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<list<string>> nomes(20);  
    for (int i = 0; i < n; ++i) {
        string nome;
        cin >> nome;
        int t = nome.size();  
        nomes[t].push_back(nome);  
    }
    while (!nomes.empty()) {
        bool first = true;
        int i=0;
        for (auto it = nomes.begin(); it != nomes.end(); ) {
            if (it->empty()) {
                it = nomes.erase(it);  
           } else {
                if(!first)cout << ", ";
                cout << (it!=nomes.end() ? it->front() : "\n");
                it->pop_front(); 
                first = false;
                ++it; i++;
            }
        }
        if(nomes.size()!=0)
            cout << endl;
    }
    return 0;
}
