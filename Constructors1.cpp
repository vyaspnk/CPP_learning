#include <iostream>
using namespace std;
class X {
private :
    int a;
public :
    X() { a = 0; }
    X(int a) { this->a = a; }
    ~X(){};
    
    int getValue() {
        return a;
    }
    void setValue(int a) {
        this->a = a;
    }
};

int main() {
	int x=10;
	int y(x);
	
	cout << "****************** Implicit Copy Constructors. *******************" << endl;
	cout << "Copy Constructor for Base Types Copies the values " << endl;
	cout << "x = " << x << " y = " << y << endl;
	
	int *xp = new int(5);
	int *yp(xp);
	cout << "Copy Constructor for pointer types copies the pointer values(not the objects itself) " << endl;
	cout << "*xp = " << *xp << " *yp = " << *yp << endl;
	
	cout << "Copy Constructor for Objects simply calls copy constructor" << endl;
	X x_obj(111);
	X y_obj(x_obj);
	cout << "x_obj = " << x_obj.getValue() << " y_obj = " << y_obj.getValue() << endl;

	cout << "Copy Constructor for Objects points simply calls copy constructors on pointers" << endl;
	X *xp_obj = new X(123);
	X *yp_obj(xp_obj);
	cout << "*xp_obj = " << xp_obj->getValue()<< endl;
	xp_obj->setValue(345);
	cout << "*xp_obj = " << xp_obj->getValue();
	cout << " y_obj = " << yp_obj->getValue() << endl;
	return 0;
}