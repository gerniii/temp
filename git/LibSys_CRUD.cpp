#include<iostream>
#include<string>
#include<fstream>
#include<cstdio>
using namespace std;


void login();
void menu();


void signup(string member, string data){
    system("clear");
    int id;
    string name, position;
    cout<<"|========================|"<<endl;
    cout<<"|     LIBRARY SYSTEM     |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<"|       SIGNING UP...    |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<" ENTER YOUR ID:";
    cin.ignore();
    cin>>id;

    system("clear");
    cout<<"|========================|"<<endl;
    cout<<"|     LIBRARY SYSTEM     |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<"|       SIGNING UP...    |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<" ENTER YOUR NAME:";
    cin.ignore();
    getline(cin, name);

    system("clear");
    cout<<"|========================|"<<endl;
    cout<<"|     LIBRARY SYSTEM     |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<"|       SIGNING UP...    |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<" ENTER YOUR POSITION:"<<endl;
    cout<<" 1. Teacher"<<endl;
    cout<<" 2. Student"<<endl;
    cout<<" >> ";
    cin.ignore();
    getline(cin, position);

//Identify the last index of file
int index = 0;
    ifstream inFile(member);
    if(inFile){
        string row;
        while(getline(inFile, row)){
            if(row.substr(0,5) == "Index"){ //Skips the header row
                continue;
            }
            //Isolates index and converts to Integer
            int i = stoi(row.substr(0,row.find(",")));
            if (i > index){
            // index = i allows the next wrriten book to be +1 in file
                index = i;
            }
        }
        inFile.close();
    }

    ofstream ofFile(member);
    if(ofFile){
        if(index == 0){//0 index means file is completely empty
            ofFile << "INDEX,ID,NAME,POSITION" <<endl;
        } //Insertion of Data
        ofFile << index + 1 << "," << id << "," << name << "," << position <<endl;
        ofFile.close();
    }
    else{
        cout<<"ERROR: FILE NOT FOUND"<<endl;
    }

    cout<<"ACCOUNT SUCCESSFULY CREATED"<<endl;
    menu();
}





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
    system("clear");
    menu();
}


void menu(string member,string data){
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
    signup(member, data);
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