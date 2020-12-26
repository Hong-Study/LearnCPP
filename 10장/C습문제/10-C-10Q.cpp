#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

class Nation{
	string nation;
	string capital;
	
	public:
	Nation(string nation, string capital) { this->nation = nation; this->capital = capital; }
	string re_nation(){
		return nation;
	}
	string re_capital(){
		return capital;
	}
};

int main(){
	vector<Nation> v;
	
	int n;
	cout<<"수도 맞추기 게임 시작한다."<<endl;
	while(1){
		cout<<"정보 입력: 1, 퀴즈: 2, 종료: 3 >>";
		cin>>n;
		if(n==1){
			cout<<"현재 "<<v.size()+1<<"개의 나라가 있습니다."<<endl;
			cout<<"나라와 수도를 입력하세요(no no이면 입력 끝)"<<endl;
			string a, b;
			while(1){
				cout<<v.size()+1<<">>";
				cin>>a>>b;
				if(a == "no" && b == "no")				//중복 체크 아직 안만듬.
					break;
				else{
					v.push_back(Nation(a,b));
				}
			}
		}
		else if(n==2){
			srand((unsigned)time(NULL));
			while(1){
				int num = rand()%(v.size()+1);
				string answer;
				cout<<v[num].re_nation()<<"의 수도는 ? ";
				cin>>answer;
				if(v[num].re_capital() == answer){
					cout<<"Correct!!"<<endl;
				}else if(answer == "exit")
					break;
				else
					cout<<"NO!!"<<endl;
			}
		}
		else
			break;
	}
}