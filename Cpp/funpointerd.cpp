#include <iostream>
using namespace std;


void display(float (*fptr)(int),int r){
    cout<<"THe area of circle is :" << (*fptr)(r);
}

float area(int r){
    return 3.14*r*r;
    
}


int main(){
   void display(float(*)(int),int);
   float area(int);
   int r;
   cout<<"Enter the Radius :"<<endl;
   cin>>r;
   display(area,r);
   return 0;
}

