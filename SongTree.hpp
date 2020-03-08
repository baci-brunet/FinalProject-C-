#ifndef SONGTREE_HPP
#define SONGTREE_HPP
#include <iostream>
#include <string>

using namespace std;

struct song{
  string title;
  string artist;
  string album;
  string year;

  song *right;
  song *left;

  song(){
    right = left = nullptr;
  }

  song(string t, string ar, string al, string yr){
    title = t;
    artist = ar;
    album = al;
    year = yr;
    right = left = nullptr;
  }
};

class SongTree
{
public:
  SongTree();
  ~SongTree();
  song *searchMain();
  void loadSong(string t, string ar, string al, string yr);

private:
  song *root;
  song *search(string title);
  song *searchTitle(song* root, string t);
  void newSong(song *root, song *track);

};

#endif
