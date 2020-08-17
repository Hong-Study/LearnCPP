#include<iostream>

struct StructCirle{
    private:
    int radius;

    public:
    StructCirle(int r) { radius = r; }
    double getArea();
};

double StructCirle::getArea(){ return 3.14*radius*radius; }

int main(){
    StructCirle waffle(3);
    std::cout<< waffle.getArea() << std::endl;
}