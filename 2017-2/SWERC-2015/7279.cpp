#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void printbin(ull number){
	//return;
		bool first=true;
		for(ull j=63;j!=~(0ULL);j--){
			if(number&(1LL<<j)) first=false;
			if(!first)printf("%d",!!(number&(1LL<<j)));
			
			//cout<<j<<endl;
		}
		puts(" ");
	}

int main(){
	ull n,m;
	vector<ull> v;
	for(ull i=1;i<64;i++){
		ull m1=~((~0ULL)<<i);
		//cout<<m1<<endl;
		ull bits=i;
		ull num=m1;
		v.push_back(m1);
		//printbin(num);
		for(ull j=1;j<64;j++){
			bits=i;
			num=m1;
			//cout<<j<<endl;
			bool wa=true;
			while(bits<64&&wa){
				wa=false;
				bool entro=false;
				if(bits+j<64){
					bits+=j;
					entro=true;
					num=num<<j;	//j 0's
					//printbin(num);
					v.push_back(num);
				}
				if(bits+i<64&&entro){
					bits+=i;
					num=(num<<i)+(m1);	//i 1's
					//printbin(num);
					v.push_back(num);
					wa=true;
				}
			}
		}
		//printf("%d\n",v.size());
	}
	sort(v.begin(),v.end());
	while(cin>>n>>m){
		ull low=(ull)(lower_bound(v.begin(),v.end(),n)-v.begin());
		ull up=(ull)(upper_bound(v.begin(),v.end(),m)-v.begin());
		printf("%lld\n",up-low);
	}
	return 0;
}