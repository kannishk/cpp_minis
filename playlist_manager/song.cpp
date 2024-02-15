#include<iostream>
#include "song.h"
#include<cstring>

using namespace std;

void IngnoreNewLines(){
    while(cin.peek()=="\n"){
        cin.ignore();
    }
}

Song::Song(){
    strcpy_s(title, "");
    strcpy_s(artist, "");
}

Song::Song(const char *t, const char *a){
    Set(t,a);
}

void Song::Set(const char *t, const char *a){
    if(strlen(t)<MAX_CHARS){
        strcpy_s(title,t);
    }
    if(strlen(a)<MAX_CHARS){
        strcpy_s(artist,a);
    }
}