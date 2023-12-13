#include <iostream>
using namespace std;

class Complex
{
    double real; 
    double img;

public:
    Complex();                                              // Default Constructor
    friend istream &operator>>(istream &, Complex &);       // Input
    friend ostream &operator<<(ostream &, const Complex &); // Output
    Complex operator+(Complex);                             // Addition
    Complex operator*(Complex);
};
Complex::Complex()
{
    real = 0;
    img = 0;
}

istream &operator>>(istream &, Complex &i)
{
    cin >> i.real >> i.img;
    return cin;
}
ostream &operator<<(ostream &, const Complex &c)
{
    cout << c.real << " + i" << c.img << endl;
    return cout;
}

Complex Complex::operator+(Complex c1){
    Complex temp;
    temp.real=real+c1.real;
    temp.img=img+c1.img;
    return temp;
}

Complex Complex::operator*(Complex d){
    Complex temp;
    temp.real=(real*d.real)-(img*d.img);
    temp.img=(real*d.img)+(img*d.real);
    return temp;
}

int main()
{
    Complex c1, c2, c3, c4;
    cout << "Enter the first complex number : ";
    cin >> c1;
    cout << "\nEnter the second complex number : ";
    cin >> c2;
    cout << "\nSum of two numbers is : \t";
    c3 = c1 + c2;
    cout << c3;
    cout << "\nProduct of two numbers is : \t";
    c4 = c1 * c2;
    cout << c4;
    return 0;
}