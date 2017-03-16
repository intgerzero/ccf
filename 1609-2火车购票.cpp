#include<iostream>
using namespace std;
int main(){
	int a[20];
	for(int i=0;i<20;i++)
		a[i]=5;
	int n;
	cin>>n;
	int t;
	for(int i=0;i<n;i++){
		int state=0;
		cin>>t;
		for(int j=0;j<20;j++){
			if(t<=a[j]){
				for(int k=0;k<t;k++){
					if(k!=t-1)
						cout<<j*5+(5-a[j])+k+1<<' ';
					else
						cout<<j*5+(5-a[j])+k+1<<endl; 
				}
				a[j]=a[j]-t;
				state=1;
				break;
			}
		}
		if(state==0){
			for(int j=0;j<20;j++){
				for(int k=a[j];k>0&&t>0;k--,t--,a[j]--){
					if(t!=1)
						cout<<j*5+(5-k)+1<<' ';
					else
						cout<<j*5+(5-k)+1<<endl;
				}
				if(t==0)
					break;
			}
		}
	}
	
} 
