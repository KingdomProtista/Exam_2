#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] > x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	int i=0,j=1,k=0,rank[20]={};
	ifstream source("score3.txt");
	ofstream myfile("rank.txt");
	string line,score[20]={};
	float Newscore[20]={};
	while(getline(source,line)){
		 cout<<line<<"\n";
		 score[i]=line;
		 i++;
	}
	for(int i=0;i<20;i++){
		Newscore[i]=atof(score[i].c_str());
	}
		sort(Newscore,20);
	for(int i=0;i<20;i++){
		if(Newscore[i]!=Newscore[i-1]){
			rank[i]=i+1;
		}
		j++;
		if(Newscore[i]==Newscore[i-1]){
			j--;
			rank[i]=j;
		}
		else j=i+1;
	}
	for(int i=0;i<20;i++){
		cout<<Newscore[i]<<"\n";
	}
	for(int i = 0; i < 20;i++){
		myfile << Newscore[i] <<"="<<rank[i]<< "\n";
	}
	myfile.close();
	return 0;
}
