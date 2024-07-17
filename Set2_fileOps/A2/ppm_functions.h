#ifndef ADD_FUNCTIONS_H
#define ADD_FUNCTIONS_H
#include <string>
using namespace std;

void print_file_options();
void print_operation_options();
int get_user_input(int, int);
bool open_files(string&, string, const int, const int);
bool read_header_information(ifstream&, string&, string&, string&);
void write_header_information(ofstream&, string&, string&, string&);
void read_and_write_modified_pixels(ifstream&, ofstream&, int&, string&, string&, string&);
#endif
