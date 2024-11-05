#include <iostream>
#include <vector>
using namespace std;

struct A{
    private: 
    public:
    const int a=1;
    A() {
        cout<<"A()"<<a<<"\n";
    }
    ~A() {
        cout<<"~A()"<<a<<"\n";
    }
    virtual const int* show()
    {
        cout<<"A!"<<"\n";
        cout<<&a<<"\n";
        const int* b=&a;
        return b;
    }
};
int main()
{
    vector<int> v;
    A* a=new A();
    const int* t=a->show();
    cout<<t<<"\n";
    int * my=const_cast<int *>(t);
    cout<<my<<"\n";
    cout<<*t<<"\n";
    cout<<a->a<<"\n";
    *my+=1;
    cout<<a->a<<"\n";
    delete(a);

    return 0;
}