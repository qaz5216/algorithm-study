#include <iostream>
#include <memory>
using namespace std;

struct A {
    string name;

    A(const string& n) : name(n) {
        cout << "[생성] " << name << endl;
    }

    ~A() {
        cout << "[소멸] " << name << endl;
    }

    void sayHello() const {
        cout << "안녕하세요, 저는 " << name << "입니다.\n";
    }
};

int main() {
    cout << "--- unique_ptr 예제 ---\n";
    unique_ptr<A> u1 = make_unique<A>("철수");
    u1->sayHello();

    // 이동만 가능
    unique_ptr<A> u2 = move(u1);
    if (!u1) cout << "u1은 이제 nullptr\n";

    cout << "--- shared_ptr 예제 ---\n";
    shared_ptr<A> s1 = make_shared<A>("영희");
    {
        shared_ptr<A> s2 = s1;
        shared_ptr<A> s3 = s2;

        cout << "s1.use_count(): " << s1.use_count() << endl;
        cout << "s2.use_count(): " << s2.use_count() << endl;
        cout << "s3.use_count(): " << s3.use_count() << endl;
    } // s2, s3 소멸

    cout << "s1.use_count(): " << s1.use_count() << endl;

    cout << "--- weak_ptr 예제 ---\n";
    weak_ptr<A> w1 = s1;

    if (auto sp = w1.lock()) {
        cout << "객체 살아있음 → ";
        sp->sayHello();
    }

    s1.reset(); // 소유권 포기 → A 소멸

    if (w1.expired()) {
        cout << "객체는 소멸되었음 (weak_ptr 감지)\n";
    }

    cout << "--- 종료 ---\n";
    return 0;
}
