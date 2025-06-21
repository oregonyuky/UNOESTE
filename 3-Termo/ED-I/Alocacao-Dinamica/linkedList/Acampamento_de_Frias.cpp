#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mxN 100
class FelipeAkio{
    public:
    struct pair{
        char f[30];
        int s;
    };
    public:
    const char *recursao(pair p[mxN], int v, int pp, int size, bool pi){
        if(size==1)return p[0].f;
        if(v==0){
            int a = p[pp].s;
            pi = (a&1 ? 1 : 0);
            for(int i=pp;i<size-1;i++)p[i] = p[i+1];
            return recursao(p, a, (a&1 ? (pp-1)%(size-1) : (pp)%(size-1)), size-1, pi);
        }
        if(pi)return recursao(p, v-1, (pp+1)%size, size, pi);
        else return recursao(p, v-1, (pp-1+size)%size , size, pi);
    }
    public:
    void beecrowd(){
        int a;
        scanf("%d", &a);
        while(a){
            scanf("%d", &a);
            pair p[mxN];
            for(int i=0;i<a;i++){
                scanf("%s %d", p[i].f, &p[i].s);
            }
            bool pi;
            printf("Vencedor(a): %s\n", recursao(p, p[0].s, 0, a, (p[0].s&1 ? 1 : 0)));
            scanf("%d", &a);
        }
    }
};
class JoseVitor{
    public:
    struct Child {
        char name[32];
        int token;
        Child* next;
        Child* prev;
    };
    public:
    Child* newChild(Child ch) {
        Child* cptr = new Child;
        strcpy(cptr->name, ch.name);
        cptr->token = ch.token;
        cptr->next = nullptr;
        cptr->prev = nullptr;
        return cptr;
    }
    public:
    Child* insert(Child* children, Child ch) {
        Child* head = children;
        if(!children) { children = newChild(ch); return children; }
        while(children->next) children = children->next;
        children->next = newChild(ch);
        children->next->prev = children;
        return head;
    }
    public:
    void solve() {
        int a;
        scanf("%d", &a);
        while(a) {
            Child* children = nullptr;
            Child ch;
            for(int i = 0; i < a; i++) {
                scanf("%s %d", ch.name, &ch.token);
                children = insert(children, ch);
            }
            Child* it = children;
            while(it->next) it = it->next;
            it->next = children;
            children->prev = it;

            Child* cur = children;
            while(a-- >= 1) {
                it = cur;
                for(int i = 0; i < cur->token; i++)
                    if(cur->token&1) it = it->next;
                    else it = it->prev;
                it->next->prev = it->prev;
                it->prev->next = it->next; 
                cur = it;
            }
            
            printf("Vencedor(a): %s\n", cur->name);
            scanf("%d", &a);
        }
    }
};
int main(){
    FelipeAkio f;
    JoseVitor j;
    f.beecrowd();
    //j.solve();
    return 0;
}