//제네릭 클래스 써보기
#include<iostream>

using namespace std;

template <class type, class type2>
class Mystack{
	int tos;
	type data[100];
	
	public:
	Mystack() : tos(-1) {};
	void push(type element);
	type pop();
	/*						이렇게도 쓸 수 있다.
	void push(type element){
		tos++;
		data[tos] = element;
		
	}
	type pop(){
		type n = data[tos];
		tos--;
		return n;
	}
	*/
};
template<class type, class type2>
void Mystack<type,type2>::push(type element){
	tos++;
	data[tos] = element;
}
template <class type, class type2> type Mystack<type,type2>::pop(){
	type n = data[tos];
	tos--;
	return n;
}
int main(){
	Mystack<int,double> my;
	my.push(1);
	my.push(2);
	my.push(3);
	
	cout<<my.pop()<<endl;
}