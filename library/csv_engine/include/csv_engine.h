#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


class csv_file 
{
public:
typedef string::iterator siterator;

void index();
//void clean();
//csv_file(char *filename);
csv_file(string input);
//void write(char* filename);
//string cell(int i,int j);
//void read(char *filename);
//void show_header();
//int Nrows();	
//int Ncols();
//bool OK();
//void transponse();
//void delete_lines(vector<int>& lines);
//void delete_row(vector<int>& Drows);
//void delete_col(vector<int>& Dcols);
//void check();
//void status();
//bool operator==(const csv_file & rhs);

private:
string file;
string file_temp;
vector<siterator> indices;
bool  primary_key_unique;
int rows,cols;	
bool file_is_OK;
int size;
};
