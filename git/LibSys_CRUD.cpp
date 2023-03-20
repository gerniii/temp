#include<iostream>
#include<string>
#include<fstream>
#include<cstdio>
using namespace std;


void login();
void signup();
void menu();


void menu_err(){
    int choice;
    system("clear");
    cin.ignore();
    cout<<"|========================|"<<endl;
    cout<<"|     LIBRARY SYSTEM     |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<"|1. Log in               |"<<endl;
    cout<<"|2. Sign up              |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<"|  !!!INVALID CHOICE!!!  |"<<endl;
    cout<<" Press enter to continue.."<<endl;
    getchar();
    menu();
}


void menu(){
    system("clear");
    int choice;
    cout<<"|========================|"<<endl;
    cout<<"|     LIBRARY SYSTEM     |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<"|1. Log in               |"<<endl;
    cout<<"|2. Sign up              |"<<endl;
    cout<<"|========================|"<<endl<<endl;
    cout<<" Choose an option>> ";
    cin>>choice;

    if(choice == 1){
    //login();
    }
    else if(choice == 2){
    //signup();
    }
    else{
    menu_err();
    }
}

















int main(){
    system("clear");
    string member = "LibSys_Member.csv";
    string data = "LibSys_Data.csv";
    menu();

    return 0;
}