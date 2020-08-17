#include<iostream>

class Circle{
    private:
    int radius;
    public:
    double getArea();
    void get_radius(int a);
};
double Circle::getArea(){
    return 3.14*radius*radius;
}
void Circle::get_radius(int a){
    radius = a;
}

int main(){
    Circle one;
    one.get_radius(5);
    std::cout<<one.getArea();
}