#include<iostream>
#include<vector>

using namespace std;

class Circle{
	string name;
	int radius;
	
	public:
	Circle(int radius, string name){
		this->radius = radius;
		this->name = name;
	}
	double getArea() { return 3.14*radius*radius; }
	string getName() { return name; }
};

int main(){
	vector<Circle*> v;
	int n = 0;
	int radius;
	string name;
	while(n!=4){
		cout<<"삽 : 1, 삭 : 2, 보기 : 3, 종료 : 4 >>";
		cin>>n;
		if(n==1){
			cout<<"반지름 이름 >> ";
			cin>>radius>>name;
			v.push_back(new Circle(radius, name));
		}else if(n==2){
			cout<<"이름 : >>";
			cin>>name;
			auto it = v.begin();						//vector<Circle*>::iterator it = v.begin();
			for(int i=0;i<v.size();it++,i++){
				if(v[i]->getName() == name){
					it = v.erase(it);
				}
				*it->getName();
			}
		}else if(n==3){
			for(int i=0;i<v.size();i++){
				cout<<v[i]->getName()<<endl;
			}
		}
	}
}