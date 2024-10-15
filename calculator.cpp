#include<iostream>
using namespace std ;
int main (){
    int a ,b ;
    cout <<"enter the value of a ";
    cin>> a;
    cout << " enter thr value of b ";
    cin>> b;
    char op;
    cout<< "enter the operation ";
    cin >> op;
    switch(op){
        case '+': cout <<(a+b) << endl;
        break;

        case '-': cout<<(a-b) << endl;
        break;

        case '*': cout <<(a*b) << endl;
        break;

        case '/':cout <<(a/b) << endl;
          break;
        
        default: cout<<"Please enter a valid operation" << endl;

    }

}