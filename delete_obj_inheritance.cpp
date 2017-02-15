#include <iostream>
using namespace std;


/*  Base class shape
    default contructor shape()
    copy constructor shape(shape &s)
    destructor ~shape()


    Derived class square : Base class shape
    default contructor square()
    copy constructor square(square &s) : shape(s)
    destructor ~square()
	
	BASE CLASS CONTRUCTOOR GETS CALLED FIRST FOLLOWED BY DERIVED CLASS CONSTRUCTOR.
	DERIVED CLASS DESTRUCTOR GETS CALLED FIRST FOLLOWED BY BASE CLASS DESTRUCTOR.
	

*/

class shape {
private: 
    int id;
public:
    static int cnt;
	shape()	{ 
	    cnt++;
		cout << "Shape Object created :" << cnt << endl;
		id = cnt;
	}
	shape(shape &s)	{ 
	    id = s.id;
		cout << "Shape Object cloned :" << id << endl;
	}
	shape(int a){
	    cout << "Shape Object created with a = " << a <<  endl;
	}
	~shape() {
		cout << "Shape Object deleted: " << cnt << endl;
		cnt--;
	}
};
int shape::cnt = 0;

class square : shape {
public:
	square() {
		cout << "Square Object Created " << endl; 
	}
	square(square &s) : shape(s) {
		cout << "Square Object Cloned " << endl; 
	}
	square(square &s[])  {
		cout << "Square Object Array Cloned " << endl; 
	}
	~square() {
		cout << "Square Object Deleted " << endl;
	}
};

int main() {
	square s;
	square T(s);
	
	square Sarray[3];
	square Tarray(Sarray);
	return 0;
}