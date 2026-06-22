#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string username, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
    public:
    void Login();
    void signUp();
    void forget();
}obj;


int main(){
    char choice;
    cout<<"\n1- Login";
    cout<<"\n2- Sgin-Up";
    cout<<"\n3- Forgot Password";
    cout<<"\n4- Exit";
    cout<<"\nEnter your choice: ";
    cin>>choice;

    switch(choice){
        case '1':
            cin.ignore();
            obj.Login();
        break;
        case '2':
            cin.ignore();
            obj.signUp();
        break;
        case '3':
            cin.ignore();
            obj.forget();
        break;
        case '4':
            return 0;
        break;
        default:
            cout<<"Invalid seleection";
    }
}

void temp :: signUp(){
    cout<<"Enter your username:";
    getline(cin, username);
    cout<<"\nEnter Your Email Address: ";
    getline(cin, Email);
    cout<<"Enter your password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios :: app);
    file<<username<<"*"<<Email<<"*"<<password<<endl;
    file.close();
}

void temp :: Login(){
    cout<<"----------------------------\n";
    cout<<"         LOGIN              \n";
    cout<<"----------------------------\n";

    cout<<"Enter your username : ";
    getline(cin, searchName);
    cout<<"Enter your password : ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios :: in);
    getline(file, username, '*');
    getline(file, Email,'*');
    getline(file,password);
    while(!file.eof()){
        if(username == searchName){
            if(password == searchPass){
                cout<<"\nAccount Login Successfully.......!!";
                cout<<"\nUsername : "<<username;
                cout<<"\nEmail : "<<Email;
            } else{
                cout<<"Password is incorrect";
            }
        }
        getline(file,username,'*');
        getline(file,Email,'*');
        getline(file,password);
    }
    file.close();
}

void temp :: forget(){
    cout<<"\nEnter your username : ";
    getline(cin, searchName);
    cout<<"\nEnter your Email Address : ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    getline(file, username, '*');
    getline(file, Email, '*');
    getline(file, password);
    while(!file.eof()){
        if(username == searchName){
            if(Email == searchEmail){
                cout<<"\n account found"<<endl;
                cout<<"\nYour password is : "<<password;
                break;
            } else{
                cout<<"Not found.....!!\n";
            }
        } else{
            cout<<"Account not found\n";
        }
    }
    file.close();

}
