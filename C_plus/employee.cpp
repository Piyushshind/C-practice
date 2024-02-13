#include <iostream>
using namespace std;

class employee
{
private:
    int a, b, c;

public:
    int d, f;

    void setData(int a1, int b2, int c3);
    void printData()
    {
        cout << "data is " << a << endl;
        cout << "data is " << b << endl;
        cout << "data is " << c << endl;
        cout << "data is " << d << endl;
        cout << "data is " << f << endl;
    }
};

void employee ::setData(int a1, int b2, int c3)
{
    a = a1;
    b = b2;
    c = c3;
};

int main()
{
    employee piyush;
    piyush.setData(4, 5, 6);
    piyush.d = 78;
    piyush.f = 59;
    piyush.printData();
    return 0;
}