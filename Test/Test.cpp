#include<iostream>

int main (){
	int *array = new int [5];
	for(int i=0;i<5;i++){
		array[i] = i;
	}
	int *tmp = new int [5];
	tmp = array;
	for(int i=0;i<5;i++) std::cout<<array[i]<<std::endl;
	delete[] array;
	for(int i=0;i<5;i++) std::cout<<tmp[i];
}