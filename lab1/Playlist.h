#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <cstring>
using namespace std;

class PlaylistNode {
    public:
        PlaylistNode(); //default
        PlaylistNode(string, string, string, int); //parameterized
        void InsertAfter(PlaylistNode*);
        void SetNext(PlaylistNode*); //mutator
        string GetID() const; //accessor
        string GetSongName() const; //accessor
        string GetArtistName() const; //accessor
        int GetSongLength() const; //accessor (length in seconds)
        PlaylistNode* GetNext() const; //accessor
        void PrintPlaylistNode(); 
        void PrintMenu(string);

    private:
        string uniqueID; //initialized to "none" in the default constructor
        string songName; //initialized to "none" in the default constructor
        string artistName; //initialized to "none" in the default constructor
        int songLength; //initialized to 0 in the default constructor
        PlaylistNode* nextNodePtr; //initialized to 0 in the default constructor
};

class LinkedList : public PlaylistNode {
    protected:
        PlaylistNode* head;
        PlaylistNode* tail;
        int playlistSize;
    public:
        LinkedList();
        void push_back(PlaylistNode*);
        void PrintEntirePlaylist(string);
        void Remove(string);
        void TotalTime();
        void ChangePos(int, int);
};

#endif