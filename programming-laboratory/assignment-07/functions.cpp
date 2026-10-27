#include <iostream>
using namespace std;
const int PI = 3.14159265;

//Function Declaration
double get_area(double radius);

int main(){
    double radius1 = 1.1, area1, area2;
    area1 = get_area(radius1);
    cout << "Area 1 is " << area1 << endl;
    area2 = get_area(2.2);
    double radius2 = 2.2;
    cout << "Area 2 is " << area2 << endl;
    double area3 = get_area(3.3);
    cout << "Area 3 is " << area3 << endl;
    return 0;
}

//Function Definition
//Return the area of a circle based on its radius
double get_area (double radius){
    return PI * radius * radius;
}