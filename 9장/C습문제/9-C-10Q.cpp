#include<iostream>
#include<string>

using namespace std;

class Shape{
	Shape *next;
	
	protected:
	virtual void draw() = 0;
	
	public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	void paint(){ draw(); }
	Shape* add(Shape* p){
		this->next = p;
		return p;
	}
	Shape* getNext(){ return next; }
};

class Circle : public Shape{
	protected:
	void draw(){
		cout << "Circle" << endl;
	}
};
class Rect : public Shape{
	protected:
	void draw(){
		cout << "Rect" << endl;
	}
};
class Line : public Shape{
	protected:
	void draw(){
		cout << "Line" << endl;
	}
};
class UI{
	static int Choice;
	public:
	static int print(){
		cout<<"삽입 : 1, 삭제 : 2, 모두보기 : 3, 종료 : 4 >> ";
		cin >> Choice;
		return Choice;
	}
	static int Insert(){
		cout<<"선 : 1, 원 : 2, 사각형 : 3 >>";
		cin >> Choice;
		return Choice;
	}
	static int Delete(){
		cout<<"삭제하고자 하는 도형의 인덱스 >> ";
		cin >> Choice;
		return Choice;
	}
};
int UI::Choice = 0;
class GraphicEditor{
	UI ui;
	int n, c;
	Shape* pStart = NULL;
	Shape* pLast = NULL;
	public:
	void Play(){
		while(1){
			n = ui.print();
			if(n == 1){
				c = ui.Insert();
				if(c == 1){
					if(pStart == NULL){
						pStart = new Line();
						pLast = pStart;
					}else{
						pLast = pLast->add(new Line());
					}
				}
				else if(c == 2){
					if(pStart == NULL){
						pStart = new Circle();
						pLast = pStart;
					}else{
						pLast = pLast->add(new Circle());
					}
				}
				else if(c == 3){
					if(pStart == NULL){
						pStart = new Rect();
						pLast = pStart;
					}else{
						pLast = pLast->add(new Rect());
					}
				}
			}else if(n == 2){
				c = ui.Delete();
				if(c == 0){
					Shape *p = pStart;
					pStart = pStart -> getNext();
					delete p;
				}else{
					Shape *p = pStart;
					Shape *del;
					for(int i=1;i<c;i++){
						p = p->getNext();
					}
					del = p->getNext();
					p->add(del->getNext());
					delete del;
				}
			}else if(n == 3){
				cout<<endl;
				Shape *p = pStart;
				int count = 0 ;
				while(p != NULL){
					cout<< count <<" : ";
					p->paint();
					p = p->getNext();
					count++;
				}
				cout<<endl;
			}else if(n == 4){
				break;
			}
		}
	}
};


int main(){
	GraphicEditor graphic;
	graphic.Play();
}