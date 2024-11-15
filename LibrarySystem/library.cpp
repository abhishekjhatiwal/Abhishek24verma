#include<iostream>
#include<fstream>
using namespace std;

class Temp{
    string id,name,author,search;
    fstream file;
public :
    void addBook();
    void showAll();
    void ExtractBook();
}obj;

int main(){
    char choice;
    cout<<"==================================================\n";
    cout<<"1-Show AllBooks\n";
    cout<<"2- Extract Book\n";
    cout<<"3-Add Books(ADMIN)\n";
    cout<<"4-Exit\n";
    cout<<"===================================================\n";
    cout<<"Enter your Choice : ";
    cin>>choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.showAll();
        break;
    case '2':
        cin.ignore();
        obj.ExtractBook();
        break;
    case '3':
        cin.ignore();
        obj.addBook();
        break;
    case '4':
        return 0;
        break;
    default:
        cout<<"Invalid Choice....! \n";
        break;
    }

    return 0;
}

void Temp ::addBook(){
    cout<<"\nENter Book ID : ";
    getline(cin,id);
    cout<<"Enter Book Name : ";
    getline(cin,name);
    cout<<"Enter Book's Author name : ";
    getline(cin,author);

    file.open("bookData.txt",ios::out | ios::app);
    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();
}

void Temp::showAll(){
    file.open("bookData.txt",ios::in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'*');
    cout<<"\n\n";
    cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name ";
    while (!file.eof())
    {
        cout<<"\t\t "<<id<<"\t\t "<<name<<" \t\t "<<author<<endl;
        getline(file,id,'*');
        getline(file,name,'*');
        getline(file,author,'*');
    }
    file.close();
}

void Temp ::ExtractBook(){
    showAll();
    cout<<"Enter Book Id : ";
    getline(cin,search);

    file.open("bookData.txt",ios::in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');

    cout<<"\n\n";
    cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name "<<endl;
    while (!file.eof())
    {
        if (search  == id)
        {
            cout<<"\t\t "<<id<<"\t\t\t "<<name<<"\t\t\t "<<author<<endl;
            cout<<"Book Extracted Successfully.....!";
        }
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    }
    file.close();
}