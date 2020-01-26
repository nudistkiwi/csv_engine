#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>


class csv_file 
{
public:
typedef std::string::iterator siterator;
bool index();
bool index(char delimiter);
void clean();
//void clean();
csv_file(char *filename);
csv_file(std::string input);
void write(char* filename);
void cell_iter(int i, int j, siterator& begin, siterator& end);
std::string cell(int i,int j);
void show_header();
int Nrows();	
int Ncols();
void transponse();
void print();
void check();
bool status();
void search_primary_key();
void swap_rows(int, int);
void swap_rows(std::vector<int>);
void swap_cols(int, int);
void rcdelete(std::vector<int>,std::vector<int>);
void set_primary_key();
void sort(int);
void loop(std::string (*func)(int,int));
bool operator== ( const csv_file& lhs);
void replace(char,char);
void deleteC(char);


private:
std::string file;
std::string file_temp;
std::vector<siterator> indices;
std::vector<char> whitelist;
bool  primary_key_unique;
int primary_column;
int rows,cols;	
bool file_is_OK;
std::vector<int> row_items;
std::vector<bool> unique_col;
std::vector<int> delete_row;
std::vector<int> delete_col;
int size;
};
