#ifndef PLAYLISTSET_HPP
#define PLAYLISTSET_HPP
#include <iostream>
#include <string>
#include <list>
#include "SongTree.cpp"

using namespace std;

struct songNode
{
  string title;
  string artist;
  string album;
  string year;
};

struct playlist{
  string name;
  playlist *next;
  list<songNode> down;

  playlist(){
    next = nullptr;
  }
  playlist(string n){
    name = n;
    next = nullptr;
  }
};

class playlistSet{
public:
  playlistSet();
  ~playlistSet();
  string addPlaylist();
  void addSong(songNode *track, string name);
  void deletePlaylist(string name);
  void deleteSong();
  void viewAll();
  //takes in name searches and returns index of songNode in SongList to manipulate.
  void isInPlaylist();
  songNode *convertNode(SongTree Tree);
  void printList();
  void shufflePlaylist();
  //similar songs;
  //libsound.io for music library

private:
  playlist *head;
};

#endif
