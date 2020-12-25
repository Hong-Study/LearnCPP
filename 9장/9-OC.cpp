#include<iostream>
#include<random>
using namespace std;

random_device rd;
mt19937_64 mt(rd());
uniform_int_distribution<int> range(0, 3);

class GameObject{
	protected:
	int distance;
	int x,y;
	
	public:
	GameObject(int startx, int starty, int distance){
		this->x = startx; this->y = starty; this->distance = distance;
	}
	virtual ~GameObject() {};
	
	virtual void move() = 0;
	virtual char getShape() = 0;
	
	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject *p){
		if(this->x == p->getX() && this->y == p->getY())
			return true;
		else
			return false;
	}
};

class Human : public GameObject{
	
	public:
	Human(int x,int y, int distance) : GameObject(x-1, y-1, distance) {};
	void move(){
		char a;
		cout<<"왼쪽(a), 아래(s), 위(d), 오른쪽(f) >> ";
		cin >> a;
		if(a == 'a'){
			if(y!=0)
				y-=distance;
			else
				cout<<"다시 입력해"<<endl;
		}
		else if(a == 's'){
			if(x!=9)
				x+=distance;
			else
				cout<<"다시 입력해"<<endl;
		}
		else if(a == 'd'){
			if(x!=0)
				x-=distance;
			else
				cout<<"다시 입력해"<<endl;
		}
		else if(a == 'f'){
			if(y!=19)
				y+=distance;
			else
				cout<<"다시 입력해"<<endl;
		}
	}
	char getShape(){
		return 'H';
	}
};
class Monster : public GameObject{			//멈춰 있는 경우가 있음 (왓다가갔다.)
	
	public:
	Monster(int x,int y, int distance) : GameObject(x-1, y-1, distance) {};
	void move(){
		
		for(int i = 0;i<2;i++){
			while(1){
				int N = range(mt);
				if(N == 0 && y > 0){
					y -= distance;
					break;
				}
				else if(N == 1 && x < 9){
					x += distance;
					break;
				}
				else if(N == 2 && x > 0){
					x -= distance;
					break;
				}
				else if(N == 3 && y < 19 ){
					y += distance;
					break;
				}
			}
		}
	}
	 char getShape(){
		 return 'M';
	 }
};
class Food : public GameObject{						//5번중에 3번 멈춤 2번 움직이는 상황이 구현 X
	public:
	Food(int x,int y, int distance) : GameObject(x-1, y-1, distance) {};
	void move(){
		int N = range(mt);
		int C = range(mt);
		if(C == 1){
			while(1){
				int N = range(mt);
				if(N == 0 && y > 0){
					y -= distance;
					break;
				}
				else if(N == 1 && x < 9){
					x += distance;
					break;
				}
				else if(N == 2 && x > 0){
					x -= distance;
					break;
				}
				else if(N == 3 && y < 19 ){
					y += distance;
					break;
				}
			}
		}
	}
	char getShape(){
		return 'F';
	}
};
class Game{
	private:
	public:
	void game(){
		Human *Hu = new Human(3,3,1);
		Monster *MO = new Monster(7,7,1);
		Food *food = new Food(8,8,1);
		while(1){
			for(int i=0;i<10;i++){
				for(int j=0;j<20;j++){
					if(i == MO->getX() && j == MO->getY())
						cout<< MO->getShape();
					else if(i == Hu->getX() && j == Hu->getY())
						cout<< Hu->getShape();
					else if(i == food->getX() && j == food->getY())
						cout<< food->getShape();
					else
						cout<<'-';
				}
				cout<<endl;
			}
			if(MO->collide(Hu)){
				cout<<"몬스터가 이겼습니다!"<<endl;
				break;
			}else if(MO->collide(food)){
				cout<<"몬스터가 이겼습니다!"<<endl;
				break;
			}else if(Hu->collide(food)){
				cout<<"인간이 이겼습니다!"<<endl;
				break;
			}
			
			Hu->move();
			MO->move();
			food->move();
		}
	}
};
int main(){
	Game g;
	g.game();
}