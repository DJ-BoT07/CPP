#include <iostream>
using namespace std;

class Test
{
private:
    int data;
public:
    Test(int data){
        this ->data = data;
    }

    void access()
    {
        cout<<"Data :"<<this->data <<endl;
    }
};


int main()
{
    // Test obj(100);
    // Test *ptr_obj; // Declare ptr_obj as a pointer to a Test object
    // ptr_obj = &obj; // Assign the address of obj to ptr_obj

    // cout << "Value: " << endl;
    // cout << ptr_obj->getValue(); // Access getValue() through the pointer
    Test obj(100);
    Test obj2(50);

    obj.access();
    obj2.access();
    return 0;
}
