#include <iostream>
using namespace std;
class tmp{ //to show implicit desctructors.
    
public :
    tmp() {}
    ~tmp() {cout << "Tmp Destructor called" << endl;}
};
class X {
private :
    int a;
    int b;
    tmp t;
public :
    X() { a = 0; }
    X(int a,int b) { this->a = a; this->b = b;}
    //X(X &s) {}
    //~X() { cout << "Destructor called" << endl;}
    
    int getValuea() {
        return a;
    }
    int getValueb() {
        return b;
    }
};

int main() {
	
	cout << "****************** Implicit Assignment Operators. *******************" << endl;
	cout << "Implicit Assignment Operator for Base Types Copies the values " << endl;
	int x=10;
	int y = x;	
	cout << "x = " << x << " y = " << y << endl;
	cout << "Implicit Destructor for base types does nothing  " << endl;
	
	cout << "Implicit Assignment Operator for pointer types copies the pointer values(not the objects itself) " << endl;
	int *xp = new int(5);
	int *yp = xp;
	cout << "*xp = " << *xp << " *yp = " << *yp << endl;
	cout << "Implicit Destructor for pointer types does nothing(no memory is deallocated)  " << endl;

	cout << "Implicit Assignment for Objects simply calls Assignment Operator of the class" << endl;
	X x_obj(111,222);
	X y_obj = x_obj;
	cout << "x_obj = " << x_obj.getValuea() << " " << x_obj.getValueb() << " y_obj = " << y_obj.getValuea() << " " << y_obj.getValueb() << endl;
	cout << "For Object type implicit Destructor is called first and then memberwise destructors are called.  " << endl;
	return 0;
}