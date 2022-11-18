#include "Playlist.h"
#include <iostream>
using namespace std;

PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(0) {}

//PlaylistNode::PlaylistNode(string id, string song, string artist, int length) : uniqueID(id), songName(song), artistName(artist), songLength(length), nextNodePtr(0) {}

PlaylistNode::PlaylistNode(string id, string song, string artist, int length) {
    uniqueID = id;
    songName = song;
    artistName = artist;
    songLength = length;
    nextNodePtr = 0;
    // if (head == nullptr) { //first node in list
    //     head = this;
    //     tail = this;
    // }
}

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    playlistSize = 0;
}

/*
void PlaylistNode::InsertAfter(PlaylistNode * a){
    nextNodePtr = a;
}
*/
void PlaylistNode::InsertAfter(PlaylistNode* new_node) {
    this->nextNodePtr = new_node; //A->next = B
    /*if (this == nullptr) { // checking for empty list
        head = new_node;
        tail = new_node;
    }
    PlaylistNode* prev;
    for (PlaylistNode* temp = head; temp != nullptr; temp = temp->nextNodePtr) {
        if (this->nextNodePtr != nullptr) {
            if (temp->nextNodePtr == this) {
                prev = temp;
            }
        }
    }
    if (this != nullptr) {
        prev->nextNodePtr = new_node;
        new_node->nextNodePtr = this;
        this->nextNodePtr = this->nextNodePtr->nextNodePtr;
    }*/
}

void PlaylistNode::SetNext(PlaylistNode* new_node) { //sets next node to the node in the parameter
    this->nextNodePtr = new_node;
    /*if (this == nullptr) { // checking for empty list
        head = new_node;
        tail = new_node;
    }
    if (this->nextNodePtr == nullptr) { // a->b->null
        this->nextNodePtr = new_node;
        new_node->nextNodePtr = nullptr;
        tail = new_node;
    }
    else { //a->b->c
        this->nextNodePtr = new_node;
        new_node->nextNodePtr = this->nextNodePtr->nextNodePtr;
    }*/
}

string PlaylistNode::GetID() const {return uniqueID;}

string PlaylistNode::GetSongName() const {return songName;}

string PlaylistNode::GetArtistName() const {return artistName;}

int PlaylistNode::GetSongLength() const {return songLength;}

PlaylistNode* PlaylistNode::GetNext() const {return nextNodePtr;}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << GetID() << endl;
    cout << "Song Name: " << GetSongName() << endl;
    cout << "Artist Name: " << GetArtistName() << endl;
    cout << "Song Length (in seconds): " << GetSongLength() << endl;
}

/*
void LinkedList::PrintEntirePlaylist(string artist) {
    if (artist == " "){
        if (head == nullptr) {
            cout << "Playlist is empty" << endl << endl;
        }
        else {    
            int num = 1;
            PlaylistNode* curr = head;
            while (num <= playlistSize) { 
                if (curr != nullptr && curr != tail) {
                    cout << num << "." << endl;
                    curr->PrintPlaylistNode();
                    cout << endl;
                    curr = curr->GetNext();
                    ++num;
                }
                else {
                    cout << num << "." << endl;
                    curr->PrintPlaylistNode();
                    cout << endl;
                    break;
                }
            }
        }
    }
    else {
        int num = 1;
        for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) {
            if (curr->GetArtistName() == artist) {
                cout << num << "." << endl;
                curr->PrintPlaylistNode();
                cout << endl;
            }
            ++num;
        }
    }
}
*/

void LinkedList::PrintEntirePlaylist(string artist) {
    if (artist == " "){
        if (head == nullptr) {
            cout << "Playlist is empty" << endl << endl;
        }
        else {    
            int num = 1;
            for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) {
                cout << num << "." << endl;
                curr->PrintPlaylistNode();
                cout << endl;
                ++num;
            }
        }
    }
    else {
        int num = 1;
        //cout << "artist name: " << artist << endl;
        for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) {
            if (curr->GetArtistName() == artist) {
                cout << num << "." << endl;
                curr->PrintPlaylistNode();
                cout << endl;
            }
            ++num;
        }
    }
}

void LinkedList::push_back(PlaylistNode* push) {
    if (head == nullptr) {
        head = push;
        tail = push;
    }
    else {
        PlaylistNode* temp = head;
        while (temp->GetNext() != nullptr) {
            temp = temp->GetNext();
        }
        tail = push;
        temp->InsertAfter(push);
    }
    ++playlistSize;
}

void LinkedList::Remove(string ID) {
    PlaylistNode* curr = head;
    //PlaylistNode* next = head->GetNext();
    bool inList = false;

    if (head == nullptr) { //playlist is empty
        cout << "Playlist is empty" << endl;
        return;
    }

    //checks if song ID is in playlist
    for (PlaylistNode* temp = head; temp != nullptr; temp = temp->GetNext()) {
        if (temp->GetID() == ID) {
            inList = true;
        }
    }
    if (inList == false) {
        cout << "Song is not in playlist." << endl << endl;
        return;
    }

    //it is in the playlist
    while (inList == true) {
        if (head->GetID() == ID) { //deleting head
            //cout << "deleting curr" << endl;
            if (head == tail) { //playlist has one song, deletes song -> playlist is empty
                cout << "\"" << head->GetSongName() << "\"" << " removed." << endl << endl;
                delete curr;
                head = nullptr;
                tail = nullptr;
                return;
            }
            else if (head->GetNext() == tail) {
                //cout << "2 songs in list, deleting head" << endl;
                cout << "\"" << head->GetSongName() << "\"" << " removed." << endl << endl;
                delete head;
                head = tail;
                return;
            }
            else if (head->GetNext() != tail && head->GetNext() != nullptr) {
                //cout << "3+ songs in playlist, deleting head" << endl;
                cout << "\"" << curr->GetSongName() << "\"" << " removed." << endl << endl;
                head = curr->GetNext();
                head->SetNext(curr->GetNext()->GetNext());
                delete curr;
                return;
            }
        }
        else if (tail->GetID() == ID) { //deleting tail, if tail is not head
            //cout << "hello" << endl;
            curr = head;
            for (PlaylistNode* temp = head; temp != nullptr; temp = temp->GetNext()) {
                if (temp->GetNext() == tail) {
                    curr = temp; //makes curr the node before the tail
                }
            }
            cout << "\"" << tail->GetSongName() << "\"" << " removed." << endl << endl;
            delete tail;
            tail = curr;
            tail->SetNext(nullptr);
        }
        else { //deleting node in the middle (not head or tail)
            for (PlaylistNode* temp = head; temp != nullptr; temp = temp->GetNext()) {
                //find where it is first, set curr to node before the one to be deleted
                if (temp->GetNext()->GetID() == ID) {
                    curr = temp;
                    PlaylistNode* del_node = temp->GetNext();
                    curr->SetNext(del_node->GetNext());
                    cout << "\"" << del_node->GetSongName() << "\"" << " removed." << endl << endl;
                    delete del_node;
                    return;
                }
            }
        }

        if (curr == nullptr || curr->GetNext() == nullptr) {
            return;
        } 
        else {
            curr = curr->GetNext();
        }
    }
}

void LinkedList::TotalTime() {
    int time = 0;
    for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) {
        time += curr->GetSongLength();
    }
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    cout << "Total time: " << time << " seconds" << endl;
}

void LinkedList::ChangePos(int currPosition, int newPosition) {   // a->b->c->d->e,  // c->a->b->->d->e
    int num = 2;
    PlaylistNode* songPos = nullptr; 
    PlaylistNode* prev = head;
    PlaylistNode* curr = head->GetNext();

    while (curr != nullptr) { //finds position of song, gives us a number
        if (currPosition == 1) { //if position is 1, songPos is the head
            songPos = head;
            break;
        }
        else if (currPosition == playlistSize) { //if position is size of playlist, songPos is the tail
            songPos = tail;
            break;
        }
        else if (num == currPosition) { //finds position of other song (middle)
            songPos = curr;
            break;
        }
        curr = curr->GetNext();
        ++num;
    }
    
    int second_num = 2;
    //head cases
    if (songPos == head) { //a->b->c->d->e
        head = head->GetNext(); //b->c->d->e
        PlaylistNode* temp = head;
        PlaylistNode* temp2 = head->GetNext();
        while (temp != nullptr) { //head to middle
            if (second_num == newPosition) { //b->c->d->e->a->null second_num = 5
                temp->SetNext(songPos);
                if (second_num >= playlistSize) {// head to tail
                    tail = songPos;
                    tail->SetNext(nullptr);
                }
                else { //head to middle
                    songPos->SetNext(temp2);
                }
                break;
            }
            temp = temp->GetNext(); //temp = e
            temp2 = temp2->GetNext(); // temp2 = null
            second_num++; //second_num = 5
        }
    }

    //tail case README: MIGHT BE A DANGLING POINTER FOR TAIL, IF 5 TO 4, CHECK IF TAIL POINTS TO NEW TAIL
    else if (songPos == tail) { //a->b->c->d->e
        prev = head;
        curr = head->GetNext();
        while (curr != nullptr) {
            if (curr == tail) { //assigning new tail
                tail = prev;
                tail->SetNext(nullptr);
            }
            curr = curr->GetNext();
            prev = prev->GetNext();
        }
        // a->b->c->d   e
        PlaylistNode* temp = head;
        PlaylistNode* temp2 = head->GetNext();
        second_num = 2;
        while (temp != nullptr) {
            if (newPosition <= 1) { //tail to head
                songPos->SetNext(temp);
                head = songPos;
                break;
            }
            else if (second_num == newPosition) { //tail to middle
                temp->SetNext(songPos);
                songPos->SetNext(temp2);
                break;
            }
            if (temp == tail) {
                break;
            }
            temp = temp->GetNext();
            temp2 = temp2->GetNext();
            ++second_num;
        }
    }

    //middle to anywhere case
    else { 
        prev = head;
        curr = head->GetNext();
        while (curr != nullptr) { //taking out the node
            if (curr == songPos) { //changes previous pointer to point to node after curr
                prev->SetNext(curr->GetNext());
            }
            curr = curr->GetNext();
            prev = prev->GetNext();
        } //a->c->d->e  b
        PlaylistNode* temp = head; //temp = d 
        PlaylistNode* temp2 = head->GetNext(); //temp2 = e
        if (newPosition <= 1) { //middle to head
            songPos->SetNext(temp);
            temp->SetNext(temp2);
            head = songPos;
        }
        else if (newPosition >= playlistSize) { //middle to tail
            tail->SetNext(songPos);
            tail = songPos;
            tail->SetNext(nullptr);
        }
        else { //middle to middle
            int number = 2;
            while (temp != nullptr) {
                if (number == newPosition) {
                    temp->SetNext(songPos);
                    songPos->SetNext(temp2);
                    break;
                }
                temp = temp->GetNext();
                temp2 = temp2->GetNext();
                ++number;
            }
        }
    }
    cout << "\"" << songPos->GetSongName() << "\" moved to position " << newPosition << endl << endl;
}

/*void LinkedList::ChangePos(int currPosition, int newPosition) {   // a->b->c->d->e,  // c->a->b->->d->e
    int num = 2;
    PlaylistNode* songPos = nullptr; 
    PlaylistNode* songname = nullptr;
    PlaylistNode* prev = nullptr;
    
    PlaylistNode* curr = nullptr;
    PlaylistNode* new_head = head;
    prev = head;
    if (newPosition >= playlistSize) { // any node to tail
        for (curr = head->GetNext(); curr != nullptr; curr = curr->GetNext()) {
            if (currPosition == 1) { //head to tail
                songname = head;
                songPos = head;
                delete head;
                head = curr;
                break;
            }
            else if (num == currPosition) { //a->b->c->d
                songname = curr;
                songPos = curr;
                prev->SetNext(curr->GetNext());
                break;
            }
            else {
                ++num;
                prev = prev->GetNext(); // 1, 2
            }
        }
        tail->SetNext(songPos);
        tail = songPos;
        tail->SetNext(nullptr);
    }
    else if (newPosition <= 1){ //any node to head
        for (curr = head->GetNext(); curr != nullptr; curr = curr->GetNext()) {
            if (num == currPosition) {
                songname = curr;
                if (curr == tail) {
                    tail = prev;
                    prev->SetNext(nullptr);
                }
                else {
                    prev->SetNext(curr->GetNext());
                }
                curr->SetNext(new_head);
                head = curr;
                break;
            }
            ++num;
            prev = prev->GetNext();
        }
    }
    else {
        prev = head;
        PlaylistNode* next = nullptr;
        for (PlaylistNode* curr = head->GetNext(); curr != nullptr; curr = curr->GetNext()) { //records the node it wants to move
            if (currPosition == 1) { //if node is head
                songPos = prev;
                songname = prev;
                break;
            }
            else if (num == currPosition) { // if node is not head
                songPos = curr;
                songname = curr;
                break;
            }
            ++num;
            prev = prev->GetNext();
        }
        num = 1;
        int num2 = 2;
        for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) { //a->b->c->d->e curr = a, b, c
            next = curr->GetNext(); //next = b, c, d
            if (currPosition == 1 || num2 == currPosition) {
                int num3 = 2;
                if (songPos == tail) {
                    tail = curr; //a->b->c->d
                    tail->SetNext(nullptr);
                }
                else if (songPos == head) {
                    head = next; //b->c->d->e
                }
                else if (next == songPos) {
                    curr->SetNext(next->GetNext()); //a->b->c->e
                }
                for (PlaylistNode* temp = head; temp != nullptr; temp = temp->GetNext()) {
                    PlaylistNode* temp2 = temp->GetNext();
                    if (newPosition == num3) {
                        temp->SetNext(songPos);
                        songPos->SetNext(temp2);
                        break;
                    }
                    ++num3;
                }
                break;
            }
            ++num2; //num2 = 2, 3, 4
        }
    }
    cout << "\"" << songname->GetSongName() << "\" moved to position " << newPosition << endl << endl;
} */

