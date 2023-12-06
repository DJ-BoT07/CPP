#include <iostream>
using namespace std;

class Base{
   public:
        int a;
    
};

class Derived:public Base{
        public:
            int b;
            void display(){
                cout<<"a :"<<a<<endl;
                cout<<"b :"<<b<<endl;
            }   
};


int main(){
   Derived obj;
   Derived *ptr;
   ptr = &obj;
   ptr -> a = 100;
   ptr -> b = 50;
   ptr ->display();
   return 0;
}

