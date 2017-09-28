#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	bool first=true;
	while(cin>>a>>b){
		if(!first){
			puts("");
		}
		first=false;
		vector<int> prob(45,0);
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				prob[i+j]++;
			}
		}
		int maxi=0;
		for(int i=0;i<42;i++){
			if(prob[i]>maxi){
				maxi=prob[i];
			}
		}
		for(int i=0;i<42;i++){
			if(prob[i]==maxi){
				printf("%d\n",i);
			}
		}
	}
	return 0;
}