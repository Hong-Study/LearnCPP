#include<iostream>
#include<string>

using namespace std;

class Printer{											//프린터 가상함수
	protected:
	string model;
	string maker;
	int printedCount;
	int availableCount;
	
	public:
	Printer(string model, string maker, int availableCount){
		this->model = model;
		this->maker = maker;
		this->printedCount = 0;
		this->availableCount = availableCount;
	}
	virtual void print(int pages) = 0;
	virtual void show() = 0;
};

class InkPrinter : public Printer{						//잉크 프린터
	private:
	int availableInk;
	
	public:
	InkPrinter(string M, string N, int p, int ai) : Printer(M,N,p) { availableInk = ai; }
	void print(int pages){
		if(availableCount - pages < 0){
			cout<<"종이가 부족합니다!!"<<endl;
		}else if(availableInk - pages < 0){
			cout<<"잉크가 부족합니다!!"<<endl;
		}else{
			cout<<"프린트 하였습니다!!"<<endl;
			availableCount -= pages;
			availableInk -= pages;
		}
	}
	void show(){
		cout<<"잉크젯 : "<<model<<", "<<maker<<", "<<"남은 종이 : "<<availableCount<<"장, "<<"남은 잉크 : "<<availableInk<<endl;
	}
};

class RagerPrinter : public Printer{					//레이저 프린터
	private:
	int availableToner;
	
	public:
	RagerPrinter(string M, string N, int p, int ai) : Printer(M,N,p) { availableToner = ai; }
	void print(int pages){
		if(availableCount - pages < 0){
			cout<<"종이가 부족합니다!!"<<endl;
		}else if(availableToner - pages < 0){
			cout<<"잉크가 부족합니다!!"<<endl;
		}else{
			cout<<"프린트 하였습니다!!"<<endl;
			availableCount -= pages;
			availableToner -= pages;
		}
	}
	void show(){
		cout<<"레이저 : "<<model<<", "<<maker<<", "<<"남은 종이 : "<<availableCount<<"장, "<<"남은 잉크 : "<<availableToner<<endl;
	}
};

class Play{
	public:
	void play(){
		char a;
		int n, count;
		InkPrinter* Ink = new InkPrinter("Officejet V40", "HP", 5, 10);
		RagerPrinter* Rager = new RagerPrinter("SCX-6x45","삼성전자",3,20);
		cout<<"현재 작동중인 2대의 프린터는 아래와 같다."<<endl;
		Ink->show();
		Rager->show();
		while(1){
			cout<<endl<<"프린터(1: 잉크젯, 2: 레이저)와 매수 입력 >> ";
			cin>>n>>count;
			if(n == 1){
				Ink->print(count);
			}
			else{
				Rager->print(count);
			}
			Ink->show();
			Rager->show();
			cout<<"계속 프린트 하시겠습니까?(y/n) >> ";
			cin>>a;
			if(a == 'n')
				break;
		}
	}
};

int main(){
	Play p;
	p.play();
}