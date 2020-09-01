#include<iostream>

class Stack{
	private:
	int i;
	int stack[100];
	public:
	Stack(){ i = 0; }
	Stack& operator << (int n);
	Stack& operator >> (int &n);
	bool operator !();
};

Stack& Stack::operator <<(int n){
	stack[i] = n;
	i++;
	return *this;
}
Stack& Stack::operator >>(int &n){
	i--;
	n = stack[i];
	return *this;
}
bool Stack::operator !(){
	if(i==0)
		return true;
	else
		return false;
}

int main(){
	Stack stack;
	stack<<3<<5<<10;
	while(true){
		if(!stack) break;
		int x;
		stack >> x;
		std::cout<< x <<' ';
	}
	std::cout<<std::endl;
}