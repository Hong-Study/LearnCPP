#include<iostream>

using namespace std;

class model{
	public:
	static int Coffee;
	static int Sugar;
	static int Cream;
	static int Water;
	static int Cup;
	static void Status(){
		cout<<"Coffee : ";
		for(int i=0;i<Coffee;i++){
			cout<<"*";
		}
		cout<<endl;
		cout<<"Sugar : ";
		for(int i=0;i<Sugar;i++){
			cout<<"*";
		}
		cout<<endl;
		cout<<"Cream : ";
		for(int i=0;i<Cream;i++){
			cout<<"*";
		}
		cout<<endl;
		cout<<"Water : ";
		for(int i=0;i<Water;i++){
			cout<<"*";
		}
		cout<<endl;
		cout<<"Cup : ";
		for(int i=0;i<Cup;i++){
			cout<<"*";
		}
		cout<<endl;
	}
	static void full(){
		Coffee = 3;
		Sugar = 3;
		Cream = 3;
		Water = 3;
		Cup = 3;
	}
	virtual void print() = 0;
};
int model::Coffee = 3;
int model::Sugar = 3;
int model::Cream = 3;
int model::Water = 3;
int model::Cup = 3;

class Nomal : public model{
	public:
	void print(){
		if(Water == 0 || Coffee == 0 || Cup == 0){
			cout<<"재료가 부족합니다!!"<<endl;
		}else{
			cout<<"맛있는 커피 나왔습니다!"<<endl;
			Water--;
			Coffee--;
			Cup--;
		}
	}
};
class SugarCoffee : public model{
	public:
	void print(){
		if(Water == 0 || Coffee == 0 || Cup == 0 || Sugar == 0){
			cout<<"재료가 부족합니다!!"<<endl;
		}else{
			cout<<"맛있는 커피 나왔습니다!"<<endl;
			Water--;
			Coffee--;
			Cup--;
			Sugar--;
		}
	}
};
class CreamCoffee : public model{
	public:
	void print(){
		if(Water == 0 || Coffee == 0 || Cup == 0 || Cream == 0){
			cout<<"재료가 부족합니다!!"<<endl;
		}else{
			cout<<"맛있는 커피 나왔습니다!"<<endl;
			Water--;
			Coffee--;
			Cup--;
			Cream--;
		}
	}
};

int main(){
	Nomal nomal;
	SugarCoffee sugar;
	CreamCoffee cream;
	int n = 0;
	while(n!=4){
		model::Status();
		cout<<endl<<"보통커피 : 0, 설탕 : 1, 블랙 : 2, 채우기 : 3, 종료 : 4 >> ";
		cin>>n;
		if(n==0)
			nomal.print();
		else if(n==1)
			sugar.print();
		else if(n==2)
			cream.print();
		else if(n==3)
			model::full();
	}
}