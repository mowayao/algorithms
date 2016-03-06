#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
int main(){
    string st;
    int M[30]={0};
    while(getline(cin,st) && st.size() > 0){   
       // cout<<st<<endl;            
       for(int i = 0; i < st.size(); i++){
          if(st[i]<='Z' && st[i] >= 'A')
             M[st[i]-'A']++;        
       }                                
    }
    char mat[100][100];
    int cnt= 0;
    for(cnt = 0; cnt < 100; cnt++){
        bool flag = 0;
        for(int j = 0; j < 26; j++){
            if(M[j]>0){
              mat[cnt][j] = '*';
              M[j]--;
              flag = 1;
            }        
        }
        if(!flag)
          break;        
    }
    for(int i = cnt-1; i >= 0; i--){
        for(int j = 0; j < 26; j++){
           if(mat[i][j] == '*')
             cout<<mat[i][j]<<" ";
           else
             cout<<"  ";       
        }
        cout<<endl;
    }
    for(char i = 'A'; i <= 'Z'; i++)
      cout<<i<<" ";
    cout<<endl;     
   /// while(1);
    return 0;
}
    
