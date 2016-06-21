#include "includes.h"

#ifndef H_PROG4
#define H_PROG4

const int NO_ITEMS = 3;  // no of words printed in single line
const int ITEM_W   = 16; // no of chars in longest word

typedef map < string, int > M;               // alias for map data type

void get_words ( M& );                       // process input stream
void print_words ( const M& );               // process output list
void clean_entry ( const string&, string& ); // eliminates punctuations

bool is_alnum ( const char& );               // predicate for alphanum chars
bool is_not_alnum ( const char& );           // predicate for non-alphanum chars
void to_lower ( char& );                     // converts char to lowercase
#endif
