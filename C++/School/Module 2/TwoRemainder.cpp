#include <iostream>
using namespace std;
int main(int argc, char** argv) {
      int remainder=0, decimal=0;
     char again='y';
    while(again!='n'){
       system("CLS"); 
           cout<<"Enter a number: "; cin>>decimal;
           remainder = decimal %2;
           cout<<"remainder: "<<remainder<<endl;
         cout<<"Try Again[y/n]: "; cin>>again;
    } 
   system("pause");
   return 0;
}