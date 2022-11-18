#include "Playlist.h"
#include <iostream>
#include <vector>
using namespace std;

void PrintMenu(string title, LinkedList );

int main() {
    string playlistTitle = "";

    cout << "Enter playlist's title:" << endl;
    getline(cin, playlistTitle);
    //PrintMenu(playlistTitle);

    //tests PrintPlaylistNode
    cout << endl;
    LinkedList list;
    PrintMenu(playlistTitle, list);
    PlaylistNode test1("123", "hello", "adele", 200);
    //test1.PrintMenu(playlistTitle);

    return 0;
}
// test1("123", "hello", "adele", 200)
void PrintMenu(string title, LinkedList list) {
    char option = 'z';
    while (option != 'q') {
        cout << title << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl << endl;
        cout << "Choose an option:" << endl;
        
        cin >> option;

        if (option == 'o') {
            string str = " ";
            cout << title << " - OUTPUT FULL PLAYLIST" << endl;
            list.PrintEntirePlaylist(str);
        }
        else if (option == 'a') {
            string id, name, artist;
            int length;
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> id;
            cin.ignore();
            cout << "Enter song's name:" << endl;
            getline(cin, name);
            //cin.ignore();
            cout << "Enter artist's name:" << endl;
            getline(cin,artist);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> length;
            PlaylistNode* temp = new PlaylistNode(id, name, artist, length);
            list.push_back(temp);
            cout << endl;
        }
        else if (option == 'd') {
            string uID = "";
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> uID;
            list.Remove(uID);
            //cout << list.GetSongName() << " removed" << endl;
            
        }
        else if (option == 'c') {
            int currPos = 0;
            int newPos = 0;
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> currPos;
            cout << "Enter new position for song:" << endl;
            cin >> newPos;
            list.ChangePos(currPos, newPos);
        }
        else if (option == 's') {
            string string;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            cin.ignore();
            getline(cin,string);
            //cout << "name inputted: " << string << endl;
            cout << endl;
            list.PrintEntirePlaylist(string);
            
        }
        else if (option == 't') {
            list.TotalTime();
            cout << endl;
        }
        else if (option != 'q') {
            cout << "Choose an option:" << endl;
            cin >> option;
        }
    }
}