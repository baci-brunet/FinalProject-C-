#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <cstdlib>
#include "playlistSet.cpp"


using namespace std;

SongTree Tree;
playlistSet Set;
list<songNode> queue;

int main(int argc, char* argv[]){

  string choice;
  bool Play = true;

  while(Play != false){
      cout << "*******************************" << endl;
      cout << "MAIN MENU" << endl;
      cout << " 1 - Load Library." << endl;
      cout << " 2 - Quit." << endl;
      cout << "*******************************" << endl;
      cout << " Enter your choice and press return: " << endl;

      getline(cin, choice);
      int c = stoi(choice);
      switch(c){

          case 1:
          {
              ifstream myfile(argv[1]);
              if(myfile.is_open()){
                string line;
                while(getline(myfile,line)){
                  stringstream ss;
                  ss << line;
                  string word;
                  string title;
                  string artist;
                  string album;
                  string year;
                  getline(ss, word, ',');
                  title = word;
                  getline(ss, word, ',');
                  artist = word;
                  getline(ss, word, ',');
                  album = word;
                  getline(ss, word, ',');
                  year = word;

                  Tree.loadSong(title, artist, album, year);
                }
              }
              //Call or write function to load library
              cout << "Library Loaded." << endl;
              cout << " " << endl;
            menu1:

              string choice1;
              bool load = true;

              while (load != false){
                  cout << "*******************************" << endl;
                  cout << "MENU" << endl;
                  cout << " 1 - Search." << endl;
                  cout << " 2 - Create Playlist." << endl;
                  cout << " 3 - View Playlists." << endl;
                  cout << " 4 - Delete Playlist." << endl;
                  cout << " 5 - Shuffle." << endl;
                  cout << " 6 - View Queue." << endl;
                  cout << " 7 - Clear Queue" << endl;
                  cout << " 8 - Quit." << endl;
                  cout << "*******************************" << endl;
                  cout << " Enter your choice and press return: " << endl;

                  getline(cin, choice1);
                  cout << " " << endl;
                  int c1 = stoi(choice1);

                  switch(c1){

                      case 1:
                      {
                          //Search function

                          songNode *node = Set.convertNode(Tree);
                          if(node == nullptr){
                            goto menu1;
                          }

                          bool load1 = true;
                          string choice2;

                          while (load1 != false){
                              cout << "*******************************" << endl;
                              cout << "MENU" << endl;
                              cout << " 1 - Add song to Queue." << endl;
                              cout << " 2 - Add song to Playlist." << endl;
                              cout << " 3 - Create Playlist." << endl;
                              cout << " 4 - Back to Main Menu." << endl;
                              cout << "*******************************" << endl;
                              cout << " Enter your choice and press return: " << endl;


                              getline(cin, choice2);
                              cout << " " << endl;
                              int c2 = stoi(choice2);

                              switch (c2){

                                  case 1:
                                  {
                                      queue.push_back(*node);
                                      break;
                                    }

                                  case 2:
                                  {

                                      string name;

                                      cout << "What playlist would you like to add a song to?" << endl;

                                      getline(cin, name);
                                      cout << " " << endl;
                                      //Add to playlist function
                                      Set.addSong(node, name);
                                      break;
                                    }

                                  case 3:
                                  {
                                      //Create playlist function
                                      /* must have the same options as main menu button
                                      (i.e. name, add song, and delete song)*/
                                      string name = Set.addPlaylist();
                                      cout << " " << endl;
                                      Set.addSong(node, name);
                                      break;
                                    }
                                  case 4:
                                  {
                                    goto menu1;
                                      break;
                                    }

                              }
                          }
                          break;
                        }

                     case 2:
                     {
                          cout << "Creating Playlist..." << endl;
                          cout << " " << endl;

                          string name = Set.addPlaylist();
                          string choice3;
                          bool load2 = true;

                          while (load2 != false){
                              cout << "*******************************" << endl;
                              cout << "MENU" << endl;
                              cout << " 1 - Add Song." << endl;
                              cout << " 2 - Back to Main Menu." << endl;
                              cout << "*******************************" << endl;
                              cout << " Enter your choice and press return: " << endl;

                              getline(cin, choice3);
                              cout << " " << endl;
                              int c3 = stoi(choice3);

                              switch(c3){

                                  case 1:
                                  {
                                    //Add song function
                                    //back to previous menu
                                      songNode *node = Set.convertNode(Tree);
                                      cout << " " << endl;
                                      Set.addSong(node, name);
                                      break;
                                    }

                                  case 2:
                                  {
                                    goto menu1;
                                      //back to previous menu
                                      break;
                                    }
                              }
                          }

                          break;
                      }

                    case 3:
                    {
                         cout << "View your Playlists" << endl;
                         cout << " " << endl;
                         //show names of all playlists created and have them select one.
                         //print playlists by name upon request
                         //back to previous menu
                         Set.viewAll();


                         string choice4;
                         bool load3 = true;

                         while (load3 != false){
                             cout << " " << endl;
                             cout << "*******************************" << endl;
                             cout << "MENU" << endl;
                             cout << " 1 - Add Song." << endl;
                             cout << " 2 - Delete Song." << endl;
                             cout << " 3 - View all songs in a playlist." << endl;
                             cout << " 4 - Back to Main Menu." << endl;
                             cout << "*******************************" << endl;
                             cout << " Enter your choice and press return: " << endl;


                             getline(cin, choice4);
                             cout << " " << endl;
                             int c4 = stoi(choice4);

                             switch(c4){

                                 case 1:
                                 {
                                     songNode *node = Set.convertNode(Tree);
                                     cout << " " << endl;
                                     string name;
                                     cout << "What playlist would you like to add a song to?" << endl;
                                     getline(cin, name);
                                     cout << " " << endl;

                                     Set.addSong(node, name);
                                     //Add song function
                                     //back to previous menu
                                     break;
                                  }

                                 case 2:
                                 {
                                     Set.deleteSong();
                                     break;
                                   }

                                 case 3:
                                 {
                                     Set.printList();
                                     break;
                                   }

                                 case 4:
                                 {
                                 //back to previous menu
                                     goto menu1;
                                     break;
                                   }
                             }
                         }

                        break;
                      }

                    case 4:
                    {
                         string name;
                         cout << "What playlist would you like to delete?" << endl;
                         getline(cin, name);
                         cout << " " << endl;
                         cout << "Deleting Playlist..." << endl;
                         cout << " " << endl;
                         //cin the name of desired playlist...then delete it
                         //back to previous menu
                         Set.deletePlaylist(name);
                         cout << "Playlist Deleted." << endl;
                         cout << " " << endl;
                         break;
                       }

                    case 5:
                    {
                         cout << "Shuffling Songs" << endl;
                         cout << " " << endl;
                         //print shuffled songs
                         Set.shufflePlaylist();

                         break;
                    }

                    case 6:
                    {
                         cout << "View your Queue" << endl;
                         cout << " " << endl;
                         if(queue.empty()){
                           cout << "Your Queue is empty." << endl;
                           cout << " " << endl;
                         }

                         for(auto it = queue.begin(); it != queue.end(); it++){
                           cout << it->title << endl;
                         }

                        break;
                     }
                    case 7:
                    {
                        cout << "Clearing queue..." << endl;
                        if(queue.empty()){
                          cout << "Your Queue is empty." << endl;
                        }

                        queue.clear();
                        cout << "Queue cleared." << endl;
                        break;
                      }

                    case 8:
                    {
                         cout << "Quit Program." << endl;
                         load = false;
                         break;
                       }

                 }
             }

          break;
        }

     case 2:
      {
          cout << "Quit Program." << endl;
          Play = false;
          break;
        }

     }//end main switch
  }//end main while

return 0;

}
