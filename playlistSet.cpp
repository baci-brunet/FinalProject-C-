#include <iostream>
#include <string>
#include <vector>
#include "playlistSet.hpp"
#include <list>
#include <cstdlib>

using namespace std;



playlistSet::playlistSet(){
}

playlistSet::~playlistSet(){
  string name = head->name;
  while(head != nullptr){
    deletePlaylist(name);
  }
}

string playlistSet::addPlaylist(){
  playlist *node = new playlist;
  cout << "Enter the name of your new playlist" << endl;
  getline(cin, node->name);
  cout << " " << endl;

  if(head == nullptr){
    head = node;
  }
  else{
    playlist *tmp = head;
    while(tmp->next != nullptr){
      tmp = tmp->next;
    }
    tmp->next = node;
  }
  return node->name;
}

void playlistSet::addSong(songNode *track, string name){
  if(head == nullptr){
    cout << "You have no playlists created." << endl;
  }
  else{
  playlist *node = nullptr;
  playlist *temp = head;
  bool b = true;
  while(temp != nullptr && b){
    if(temp->name == name){
      node = temp;
      b = false;
    }
    else{
      temp = temp->next;
    }
    if(temp == nullptr){
        cout << "You dont have a playlist saved under this name. Enter a valid playlist name." << endl;
        return;
    }
  }
  (node->down).push_back(*track);//maybe &

}
}


void playlistSet::deletePlaylist(string name){
//what playlist would you like to delete?
  if(head == nullptr){
    cout << "You have no playlists to delete." << endl;
    return;
  }
  else{
  playlist *temp = head;
  playlist *prev;
  //empty list and it is empty
  if(head != nullptr && head->name == name){
    head->down.clear();
    head = temp->next;
    delete(temp);
  }

  while(temp->next != nullptr){
    if(temp->next->name == name){
        temp->next->down.clear();
        prev = temp;
        prev->next = temp->next->next;
        delete(temp);
        temp = prev;
        return;
    }
  }
}
}

void playlistSet::deleteSong(){
  playlist *temp = head;
  string title;
  cout << "What song would you like to delete?" << endl;
  getline(cin, title);
  while(temp != nullptr){
    for(auto it = temp->down.begin(); it != temp->down.end(); it++){
      if(it->title == title){
        temp->down.erase(it);
        return;
      }
    }
    temp = temp->next;
  }//end while
  cout << "Song not found in any of your playlists." << endl;
}

void playlistSet::viewAll(){
  playlist *temp = head;
  bool a = true;
  if(temp ==  nullptr){
    cout << "You currently have no playlists created." << endl;
  }
  else{
  while(temp != nullptr && a){
    cout << temp->name << endl;
    temp = temp->next;
  }
  a = false;
 }
}

void playlistSet::isInPlaylist(){
  playlist *temp = head;
  string title;
  cout << "What song would you like to find?" << endl;
  getline(cin, title);
  while(temp != nullptr){
    for(auto it = temp->down.begin(); it != temp->down.end(); it++){
      if(it->title == title){
        cout << "[It is in: "  << temp->name << "]" << endl;
      }
    }
    temp = temp->next;
  }//end while
  cout << "Song not in any of your playlists" << endl;
}


songNode *playlistSet::convertNode(SongTree Tree)
{

/*All this does is converts bst node into a linked list node*/
//User searches for song (USING BST "searchMain" FUNCTION which returns a BST node)
//Function takes in song node in BST format as the argument, then copies the strings "song name, artist, album" to new node of Linked List format
//return linked list formatted node
song *track = Tree.searchMain();
if(track){
  songNode *node = new songNode;
  node->title = track->title;
  node->artist = track->artist;
  node->album = track->album;
  node->year = track->year;
  return node;
}
else{
  return nullptr;
}
}

void playlistSet::printList(){
//this function searches for playlist name and prints the songlist for that playlist
string name;
cout << "What playlist would you like to see?" << endl;
getline(cin, name);
cout << " " << endl;
playlist *node = nullptr;
playlist *temp = head;
bool c = true;
if(temp ==  nullptr){
  cout << "You currently have no playlists." << endl;
}
else{
while(temp != nullptr && c){
  if(temp->name == name){
    node = temp;
    c = false;
  }
  else{
    temp = temp->next;
  }
  if(temp == nullptr){
      cout << "You dont have a playlist saved under this name. Enter a valid playlist name." << endl;
      return;
  }
}//end while


for(auto it = node->down.begin(); it != node->down.end(); it++){
  cout << it->title << endl;
}

}
}

void playlistSet::shufflePlaylist(){
  string name;
  cout << "What playlist would you like to shuffle?" << endl;
  getline(cin, name);
  playlist *node = nullptr;
  playlist *temp = head;
  bool l = true;
  if(temp == nullptr){
    cout << "You currently have no playlists." << endl;
  }
  else{
  while(temp != nullptr && l){
    if(temp->name == name){
      node = temp;
      l = false;
    }
    else{
      temp = temp->next;
    }
    if(temp == nullptr){
        cout << "You dont have a playlist saved under this name. Enter a valid playlist name." << endl;
        return;
    }
  }//end while
  //create vector and add all songNodes to vector
  //use vector shuffle function (built-in)
  //put back into list and print it. (need print func written in here...cant use print list)
vector<songNode> v{ begin(node->down), end(node->down) };
random_shuffle(v.begin(), v.end());
for(auto it = v.begin(); it != v.end(); ++it){
    cout << it->title << ' ';
  }
  cout << "Your playlist is shuffled." << endl;

}
}
