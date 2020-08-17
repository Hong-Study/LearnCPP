#include<iostream>
#include<string>
using namespace std;

class Circle{
    int radius;
    string name;

    public:
    void setCircle(string name, int radius);
    double getArea();
    string getName();
};
void Circle::setCircle(string name, int radius){
    this->radius = radius;
    this->name = name;
}
double Circle::getArea(){
    return 3.14*radius*radius
}
string Circle::getName(){
    return name;
}
class CirceManager{
    Circle *p;
    int size;

    public:
    CirceManager(int size);
    ~CirceManager();
    void searchByName();
    void searchByArea();
};
CirceManager::CirceManager(int size){
    this->size = size;
    p = new Circle [size];
    string name,radius;
    for(int i=0;i<size;i++){
        cout<<"원 "<<i+1<<"의 이름과 반지름 >>";
        getline(cin,name,' ');
        getline(cin,radius);
        p[i].setCircle(name,radius);
    }
}
CirceManager::~CirceManager(){
    delete [] p;
}
void CirceManager::searchByName(){
    string name;
    cout<<"검색하고자 하는 원의 이름 >>";
    getline(cin,name);
    for(int i=0;i<size;i++){
        if(p[i].getName() == name)
            cout<<p[i].getArea();
    }
}
void CirceManager::searchByArea(){
    double num;
    cout<<"최소 면적을 정수로 입력하세요 >>";
    getline(cin,name);
    for(int i=0;i<size;i++){
        if(p[i].getName() == name)
            cout<<p[i].getArea();
    }
}
int main(){
    Family *simpson = new Family("Simpson",3);
    simpson->setname(0,"Mr. Simpson");
    simpson->setname(1,"Mrs. Simpson");
    simpson->setname(2,"Bart Simpson");
    simpson->show();
    delete simpson;
}