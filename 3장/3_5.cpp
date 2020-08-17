#include<iostream>

class Rectangle{
    private:
    int width;
    int height;

    public:
    Rectangle();
    Rectangle(int a,int b);
    Rectangle(int a);
    bool isSqurare();
};

Rectangle::Rectangle() : Rectangle(5,5) {};
Rectangle::Rectangle(int a) : Rectangle(a,a) {};
Rectangle::Rectangle(int a,int b) : width(a), height(b) {};

bool Rectangle::isSqurare(){
    if(width == height)
        return true;
    else
        return false;
}

int main(){
    Rectangle rect1;
    Rectangle rect2(3,5);
    Rectangle rect3(3);

    if(rect1.isSqurare()) std::cout<< "rect1은 정사각형이다." <<std::endl;
    if(rect2.isSqurare()) std::cout<< "rect2은 정사각형이다." <<std::endl;
    if(rect3.isSqurare()) std::cout<< "rect3은 정사각형이다." <<std::endl;
}