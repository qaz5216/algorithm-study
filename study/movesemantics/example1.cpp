#include <iostream>

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
        cout << "--- a1 생성 ---\n";
    A a1("a1", 1);

    cout << "--- a2 복사 생성 ---\n";
    A a2 = a1;  // 복사 생성자

    cout << "--- a3 이동 생성 ---\n";
    A a3(std::move(a1));  // 이동 생성자

    cout << "--- a4 기본 생성 + 복사 대입 ---\n";
    A a4;
    a4 = a2;  // 복사 대입 연산자

    cout << "--- a5 기본 생성 + 이동 대입 ---\n";
    A a5;
    a5 = std::move(a2);  // 이동 대입 연산자

    cout << "--- 종료 ---\n";

    return 0;
}