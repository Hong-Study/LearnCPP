#include<iostream>
#include<string>
using namespace std;

class Person{
    string name;

    public:
    Person() {this->name = "없음";}
    Person(string name) {this->name = name;}
    void set(string name){ this->name = name; }
    string getName() {return name;}
};
class Family{
    Person *p;
    int size;
    string FAM;

    public:
    Family(string name, int size);
    void setname(int num, string name);
    void show();
    ~Family();
};
Family::Family(string name, int size){
    FAM = name;
    p = new Person [size];
    this->size = size;
}
void Family::setname(int num, string name){
    p[num].set(name);
}
void Family::show(){
    cout<<FAM<<"가족은 다음과 같이 "<<size<<"명 입니다."<<endl;
    for(int i=0;i<size;i++){
        cout<<p[i].getName()<<"\t";
    }
    cout<<endl;
}
Family::~Family(){
    delete [] p;
}

int main(){
    Family *simpson = new Family("Simpson",3);
    simpson->setname(0,"Mr. Simpson");
    simpson->setname(1,"Mrs. Simpson");
    simpson->setname(2,"Bart Simpson");
    simpson->show();
    delete simpson;
}