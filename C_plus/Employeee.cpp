#include <iostream>
using namespace std;

class Employeee
{
    static int count;
    int data;

public:
    int no;
    void getData(void)
    {
        cout << "Enter data" << endl;
        cin >> data;
        cout << "Enter no " << endl;
        cin >> no;
        count++;
    }
    void printData(void);

    static void getCount(void)
    {
        // we can only access static variables in static methods 
        cout << "Count is " << count << endl;
    }
};

void Employeee ::printData(void)
{
    cout << "Data is " << data << " No. is " << no << " and count is " << count + 1 << endl;
}

int Employeee ::count = 10;

int main()
{
    Employeee piyush, ram, dom;
    piyush.getData();
    piyush.printData();
    ram.getData();
    ram.printData();
    dom.getData();
    dom.printData();
    return 0;
}