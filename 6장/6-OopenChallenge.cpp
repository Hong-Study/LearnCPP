#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

class Person{
	private:
	string name;
	int num;
	
	public:
	void ChoiceName(string name){
		this->name = name;
	}
	void ChoiceNum(){
		cin>>this->num;
	}
	string ReName(){
		return name;
	}
	int ReNum(){
		return num;
	}
};
class UpAndDownGame{
	private:
	static Person *person;
	static int first;
	static int last;
	static int collet;
	
	public:
	static void StartGame(){
		srand((unsigned)time(0));
		collet = rand()%100;
		person[0].ChoiceName("김인수");
		person[1].ChoiceName("오은경");
		int i=0;
		while(1){
			cout<<first<<"과 "<<last<<"사이에 있습니다."<<endl;
			cout<<person[i].ReName()<<">>";
			person[i].ChoiceNum();
			if(collet == person[i].ReNum()){
				cout<<person[i].ReName()<<"가(이) 이겼습니다!"<<endl;
				break;
			}
			else if(collet < person[i].ReNum() && last > person[i].ReNum())
				last = person[i].ReNum();
			else if(first < person[i].ReNum() && collet > person[i].ReNum())
				first = person[i].ReNum();
			i = (i+1)%2;
		}
	}
};

int UpAndDownGame::first = 0;
int UpAndDownGame::last = 99;
int UpAndDownGame::collet = 0;
Person *UpAndDownGame::person = new Person[2];
int main(){
	UpAndDownGame Game;
	Game.StartGame();
}