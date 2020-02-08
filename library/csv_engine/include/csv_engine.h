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
void type_col();
void set_data_type();
void set_data_type(std::vector<std::string>);
std::string  get_data_type(int);
void basic_type();

private:
std::string file;
std::string file_temp;
std::vector<siterator> indices;
std::vector<char> whitelist;
std::vector<std::string> data_type;
bool  primary_key_unique;
int primary_column;
int rows,cols;	
std::vector<std::string> field_types;
std::vector<std::string> col_type;
bool file_is_OK;
std::vector<int> row_items;
std::vector<bool> unique_col;
std::vector<int> delete_row;
std::vector<int> delete_col;
int size;
std::vector<std::string> basic_types;
};
