#pragma once
#include<iostream>
#include "song.h";

using namespace std;

class playlist{
    private:
        int no_of_songs;
        int song_index;
        int array_size;
        Song *Playlist;

    public:
        playlist();
        void addSong(const Song &s);
        bool deleteSong(const Song &s);
        void showAll() const;
        void play(int num);
        void doubleSize();
        void halfSize();
        void showStatus() const;
        friend playlist operator + (playlist list, const Song s);
        friend playlist operator - (playlist list, const Song s);
        ~playlist();
};