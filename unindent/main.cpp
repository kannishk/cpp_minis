#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    string f;
    string iv;
    int c;
    opterr=0;
    int indent;
    string line;

    while((c=getopt(argc,argv,"f:i:"))!=-1){
        switch(c){
            case'f':
                f=optarg;
                break;
            case'i':
                iv=optarg;
                break;
            case'?':
               if(optopt=='i' || optopt=='f')
                    cerr<<"Options and require an argument";
                else if(isprint(optopt))
                    cout<<"Unknown option";
                else   
                    cout<<"Unknown option character";
                return 1;
            default:
                abort();
        }
    }

    // indent = stoi(iv);

    fstream my_file;
    ofstream write;

    my_file.open(f);
    write.open("new_file.txt");

    if(!my_file){
        cout << "Get gud";
        return 0;
    }

    while(my_file){
        getline(my_file,line);

        if(line=="-1"){
            break;
        }

        // Determine the dynamic indent based on leading spaces
        size_t pos = line.find_first_not_of(' ');
        indent = (pos == string::npos) ? 0 : pos;

        // Remove indent spaces and write to output
        write << line.substr(indent) << endl;
    }

    my_file.close();
    write.close();
    return 0;
}