#include <iostream>

class MyClass {
public:
    int* data;
    MyClass() : data(nullptr){}
void allocate(int size) {
    makenull();
    data = new int[size];
   for (int i = 0; i < size; ++i) {
    data[i] = i; }
    }
void makenull() {
        delete[] data;
        data = nullptr; }
void display() const {
    if (data) {
      std::cout << "Data: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << data[i] << " ";}
        std::cout << std::endl;
        } else {
        std::cout << "No data allocated." << std::endl;}}
};
int main() {
MyClass obj;
obj.allocate(10);
obj.display();
obj.makenull();
obj.display();
    return 0;
}
