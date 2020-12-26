//제네릭 클래스로 스택 구현

#include<iostream>
using namespace std;

template <class type>
class Mystack{
	int tos;
	type data[100];
	
	public:
	Mystack();
	void push(type element);
	type pop();
};

template <class type>
Mystack<type>::Mystack(){
	tos = -1;
}
template <class type>
void Mystack<type>::push(type element){
	if(tos == 99){
		cout<<"stack is full"<<endl;
		return;
	}
	tos++;
	data[tos] = element;
}
template <class type>
type Mystack<type>::pop(){
	if(tos == -1){
		cout<<"stack is empty"<<endl;
		return 0;
	}
	type n = data[tos--];
	return n;
}
class Point{
	int x, y;
	public:
	Point(int x=0,int y=0) { this->x = x; this->y = y; }
	void show(){ cout<<"( "<< x << ", "<<y<<" )"<<endl; }
};
int main(){
	Mystack<int*> ipStack;	//int형 포인터 제네릭클래스
	int *p = new int [3];
	for(int i=0;i<3;i++) p[i] = i*10;
	ipStack.push(p);		//포인터 푸시
	int *q = ipStack.pop();	//포인터 팝
	for(int i=0;i<3;i++){
		cout<<q[i]<<", ";
	}
	cout<<endl;
	delete[] p;
	
	Mystack<Point> PointStack;
	Point a(2,3),b;
	PointStack.push(a);
	b = PointStack.pop();
	b.show();
	
	Mystack<Point*> pStack;
0	pStack.push(new Point(10,20));
	Point* pPoint = pStack.pop();
	pPoint->show();
	
	Mystack<string> stringStack;
	string s = "C++";
	stringStack.push(s);
	stringStack.push("Java");
	cout<<stringStack.pop()<<endl;
	cout<<stringStack.pop()<<endl;
}