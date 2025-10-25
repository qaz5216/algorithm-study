#include <iostream>
#include <vector>

using namespace std;

struct A{
    string name;
    int value;
public:
    A(){
        name="defalut";
        value=10;
        cout<<"기본생성자\n";
    }
    A(string n,int v){
        name=n;
        value=v;
        cout<<"사용자 정의 생성자\n";
    }
    A(const A& other){
        name = other.name;
        value = other.value;
        cout<<"복사 생성자\n";
    }
    A(A&& other) noexcept {
        name = move(other.name);
        value = other.value;
        cout << "이동 생성자 호출\n";
    }
    A& operator=(const A& other) {
        cout << "복사 대입 연산자 호출\n";
        name = other.name;
        value = other.value;
        return *this;
    }
    A& operator=(A&& other) noexcept {
        cout << "이동 대입 연산자 호출\n";
        name = move(other.name);
        value = other.value;
        return *this;
    }
    ~A(){
        cout<<"소멸자 호출\n";
    }
};

int main()
{
    string str="hi";
    
    vector<A> arr;
    vector<A> vec;
    arr.reserve(5);
    for(int i=0;i<10;i++){
        arr.push_back(A(str,i));
    }
    cout<<"push_back\n";
    vec.reserve(10);
    for(int i=0;i<10;i++){
        vec.push_back(arr[i]);
    }
    vec.resize(0);
    cout<<"emplace_back\n";
    for(int i=0;i<10;i++){
        vec.emplace_back("hi",i);
    }
    vec.resize(0);
    cout<<"push_back_move\n";
    for(int i=0;i<10;i++){
        vec.push_back(move(arr[i]));
    }
    cout<<"push_back_move_finish\n";
    return 0;
}