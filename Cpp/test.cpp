#include <iostream>
using namespace std;



class Test{
    private:
        int a,b,c;
    public:
     int addition(int a,int b){
        c = a + b;
        return c; 
     }

     void display();

};

void Test::display(){
    cout<<"Hellooo dj"<<endl;
}

int main(){
    // int n = 10;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = n; i > n; j--)     
    //     {
    //         n = n + i +j;
    //     }
        
    // }
    Test t1;
    cout<<t1.addition(10,20)<<endl;
    t1.display();

    return 0;
}
