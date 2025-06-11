#include<iostream> 

using namespace std;

int main()
{
    int x=12;
    cout<< x<<"\n";
    x=x &(-x);
    cout << x;
    return 0;
}
// -,30,29,28        ....... 15,14,13,12 11,10,9,8 7654 3210
//  // -1