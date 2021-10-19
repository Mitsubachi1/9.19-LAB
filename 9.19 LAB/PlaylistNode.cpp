// Only edit if necessary

#include "PlaylistNode.h"
#include <iostream>
#include <string>
using namespace std;


PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}
PlaylistNode::PlaylistNode(string id, string song, string artist, int length) {

    uniqueID = id;
    songName = song;
    artistName = artist;
    songLength = length;
    nextNodePtr = 0;
}
void PlaylistNode::InsertAfter(PlaylistNode* Node) {
    this->SetNext(Node->GetNext());
    Node->SetNext(this);

}



void PlaylistNode::SetNext(PlaylistNode* Node) {
    nextNodePtr = Node;

}
string PlaylistNode::GetID() {

    return uniqueID;
}

string PlaylistNode::GetSongName() {
    return songName;
}

string PlaylistNode::GetArtistName() {

    return artistName;
}
int PlaylistNode::GetSongLength() {
    return songLength;
}
PlaylistNode* PlaylistNode::GetNext() {
    return nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << GetID() << endl;
    cout << "Song Name: " << GetSongName() << endl;
    cout << "Artist Name: " << GetArtistName() << endl;
    cout << "Song Length (in seconds): " << GetSongLength() << endl;
}

//Constructors and functions for menu execution

Playlist::Playlist() {
    head = tail = 0;
}
void Playlist::AddSong(string id, string songname, string artistname, int length) {

    PlaylistNode* n = new PlaylistNode(id, songname, artistname, length);
    if (head == 0)
        head = tail = n;
    else {
        n->InsertAfter(tail);
        tail = n;
    }

}
bool Playlist::RemoveSong(string id) {
    PlaylistNode* curr = head;
    PlaylistNode* last = NULL;
    if (head == NULL) {
        cout << "Playlist is empty." << endl;
        return false;
    }
    while (curr != NULL) {
        if (curr->GetID() == id) {
            break;
        }
        last = curr;
        curr = curr->GetNext();

    }
    if (curr == NULL) {
        cout << "\"" << curr->GetSongName() << "\" is not found" << endl;
        return false;
    }
    else {
        if (last != NULL) {
            last->SetNext(curr->GetNext());
        }
        else
            head = curr->GetNext();

        if (tail == curr)
            tail = last;
        cout << "\"" << curr->GetSongName() << "\" removed." << endl;
        delete curr;
        return true;
    }

}



bool Playlist::ChangePosition(int oldpos, int newpos) {
    
    int pos;
    if (head == NULL) {
        cout << "Playlist is empty." << endl;
        return false;
    }

    PlaylistNode* prev = NULL;
    PlaylistNode* curr = head;
    if (head == NULL || head == tail) {
        return false;
    }
    for (pos = 1; curr != NULL && pos < oldpos; pos++) {
        prev = curr;
        curr = curr->GetNext();
    }
    if (curr != NULL) {
        string currentSong = curr->GetSongName();

        if (prev == NULL) {
            head = curr->GetNext();
        }
        else {
            prev->SetNext(curr->GetNext());
        }

        if (curr == tail) {
            tail = prev;
        }
        PlaylistNode* curr1 = curr;
        prev = NULL;
        curr = head;
        for (pos = 1; curr != NULL && pos < newpos; pos++) {
            prev = curr;
            curr = curr->GetNext();
        }
        if (prev == NULL) {

            curr1->SetNext(head);
            head = curr1;

        }
        else {
            curr1->InsertAfter(prev);
        }
        if (curr == NULL) {
            tail = curr1;
        }

        cout << "\"" << currentSong << "\" moved to postion " << newpos << endl;
        return true;
    }
    else {
        cout << "Song's current position is invalid" << endl;
        return false;
    }

}

void Playlist::SongsByArtist(string artist) {

    if (head == NULL)

        cout << "Playlist is empty" << endl;

    else {

        PlaylistNode* curr = head;
        int i = 1;
        while (curr != NULL) {

            if (curr->GetArtistName() == artist) {

                cout << endl << i << "." << endl;
                curr->PrintPlaylistNode();

            }

            curr = curr->GetNext();
            i++;

        }

    }

}
int Playlist::totaltime() {

    int total = 0;

    PlaylistNode* curr = head;

    while (curr != NULL) {

        total += curr->GetSongLength();
        curr = curr->GetNext();


    }

    return total;
}

void Playlist::printlist() {
    PlaylistNode* curr = head;
    int index = 1;
    if (head == NULL)
        cout << "Playlist is empty" << endl;
    else {
        while (curr != NULL) {
            cout << index++ << "." << endl;
            curr->PrintPlaylistNode();
            curr = curr->GetNext();
            cout << endl;
        }

    }
}