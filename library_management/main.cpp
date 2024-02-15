#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<fstream>

using namespace std;

int quantity = 0;

int generateBookID(string basicString);
int generateAlphabetID(char c);
int queue_array[20];
struct BST *rack[10][5];
struct User *start = nullptr;

class Queue{
    public:
        int top;

        Queue(){
            top = -1;
        }

        bool isFull(){
            return top == 19;
        }

        bool isEmpty(){
            return top == -1;
        }

        void enQueue(int value){
            if(!isFull()){
                top++;
                queue_array[top]=value;
            }else{
                cout << "Queue is full";
            }
        }

        int deQueue(){
            int value = queue_array[0];
            for (int i = 0; i < top;++i){
                queue_array[i] = queue_array[i + 1];
            }
            top--;
            return value;
        }

        void reset(){
            top = -1;
        }

        void get_top(){
            return top;
        }
};

struct Book{
    string name;
    string author;
    int id, amount;
    int rack;
    struct Book *next;
    public:
        Book(string new_name, string new_author, int new_id, int new_rack){
            name = new_name;
            author = new_author;
            id = new_id;
            rack = new_rack;
            next = nullptr;
            amount = 1;
        }
};

struct BST{
    int id;
    struct BST *left, *right;
    struct Book *next;
    public:     
        BST(int new_id){
            id = new_id;
            left = nullptr;
            right = nullptr;
            next = nullptr;
        }
};

void generateLibraryData();
void displayLibrary(struct BST *root);
void addBook(int shelve, string book_name, string author_name);
bool deleteBook(string name, string author_name);


struct User{
    string name;
    struct Book *book;
    struct User *next;
    public: 
        User(string new_name){
            name = new_name;
            next = nullptr;
            book = nullptr;
        }
};

int main(){
    generateLibraryData();
    int choice;

    while(true){
        cout << "\n\n\n++++++++++     M E N U     ++++++++++\n";
        cout << "0. Exit\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert a Book\n";
        cout << "3. Delete a Book\n";
        cout << "4. Search Book By Name\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Display Issues\n";
        cout << "\nSelect an option : ";

        cin >> choice;

        switch(choice){
            case 0:{
                exit(0);
            }
            case 1:{
                cout << "\n\n\n+++++  Display +++++\n";

                for (int c = 0; c < 5;++c){
                    cout<<"Rack "<<c+1<<endl;

                    for (int r = 0; r < 10;++r){
                        cout << "Sheleve " << r + 1 << endl;
                        displayLibrary(rack[r][c]);
                    }
                }
                break;
            }
            case 2:{
                string book_name;
                string author_name;
                cout << "\n\n\n++++++++++     I N S E R T     ++++++++++\n";
                cout << "0. Back\n";
                cout << "1. Mathematics\n";
                cout << "2. Computer\n";
                cout << "3. Physics\n";
                cout << "4. Islamiat\n";
                cout << "5. Others\n";
                cout << "\nSelect an option : ";

                int choice;
                cin >> choice;

                if(choice==0)
                    break;
                else{
                    cout << "\nBook Menu : ";

                    cin.ignore();
                    getline(cin, book_name);

                    cout << "\nAuthor Name: ";
                    getline(cin, author_name);

                    addBook(choice - 1, book_name, author_name);
                }
                break;
            }

            case 3:{
                string name, author_name;
                cout << "Delete++++++\n";
                cout << "\nEnter book name :";
                cin.ignore();
                getline(cin, name);
                cout << "\nEnter Author Name  ";
                getline(cin, author_name);
                bool deleted = deleteBook(name, author_name);
                if(deleted){
                    cout << "\n\nSuccessfully Deleted";
                }
                else{
                    cout << "\n\nBook Not found";
                }
                break;
            }

            case 4:{
                string name;
                bool found = false;
                cout << "\n\n\n Search \n";
                cout << "\n Enter Book Name";
                cin.ignore();
                getline(cin, name);

                int id = generateBookID(name);

                for (int c = 0; c < 5;c++){
                    int shelve = id % 10;

                    struct BST *bst = searchBST(rack[shelve][c], id);

                    if(bst!=nullptr){
                        found = SearchingsearchBook(bst, name, c, shelve);
                        break;
                    }
                }
                if(!found){
                    cout << "\n\nBook Not found";
                }
                break;
            }

            case 5: {
                string book_name;
                string author_name;
                string username;
                
            }
        }
    }
}