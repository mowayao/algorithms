#include <iostream>
#include <fstream>
using namespace std;

#define Max 100000

int n;
int from,to;
int d[110][110];

void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][k]+d[k][j]<d[i][j])d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
}
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)d[i][j]=0;
			else d[i][j]=Max;
		}
	}
}

int main(){
	cin>>n>>from>>to;
	init();
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t;
			cin>>t;
			if(j==1){
				d[i][t]=0;
			}else{
				d[i][t]=1;
			}
		}
	}
	floyd();
	if(d[from][to]==Max){
		cout<<-1<<endl;
	}else{
		cout<<d[from][to]<<endl;
	}

}
