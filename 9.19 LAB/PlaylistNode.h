// Only edit if necessary

#ifndef PlaylistNode_h
#define PlaylistNode_h
#include <iostream>
#include<string>

using namespace std;
class PlaylistNode {
public:
	PlaylistNode();
	PlaylistNode(string id, string song, string artist, int length);
	void InsertAfter(PlaylistNode* Node);
	void SetNext(PlaylistNode* Node);
	string GetID();
	string GetSongName();
	string GetArtistName();
	int GetSongLength();
	PlaylistNode* GetNext();
	void PrintPlaylistNode();
private:
	string uniqueID;
	string songName;
	string artistName;
	int songLength;
	PlaylistNode* nextNodePtr;

};

class Playlist
{
private:
	PlaylistNode* head;
	PlaylistNode* tail;

public:
	Playlist();
	void AddSong(string id, string songname, string artistname, int length);
	bool RemoveSong(string id);
	void printlist();
	bool ChangePosition(int oldpos, int newpos);
	void SongsByArtist(string artist);
	int totaltime();
};






#endif