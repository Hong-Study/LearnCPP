#include<iostream>
#include<string>
using namespace std;

class Person{
    string name;
    string tel;
    public:
    Person();
    string getName() { return name; }
    string getTel() { return tel; }
    void set(string name, string tel);
};
Person::Person(){ name = "없어믐";}
void Person::set(string name, string tel){
    this->name = name;
    this->tel = tel;
}
int main(){
    Person person[3];
    string name,tel;
    for(int i=0;i<3;i++){
        cout<<"사람 "<<i+1<<">>";
        getline(cin,name,' ');
        getline(cin,tel);
        person[i].set(name,tel);
    }
    cout<<"모든 사람의 이름은 "<<person[0].getName()<<" "<<person[1].getName()<<" "<<person[2].getName()<<endl;
    cout<<"전화 번호 검색합니다. 이름을 입력하세요>>";
    getline(cin,name);
    for(int i=0;i<3;i++){
        if(person[i].getName() == name)
            cout<<"전화번호는 "<<person[i].getTel();
    }
}