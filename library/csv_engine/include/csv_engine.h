#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


class csv_file 
{
public:
typedef std::string::iterator siterator;
void index();
//void clean();
csv_file(char *filename);
csv_file(std::string input);
void write(char* filename);
void cell_iter(int i, int j, siterator& begin, siterator& end);
void append(std::string& str, int, int);
std::string cell(int i,int j);
//void read(char *filename);
void show_header();
int Nrows();	
int Ncols();
bool OK();
void transponse();
void transponse0();
void print();
void delete_cr(std::vector<int>& dcolumns,std::vector<int>& drows);
void delete_cr(int, int drows);
void check();
bool status();
void search_primary_column();
//bool operator==(const csv_file & rhs);
private:
std::string file;
std::string file_temp;
std::vector<siterator> indices;
std::vector<char> deletion;
bool  primary_key_unique;
int primary_column;
int rows,cols;	
bool file_is_OK;
int size;
};
