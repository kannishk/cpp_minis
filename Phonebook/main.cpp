#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<conio.h>

using namespace std;

void menu();
void addNum();
void showRecords();
void searchWithSerialNumber();
void recordDeletion();
void updateRecord();
class PhoneBook{
    int srno;
    char n[28];
    char m[17];
    char e[40];
    char g[30];

    public:
    int getSrNo(){ return srno;}
    void storeData(){
        cout<<"\n....Create new Phone Record....\n";
        cout<<"Enter Serial Number  ";
        cin>>srno; cin.ignore();
        cout<<"Enter Record Name  ";
        cin.getline(n,28);
        cout<<"Enter Mobile Number  ";
        cin.getline(m,17);
        cout<<"Enter Email ID  ";
        cin.getline(e,40);
        cout<<"Enter Record Group ";
        cin.getline(g,30);
        cout<<endl;
    }
    void showData(){
        cout<<"\n...............PHONE BOOK RECORD...............\n";
        cout<<"Sr. No.    : "<<srno<<endl;
        cout<<"Name       : "<<n<<endl;
        cout<<"Mobile No. : "<<m<<endl;
        cout<<"Email ID   : "<<e<<endl;
        cout<<"Group      : "<<g<<endl;
    }
}x;


void addNum(){
    ofstream fout;
    fout.open("Phonebook.dat",ios::out|ios::binary|ios::app);
    x.storeData();
    fout.write((char*)&x,sizeof(x));
    fout.close();
    cout<<"\nRecord Saved to File...\n";
}

void showRecords(){
    ifstream fin;
    fin.open("Phonebook.dat",ios::out | ios::binary | ios::app);
    while(fin.read((char*)&x,sizeof(x))){
        x.showData();
    }
    fin.close();
    cout<<"\nReading of Data File completed...\n";
}

void searchWithSerialNumber(){
   ifstream fin;
   int n, flag=0;
   fin.open("PhoneBook.dat",ios::out|ios::binary|ios::app);
   cout<<"Enter Serial Number  ";
   cin>>n;
   while(fin.read((char*)&x,sizeof(x))){
    if(n==x.getSrNo()){
        x.showData();
        flag++;
        cout<<"\n\n..Record Found and Displayed...\n";
    }
   }
   fin.close();
   if(flag==0){
    cout<<"\nNot in File\n";
   } 
   cout<<"\nReading of Data File Completed\n";
}

void recordDeletion(){
    ifstream fin;
    ofstream fout;
    int n, flag=0;
    fin.open("PhoneBook.dat",ios::out|ios::binary|ios::app);
    fout.open("temp.dat",ios::out|ios::binary|ios::app);
    cout<<"Enter Serial Number of Record to Delet ";
    cin>>n;
    while(fin.read((char*)&x,sizeof(x))){
        if(n==x.getSrNo()){
            cout<<"\nThe Following record is Deleted...\n";
            x.showData();
            flag++;
        }else{
            fout.write((char*)&x,sizeof(x));
        }
    }
    fin.close();
    fout.close();
    if(flag==0){
        cout<<"\nThe Record of Serial Number is not there\n";
    }
    cout<<"\nReading COmpleted\n";
    remove("PhoneBook.dat");
    rename("temp.dat","PhoneBook.dat");
}

void updateRecord(){
    fstream fio;
    int n,flag=0,pos;
    fio.open("PhoneBook.dat",ios::out|ios::binary|ios::in);

    cout<<"Enter Serial Number  ";
    cin>>n;
    while(fio.read((char*)&x,sizeof(x))){
        pos=fio.tellg();
        if(n==x.getSrNo()){
            cout<<"\nThe following record will be modified\n";
            x.showData();
            flag++;
            cout<<"\nReneter the  new details...\n";
            x.storeData();
            fio.seekg(pos-sizeof(x));
            fio.write((char*)&x,sizeof(x));
            cout<<"\n..Data Modified...\n";
        }
    }
    fio.close();
    if(flag==0){
        cout<<"\nThe Record NOt found\n";
    }
    cout<<"\nReading Completed\n";
}

void menu(){
    int ch;
    do{
        cout<<"............................................\n";
        cout<<"           PHONE BOOK MANAGEMENT\n";
        cout<<"............................................\n\n";
        cout<<"::::::::::::::: PROGRAM MENU :::::::::::::::\n";
        cout<<"0. Exit\n";
        cout<<"1. Save New Phone Record\n";
        cout<<"2. Display All Saved Records\n";
        cout<<"3. Search Specific Record\n";
        cout<<"4. Delete Specific Record\n";
        cout<<"5. Modify Existing Record\n";
        cout<<"Enter Your Choice  ";
        cin>>ch;

        switch(ch){
            case 1:addNum(); break;
            case 2: showRecords(); break;
            case 3: searchWithSerialNumber(); break;
            case 4: recordDeletion(); break;
            case 5: updateRecord(); break;
        }
        getch();
    }while(ch);
}
int main(){
    menu();
    return 0;
}
