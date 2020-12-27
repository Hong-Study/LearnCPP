#include<iostream>
#include<map>

using namespace std;

int main(){
	map<string, int> v;
	
	int n=0;
	string name;
	int count;
	while(n!=3){
		cout<<"입력 : 1, 조회 : 2, 종료 : 3 >> ";
		cin>>n;
		if(n==1){
			cout<<"이름과 점수 >>";
			cin>>name>> count;
			if(v.find(name) == v.end())
				v.insert(make_pair(name, count));
			else
				cout<<"이미 있는 값입니다."<<endl;
		}
		else if(n == 2){
			cout<<"이름 : ";
			cin>>name;
			cout<<name<<"의 점수는 "<<v[name]<<endl;
		}
	}
	cout<<"프로그램을 종료합니다."<<endl;
}