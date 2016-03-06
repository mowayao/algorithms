#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
map<string,int> mma;

int main(){
    string st;
    int sum = 0;
    while(getline(cin,st)){
        mma[st]++;
        sum++;
    }
    for(map<string,int>::iterator it = mma.begin(); it != mma.end(); it++){
        cout<<it->first<<" ";
        printf("%.4lf\n",it->second*100.0/sum);
    }
    return 0;
}
