#include<iostream>
#include<string>
#include<fstream>
#include<cstdio>
using namespace std;


void login();
void menu(string member, string data);


void signup(string member, string data){
    system("clear");
    int id,pos_num;
    string name;
    cout<<"|========================|"<<endl;
    cout<<"|     LIBRARY SYSTEM     |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<"|       SIGNING UP...    |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<" ENTER YOUR 5 DIGIT ID:";
    cin.ignore();
    cin>>id;
    string id_str = to_string(id);
    if(id_str.length() > 5){
    cout<<" ERROR: ID MUST ONLY BE 5 DIGITS LONG"<<endl;
    cout<<" CLICK ENTER TO RETRY...  "<<endl;
    cin.ignore();
    getchar();
    signup(member, data);
    }


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
    cin>>pos_num;

    string position;
    if(pos_num == 1){
        position = "Teacher";
    }
    else if(pos_num == 2){
        position = "Student";
    }
    else{
    cout<<"|========================|"<<endl;
    cout<<"|     LIBRARY SYSTEM     |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<"|       SIGNING UP...    |"<<endl;
    cout<<"|========================|"<<endl;
    cout<<" ERROR: ONLY TYPE 1 OR 2  "<<endl;
    cout<<" CLICK ENTER TO RETRY...  "<<endl;
    cin.ignore();
    getchar();
    signup(member, data);
    }

//Identify the last index of file
int start_index = 0;
    ifstream inFile(member);
    if(inFile){
        string row;
        while(getline(inFile, row)){
            if(row.substr(0,5) == "INDEX"){ //Skips the header row
                continue;
            }
            //Isolates index and converts to Integer
            int i = stoi(row.substr(0, row.find(",")));
            if (i > start_index){
            // index = i allows the next written data to be +1 in file
                start_index = i;
            }
        }
        inFile.close();
    }


    ofstream ofFile(member, ios::app);
    if(ofFile){
        if(start_index == 0){//0 index means file is completely empty
            ofFile << "INDEX,ID,NAME,POSITION" <<endl;
        } //Insertion of Data
        ofFile << start_index + 1 << "," << id << "," << name << "," << position <<endl;
        ofFile.close();
    }
    else{
        cout<<"ERROR: FILE NOT FOUND"<<endl;
    }
    system("clear");
    cout<<"ACCOUNT SUCCESSFULY CREATED"<<endl;
    menu(member, data);
}
void menu_err(string member, string data){
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
    menu(member, data);
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
    menu_err(member, data);
    }
}


int main(){
    system("clear");
    string member = "LibSys_Member.csv";
    string data = "LibSys_Data.csv";
    menu(member, data);

    return 0;
}