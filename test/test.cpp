#include <iostream>
#include <set>
using namespace std;

class Animal {
    public:
    Animal(){
        cout<<"Animal()"<<"\n";
    }
    virtual ~Animal(){
        cout<<"~Animal()"<<"\n";
    }
};

class Dog : public Animal {
	public:
    Dog(){
        cout<<"Dnimal()"<<"\n";
    }
    virtual ~Dog(){
        cout<<"~Dnimal()"<<"\n";
    }
};

int main()
{
    Dog d;
    return 0;
}