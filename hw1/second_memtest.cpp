#include <iostream>
#include <stdlib.h>
#include "flexCharManager.h"
using namespace std;

int main(int argc, char *argv[])
{
  flexCharManager simplest_mem_manager;

    char* phrase = simplest_mem_manager.alloc_chars(13);
  phrase[0] = 'H';
  phrase[1] = 'e';
  phrase[2] = 'l';
  phrase[3] = 'l';
  phrase[4] = 'o';
  phrase[5] = ' ';
  phrase[6] = 'w';
  phrase[7] = 'o';
  phrase[8] = 'r';
  phrase[9] = 'l';
  phrase[10] = 'd';
  phrase[11] = '!';
  phrase[12] = '\n';


 cout << phrase << endl;

 // free world!
 char* p;
 p = phrase;
 p+=6;
 // cout << *p << endl;
 simplest_mem_manager.free_chars(p);
  
  char* phrase2 = simplest_mem_manager.alloc_chars(11);
  //cout << phrase << endl;

  phrase2[0] = 'm';
  phrase2[1] = 'o';
  phrase2[2] = 'o';
  phrase2[3] = 'n';
  phrase2[4] = '!';
  phrase2[5] = ' ';
  phrase2[6] = 'B';
  phrase2[7] = 'y';
  phrase2[8] = 'e';
  phrase2[9] = '.';
  phrase2[10] = '\n';
 
  cout << phrase << endl;
/*replace with driver code as specificed in the assignment*/
  //std::cout << "Hello world!\n";
  
  return 0;
}