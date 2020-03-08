#include <iostream>
#include "SongTree.hpp"
#include <string>

using namespace std;

//Functions for tree
SongTree::SongTree(){
}
SongTree::~SongTree(){
}

void SongTree::newSong(song *root, song *track){
  if(track->title < root->title){
    if(root->left == NULL){
      root->left = track;
    }else{
      newSong(root->left, track);
    }
  }
  if(track->title > root->title){
    if(root->right == NULL){
      root->right = track;
    }else{
      newSong(root->right, track);
    }
  }
}

void SongTree::loadSong(string t, string a, string a2, string y){
  song* track = new song(t, a, a2, y);
  if(root == NULL){
    root = track;
  }else{
    newSong(root, track);
  }
}

//main search function that is called by main without access to private variables
song *SongTree::searchMain(){
  string t;
  cout << "Search song by Title:" << endl;
  cout << "Title: ";
  getline(cin, t);
  cout << " " << endl;
  song *track = search(t);
  if(track == nullptr){
    cout << "Song not found." << endl;
  }
  else{
  cout << "Song Info:" << endl;
  cout << "***********" << endl;
  cout << "Title:" << track->title << endl;
  cout << "Artist:" << track->artist << endl;
  cout << "Album:" << track->album << endl;
  cout << "Year:" << track->year << endl;
  cout << "***********" << endl;
  }
  return track;
}


// Helper search functions
song *SongTree::searchTitle(song* root, string t){
  if(root != nullptr){
    if(root->title == t){
      return root;
    }
    else if(t < root->title){
      return searchTitle(root->left, t);
    }
    else{
      return searchTitle(root->right, t);
    }
  }

  else{
    return nullptr;
    }
}



//main helper search function private to class
song* SongTree::search(string t){
    return searchTitle(root, t);
}
