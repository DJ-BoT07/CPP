#include <iostream>
using namespace std;


int main(){
   int i,n,*ptr,key,a[10];
   cout<<"Entr the nUmber of element :"<<endl;
   cin>>n;
   cout<<"Enter the array element : "<<endl;
   for ( i = 0; i < n; i++)
   {
    cin>>a[i];
   }

   ptr = &a[0];
   cout<<"Enter the KEy :"<<endl;
   cin>>key;
   for ( i = 0; i < n; i++)
   {
    if(*ptr == key){
        cout<<"Present";
        break;
    }
    else{
        ptr = ptr + 1;
    }
   }
   
   
   return 0;
}

