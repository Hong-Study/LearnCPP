#include<iostream>
#include<string>
using namespace std;

class Player{
    string name;
    string word;

    public:
    void Getname();
    void GetWorld();
    string PushWorld();
};
void Player::Getname(){
    cout<<"참가자의 이름을 입력하세요. >>";
    getline(cin,name);
}
void Player::GetWorld(){
    cout<<name<<" >>";
    getline(cin,word);
}
string Player::PushWorld(){
    return word;
}
class WorldGame{
    string answer = "아버지";
    Player *play;
    int num;
    public:
    WorldGame();
    bool TrueorFalse(string num);
};
WorldGame::WorldGame(){
    cout<<"게임 시작합니다!"<<endl;
}
bool WorldGame::TrueorFalse(string num){
    int a = answer.size();
    string x = "지";
    string y = "지";
    if((answer.at(a-3) == num.at(0)) && (answer.at(a-2) == num.at(1)) && (answer.at(a-1) == num.at(2))){            //visual studio code는 한글을 3글자 취급한다.. 이것때매 시간 얼마나 날린건지;
        answer = num;
        return true;
    }
    else
        return false;
}


int main(){
    int n;
    WorldGame game;
    cout<<"게임에 참가하는 인원은 몇명입니까? ";
    cin>>n;
    cin.ignore();
    Player *player = new Player [n];
    for(int i=0;i<n;i++){
        player[i].Getname();
    }
    int i=0;
    cout<<"시작 단어는 아버지입니다.\n";
    while(true){
        player[i%n].GetWorld();
        if(!game.TrueorFalse(player[i%n].PushWorld())){
            cout<<"실패하셨습니다."<<endl;
            break;
        }
        i++;
    }
}