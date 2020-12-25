#include<iostream>
#include<string>

using namespace std;

class Seat;
class Schedule;
class AirlineBook;

class Seat{									//자리를 맡는 클래스
	private:
	string name;
	bool check;
	
	public:
	void Setting(bool check){
		this->check = check;
	}
	void choice_seat(string name){
		this->name = name;
		check = true;
	}
	void cancle_seat(){
		check = false;
	}
	bool Return_Check(){
		return check;
	}
	string Return_name(){
		return name;
	}
};

class Schedule{								//시간대의 스케줄을 관리하는 클래스 * Seat클래스 8개 잇음
	private:
	Seat SETS[8];
	string Time;
	
	public:
	Schedule(string Time){
		this->Time = Time;
		for(int i=0;i<8;i++){
			SETS[i].Setting(false);
		}
	}
	void Show_Schedule(){
		cout<<Time<<":	";
		for(int i=0;i<8;i++){
			if(!SETS[i].Return_Check())
				cout<<"---    ";
			else
				cout<<SETS[i].Return_name()<<"    ";
		}
		cout<<endl;
	}
	void Reservation(int num, string name){
		SETS[num].choice_seat(name);
	}
	void Cancle(int num, string name){
		SETS[num].cancle_seat();
	}
	string Return_Time(){
		return Time;
	}
};

class AirlineBook{									//전체적인 프로그램을 관리하는 프로그램
	private:
	Schedule MIN[3]{Schedule("07시"), Schedule("12시"), Schedule("17시")};
	int Time;
	int Seat_Number;
	string Name;
	public:
	AirlineBook(){
		Time = 0;
		Seat_Number = 0;
	}
	void Show_Menu(){
		cout<<"예약:1,  취소:2,  보기:3,  끝내기:4  >> ";
	}
	void Air_Reservation(){
		Show_Time();
		cin>>Time;
		MIN[Time-1].Show_Schedule();
		cout<<"좌석 번호 >> ";
		cin>>Seat_Number;
		cout<<"이릅 입력 >> ";
		cin>>Name;
		MIN[Time-1].Reservation(Seat_Number-1,Name);
	}
	void Air_Cancle(){
		Show_Time();
		cin>>Time;
		MIN[Time-1].Show_Schedule();
		cout<<"좌석 번호 >> ";
		cin>>Seat_Number;
		cout<<"이릅 입력 >> ";
		cin>>Name;
		MIN[Time-1].Cancle(Seat_Number-1,Name);
	}
	void Air_Show(){
		for(int i=0;i<3;i++){
			MIN[i].Show_Schedule();
		}
	}
	void Show_Time(){
		cout<<"07시:1,  12시:2  17시:3  >> ";
	}
};

int main(){
	AirlineBook AIR;
	int num;
	while(1){
		AIR.Show_Menu();
		cin>>num;
		switch(num){
			case 1:
				AIR.Air_Reservation();
				break;
			case 2:
				AIR.Air_Cancle();
				break;
			case 3:
				AIR.Air_Show();
				break;
			case 4:
				cout<<"예약 시스템을 종료합니다."<<endl;
				return 0;
		}
	}
}