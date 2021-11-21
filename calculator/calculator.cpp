#include<conio.h>
#include<iostream>
using namespace std;

class complex  //complex number
{
private:
    int a, b;   // a+bi
public:
    complex (int x, int y)
    {
        a = x; b = y;
    }

    complex (){}

    void set_data()
    {
        cin >> a >> b; 
    }

    complex operator+(complex c) // + operator overloading.. additing complex numbers
    {
        complex temp;
        temp.a = a + c.a;
        temp.b = b + c.b;
        return(temp);
    }
    complex operator-(complex c) // - operator overloading to subtract complex numbers
    {
        complex temp;
        temp.a = a - c.a;
        temp.b = b - c.b;
        return(temp);
     }

    void show_data()
    {
        if (b>=0 || a>=0)
        {
            cout << "= " << a << "+" << b << "i" << endl;
        }
        else
        {
            cout << "= " << a << b << "i" << endl;
        }
    }
    complex operation(complex c1, char op, complex c2)
    {
        switch (op)
        {
        case '+':
            c1 = c1 + c2;
            break;

        case '-':
            c1 = c1 - c2;
            break;

        /*case '=': c1 = (********) ? (c1 = c1 + c2) : (c1 = c1 - c2);
            break;*/

        default:
            c1 = c2;
            cout << "wrong operator" << endl;
            break;
        }
        return (c1);
    }
};
int main(int argc, char const* argv[])
{
    int n; char op='+';
    complex c1(0, 0);
    do
    {
    cout << "How many complex numbers you want to calculate:  ";
    cin >> n;
    complex* p = new complex[n];  //dynamic memory allocation

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the complex number " << i + 1 << endl;
        p[i].set_data();
        c1 = c1.operation(c1,op,p[i]);
        cin >> op;
        c1.show_data();
    }
    
    cout << "\nDo another? (y/n): ";
    cin >> op;

    delete [] p;
    p = NULL;
 
    } while (op !='n'); //op== 'y'
    
    return 0;
}

