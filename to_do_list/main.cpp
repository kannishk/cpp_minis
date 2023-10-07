//to do list
#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include<string>
using namespace std;
void addtodo();

void readData();
int searchData();
void deleteData();
void updateData();

int ID;
struct todo{
    int id;
    string task;
};
void print(todo s);

int main(){
    system("clear");
    cout<<"To Do List"<<endl;
    ifstream read;
    read.open("id.txt");
    if(!read.fail()){
        read>>ID;
    }
    else{
        ID=0;
    }
    read.close();

    while(true){
        cout<<endl<<endl;
        cout << "1.Add student data"<<endl;
        cout << "2.See student data"<<endl;
        cout << "3.Search student data"<<endl;
        cout << "4.Delete student data"<<endl;
        cout << "5.Update"<<endl;
    
    int choice;
    cout<<"Enter Choice"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            addtodo(); break;
        case 2:
            readData(); break;
        case 3:
            searchData(); break;
        case 4:
            deleteData(); break;
        case 5:
            updateData(); break;
    }
    }
    return 0;
}

void addtodo(){
    system("clear");
    todo todo;
    cout<<"Enter New Task "<<endl;
    cin.get();
    getline(cin,todo.task);
    ID++;

    ofstream write;
    write.open("todo.txt",ios::app);
    write<<"\n"<<ID;
    write<<"\n"<<todo.task;
    write.close();

    write.open("id.txt");
    write<<ID;
    write.close();

    char ch;
    cout<<"Want more?"<<endl;
    cin>>ch;

    if(ch=='y'){
        addtodo();
    }else{
        cout<<"Task has been added succesfully"<<endl;
        return;
    }
}

void print(todo s){
    cout<<"\n\t"<<s.id;
    cout<<"\n\t"<<s.task;
}

void readData(){
    system("clear");
    todo todo;
    ifstream read;
    read.open("todo.txt");
    while(!read.eof()){
        read>>todo.id;
        read.ignore();
        getline(read,todo.task);
        print(todo);
    }
    read.close();
}

int searchData(){
    system("clear");
    int id;
    cout<<"enter id"<<endl;
    cin>>id;
    todo todo;
    ifstream read;
    read.open("todo.txt");
    while(!read.eof()){
        read>>todo.id;
        read.ignore();
        getline(read,todo.task);
        if(todo.id==id){
            print(todo);
            return id;
        }
    }
    return -1;
}

void deleteData(){
    system("clear");
    int id = searchData();
    cout<<"Wanna delete"<<endl;
    char choice;
    cin>>choice;
    if(choice=='y'){
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        while(!read.eof()){
            read>>todo.id;
            read.ignore();
            getline(read,todo.task);
            if(todo.id != id){
                tempFile<<"\n"<<todo.id;
                tempFile<<"\n"<<todo.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt","todo.txt");
        cout<<"Deleted"<<endl;
    }else{
        cout<<"Not found"<<endl;
    }
}

void updateData(){
    system("clear");
    int id=searchData();
    if(id != -1){
        cout<<"wanna Update"<<endl;
        char choice;
        cin>>choice;
        if(choice=='y'){
            todo newData;
            cout<<"enter task"<<endl;
            cin.get();
            getline(cin,newData.task);
            todo todo;
            ofstream tempFile;
            tempFile.open("temp.txt");
            ifstream read;
            read.open("todo.txt");
            while(!read.eof()){
                read>>todo.id;
                read.ignore();
                getline(read,todo.task);
                if(todo.id != id){
                    tempFile<<"\n"<<todo.id;
                    tempFile<<"\n"<<todo.task;
                }else{
                    tempFile<<"\n"<<todo.id;
                    tempFile<<"\n"<<newData.task;
                }
            }
            read.close();
            tempFile.close();
            remove("todo.txt");
            rename("temp.txt","todo.txt");
            cout<<"Success"<<endl;
        }else{
            cout<<"Not Updated"<<endl;
        }
    }else{
        cout<<"invalid"<<endl;
    }
}