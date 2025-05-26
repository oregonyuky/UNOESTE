#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void exibir(vector<vector<double>> mat){
    int n = mat.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
double getDet(vector<vector<double>> mat, int n){
    if(n==1)return mat[0][0];
    if(n==2)return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
    double res=0.0;
    for(int i=0;i<n;i++){
        vector<vector<double>> sub(n, vector<double>(n));
        for(int j=1;j<n;j++){
            int subcol=0;
            for(int k=0;k<n;k++){
                if(i==k)continue;
                sub[j-1][subcol++] = mat[j][k];
            }
        }
        int sign = (~i&1 ? 1 : -1);
        res += sign*mat[0][i]*getDet(sub, n-1);
    }
    return res;
}
void exA(){
    double x[12] = {-1, -0.75, -0.6, -0.5, -0.3, 0, 0.2, 0.4, 0.5, 0.7, 1};
    double fx[12] = {2.05, 1.15, 0.45, 0.4, 0.5, 0, 0.2, 0.6, 0.51, 1.2, 2.05};
    double s[4], sf[3], q=0.0;
    memset(s, 0.0, sizeof(s));
    memset(sf, 0.0, sizeof(sf));
    for(int i=0;i<11;i++){
        q += 1;
        s[0] += x[i];
        s[1] += pow(x[i], 2);
        s[2] += pow(x[i], 3);
        s[3] += pow(x[i], 4);
        sf[0] += fx[i];
        sf[1] += fx[i]*x[i];
        sf[2] += fx[i]*pow(x[i], 2);
    }
    int n=3;
    vector<vector<double>> mat(n, vector<double>(n));
    mat[0][0] = q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)continue;
            mat[i][j] = s[i+j-1];
        }
    }
    double d = getDet(mat, n);
    mat[0][0] = q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0)mat[i][j] = sf[i];
            else mat[i][j] = s[i+j-1];
        }
    }
    double dx = getDet(mat, n);
    mat[0][0] = q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)continue;
            if(j==1)mat[i][j] = sf[i];
            else mat[i][j] = s[i+j-1];
        }
    }
    double dy = getDet(mat, n);
    mat[0][0] = q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)continue;
            if(j==2)mat[i][j] = sf[i];
            else mat[i][j] = s[i+j-1];
        }
    }
    double dz = getDet(mat, n);
    printf("%.3lfx^2 + %.3lfx + %.3lf\n", dz/d, dy/d, dx/d);
}
void exB(){
    double x[4] = {0, 1, 2, 3};
    double fx[4] = {0, 1.1, 1.9, 2.8};
    double s[4], sf[3], q=0.0;
    memset(s, 0.0, sizeof(s));
    memset(sf, 0.0, sizeof(sf));
    for(int i=0;i<4;i++){
        q += 1;
        s[0] += x[i];
        s[1] += pow(x[i], 2);
        s[2] += pow(x[i], 3);
        sf[0] += fx[i];
        sf[1] += fx[i]*x[i];
    }
    int n = 2;
    vector<vector<double>> mat(n, vector<double>(n));
    vector<vector<double>> mat1(n, vector<double>(n));
    mat[0][0] = q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)continue;
            mat[i][j] = s[i+j-1];
        }
    }
    double d = getDet(mat, n);
    mat1 = mat;
    for(int i=0;i<n;i++){
        mat1[i][0] = sf[i];
    }
    double dx = getDet(mat1, n);
    mat1 = mat;
    for(int i=0;i<n;i++){
        mat1[i][1] = sf[i];
    }
    double dy = getDet(mat1, n);
    printf("%.3lfx + %.3lf\n", dy/d, dx/d);
}
void exC(){
    double x[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    double fx[8] = {0.5, 0.6, 0.9, 0.8, 1.2, 1.5, 1.7, 2};
    double s[4], sf[3], q=0.0;
    memset(s, 0.0, sizeof(s));
    memset(sf, 0.0, sizeof(sf));
    for(int i=0;i<8;i++){
        q += 1;
        s[0] += x[i];
        s[1] += pow(x[i], 2);
        s[2] += pow(x[i], 3);
        sf[0] += fx[i];
        sf[1] += fx[i]*x[i];
    }
    int n = 2;
    vector<vector<double>> mat(n, vector<double>(n));
    vector<vector<double>> mat1(n, vector<double>(n));
    mat[0][0] = q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)continue;
            mat[i][j] = s[i+j-1];
        }
    }
    double d = getDet(mat, n);
    mat1 = mat;
    for(int i=0;i<n;i++){
        mat1[i][0] = sf[i];
    }
    double dx = getDet(mat1, n);
    mat1 = mat;
    for(int i=0;i<n;i++){
        mat1[i][1] = sf[i];
    }
    double dy = getDet(mat1, n);
    printf("%.3lfx + %.3lf\n", dy/d, dx/d);
}
int main(){
    printf("a) "); exA();
    printf("b) "); exB();
    printf("c) "); exC();

    return 0;
}