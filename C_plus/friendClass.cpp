#include <iostream>
using namespace std;

class complex;
class addition
{
public:
    int add(int n1, int n2)
    {
        return (n1 + n2);
    }
    int sumRealComplex(complex, complex);
};

class complex
{
    int a, b;
    friend int addition::sumRealComplex(complex, complex);

public:
    void setInput(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
};

int addition::sumRealComplex(complex o1, complex o2)
{
    return (o1.a + o2.a);
};

int main()
{

    return 0;
}
