#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 10000+10;
const int maxm = 80;
char mat[maxn][maxm];
char revmat[maxm][maxn];
int r,c;
int P[maxn],F[maxn];
int gcd(int a,int b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}
void getP() {
    P[1] = P[0] = 0;
    for(int i = 1; i < r; i++) {
        int j = P[i];
        while(j && strcmp(mat[i],mat[j])) j = P[j];
        if(strcmp(mat[i],mat[j])==0) P[i+1] = j+1;
        else P[i+1] = 0;
    }
}
void getF() {
    F[1] = F[0] = 0;
    for(int i = 1; i < c; i++) {
        int j = F[i];
        while(j && strcmp(revmat[i],revmat[j])) j = F[j];
        if(strcmp(revmat[i],revmat[j])==0) F[i+1] = j+1;
        else F[i+1] = 0;
    }
}
void getRev() {
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            revmat[i][j] = mat[j][i];
        }
    }
}
void solve() {
    int L = r-P[r],R = c - F[c];
    printf("%d\n",L*R);
}
int main(){

    while(~scanf("%d%d",&r,&c)){
        for(int i = 0; i < r; i++) scanf("%s",mat[i]);
        getP();
        getRev();
        getF();
        solve();
    }
    return 0;
}
