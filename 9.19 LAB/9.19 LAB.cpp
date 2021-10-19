#include <iostream>
#include <string>
#include "PlaylistNode.h"

using namespace std;
PlaylistNode* ExecuteMenu(char choice, string playlistTitle, PlaylistNode* headNode);
void PrintMenu(const string playlistTitle) {
    /* Type your code here */
    cout << playlistTitle << " PLAYLIST MENU\n"
        << "a - Add song\n"
        << "d - Remove song\n"
        << "c - Change position of song\n"
        << "s - Output songs by specific artist\n"
        << "t - Output total time of playlist (in seconds)\n"
        << "o - Output full playlist\n"
        << "q - Quit\n" << endl;
}

PlaylistNode* ExecuteMenu(char choice, string playlistTitle, PlaylistNode* headNode) {
    string name, uid, artist;/* Type your code here */
    int length, oldpos, newpos;
    Playlist playlist;


    //TODO:: Code the case statements for the menu
    while (choice != 'q') {
        switch (choice) { //switch statements here
                       //if a certain case becomes a block of code, enclose it with {} after the ":" and before the "break;"

        case 'q':
            exit(0);
            break;

        case 'a': {

            cin.ignore();
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, uid);
            cout << "Enter song's name:" << endl;
            getline(cin, name);
            cout << "Enter artist's name:" << endl;
            getline(cin, artist);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> length;
            playlist.AddSong(uid, name, artist, length);
            cout << endl;
        }
                break;

        case 'd': {
            cin.ignore();
            cout << "\nREMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> uid;
            playlist.RemoveSong(uid);
            cout << endl;
        }
                break;

        case 'c': {
            cin.ignore();
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> oldpos; //oldpos
            cout << "Enter new position for song:" << endl;
            cin >> newpos; //newpos
            playlist.ChangePosition(oldpos, newpos);
            cout << endl;

        }
                break;

        case 's': {
            cin.ignore();
            cout << "\nOUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name: " << endl;
            getline(cin, artist);
            playlist.SongsByArtist(artist);
        }
                break;

        case 't': {
            cout << "\nOUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << playlist.totaltime() << " seconds" << endl;
        }
                break;

        case 'o': {
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            playlist.printlist();
        }
                break;

        default:
            break;
        }
        
        PrintMenu(playlistTitle);
        cout << "Choose an option:" << endl;
        cin.ignore();
        cin >> choice;
    }
    return headNode;
}

int main() {
    /* Type your code here */
    string playlistTitle;
    char choice;
    cout << "Enter playlist's title:" << endl;
    getline(cin, playlistTitle);
    PrintMenu(playlistTitle);



    //TODO: add in cin statement for user choice and char variable, then call execute menu




    cout << "Choose an option:" << endl;
    cin >> choice;
    PlaylistNode* headNode = nullptr;              //
    //headNode= new PlaylistNode();        // Idk if i did this part right, but right now it works
    ExecuteMenu(choice, playlistTitle, headNode);  //might edit later if headnode aint right

    return 0;
}

