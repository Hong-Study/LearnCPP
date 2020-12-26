#include<iostream>

using namespace std;
class Comparble{
	public:
	virtual bool operator > (Comparble& op2) = 0;
	virtual bool operator < (Comparble& op2) = 0;
	virtual bool operator == (Comparble& op2) = 0;
};
class Circle : public Comparble{
	int radius;
	
	public:
	Circle(int radius=1){ this->radius = radius; }
	int getRadius() { return radius; }
	bool operator >(Comparble& op2){
		Circle *c;
		c = (Circle*) &op2;
		if(this->radius > c->getRadius())
			return true;
		else
			return false;
	}
	bool operator <(Comparble& op2){
		Circle *c;									//형변환이 중요하다고 개인적으로 생각됨.
		c = (Circle*) &op2;
		if(this->radius < c->getRadius())
			return true;
		else
			return false;
	}
	bool operator ==(Comparble& op2){
		Circle *c;
		c = (Circle*) &op2;
		if(this->radius == c->getRadius())
			return true;
		else
			return false;
	}
};

template <class type>
type bigger(type a, type b){
	if(a>b) return a;
	else return b;
}

int main(){
	int a=20, b=50, c;
	c = bigger(a,b);
	cout<<"20과 50중 큰 값은 "<< c <<endl;
	Circle waffle(10), pizza(20),y;
	y = bigger(waffle, pizza);
	cout<<"waffle과 pizza 중 큰 것의 반지름은 "<<y.getRadius()<<endl;
}