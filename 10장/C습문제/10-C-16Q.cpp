#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Shape{	
	protected:
	virtual void draw() = 0;
	
	public:
	void paint(){ draw(); }

};

class Circle : public Shape{
	protected:
	virtual void draw(){
		cout << "Circle" << endl;
	}
};
class Rect : public Shape{
	protected:
	virtual void draw(){
		cout << "Rect" << endl;
	}
};
class Line : public Shape{
	protected:
	virtual void draw(){
		cout << "Line" << endl;
	}
};

int main(){
	vector<Shape*> v;
	
	int n;
	int choice;
	while(n!=4){
		cout<<"삽입 : 1, 삭제 : 2, 모두보기 : 3, 종료 : 4 >> ";
		cin >> n;
		if(n==1){
			cout<<"선 : 1, 원 : 2, 사각형 : 3 >>";
			cin >> choice;
			if(choice == 1){
				v.push_back(new Line());
			}else if(choice == 2){
				v.push_back(new Circle());
			}else if(choice == 3){
				v.push_back(new Rect());
			}
		}else if(n==2){
			cout<<"삭제하고자 하는 도형의 인덱스 >> ";
			cin >> choice;
			auto it = v.begin()+choice;
			it = v.erase(it);
		}else if(n==3){
			for(int i=0;i<v.size();i++){
				cout<<i<<": ";
				v[i]->paint();
			}
		}
	}
}