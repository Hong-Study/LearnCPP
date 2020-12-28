#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>

using namespace std;

class AbstractPlayer{
	string name;
	
	protected:
	static string gbb[3];
	
	public:
	AbstractPlayer(string name){
		this->name = name;
		gbb[0] = "가위";
		gbb[1] = "바위";
		gbb[2] = "보";
	}
	virtual string turn()=0;
	string getName(){ return name; }
};
string AbstractPlayer::gbb[3];
class Human : public AbstractPlayer{
	public:
	Human(string name) : AbstractPlayer(name) {}
	string turn(){
		string answer;
		while(1){
			cout<<getName()<<">>";
			cin>>answer;
			if(answer == "가위" || answer == "바위" || answer == "보")
				return answer;
		}
	}
};
class Computer : public AbstractPlayer{
	public:
	Computer(string name = "Computer") : AbstractPlayer(name) {}
	string turn(){
		srand((unsigned)time(NULL));
		int n = rand() % 3;
		cout<<getName()<<" "<<gbb[n]<<endl;
		return gbb[n];
	}
};
int main(){
	string name;
	cout<<"선수 이름 입력 : ";
	cin>>name;
	Human A(name);
	Computer B;
	while(1){
		string a = A.turn();
		string b = B.turn();
		
		if(a == b){
			cout<<"the same"<<endl;
		}else if((a == "가위" && b == "보") || (a == "바위" && b == "가위") || (a == "보" && b == "바위")){
			cout<<A.getName()<<"is winner"<<endl;
		}else{
			cout<<B.getName()<<"is winner"<<endl;
		}
	}
}