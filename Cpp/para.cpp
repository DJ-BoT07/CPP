#include <iostream>
using namespace std;

class Test{
    private:
            int height,width;
    public:
        Test(int h,int w){
            height = h;
            width = w;
        }


        int area(){
            return (height * width);
        }
};


int main(){
   Test t1(5,3);
   cout<<t1.area();
   return 0;
}