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
    // indivisually diclairing functions as friends 
    // friend int addition::sumRealComplex(complex, complex);

    // alteret :-  we cal declair whole class as a friend 
    friend class addition;


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
    complex a1, b2;
    a1.setInput(4, 7);
    b2.setInput(9, 5);
    addition an;
    int ans = an.sumRealComplex(a1, b2);
    cout<< "Addition is :-" << ans << endl;

    return 0;
}
