#ifndef ADD_FUNCTIONS_H
#define ADD_FUNCTIONS_H
#include <string>
#include <vector>
using namespace std;
string prompt_user_for_filename();
bool open_file(ifstream&, const string&);
vector<string> read_words_from_file(ifstream&);
void remove_punctuation(vector<string>&, const string);
void capitalize_words(vector<string>&);
vector<string> filter_unique_words(vector<string>&);
void count_letters(unsigned int (&letters)[26], const vector<string>&);
void print_letter_counts(unsigned int (&letters)[26]);
void print_max_min_letter(const unsigned int (&letters)[26]);
#endif
