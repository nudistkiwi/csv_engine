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
std::vector<int> index();
std::vector<int> index(char delimiter);

//void crop();
csv_file(char *filename);
csv_file(std::string input);
//csv_file(siterator&,siterator&);
csv_file();
~csv_file();
void write(char* filename);
std::string cell(int i,int j)const;
std::string celll(int i,int j)const;
std::string line(int i) const;
//void show_header();
int Nrows();
int Ncols();
//void transponse();
//void print();
//void check();
bool status();
void clean();
void replace(std::string,std::string);
void swap_rows(int, int);
void swap_rows(std::vector<int>);
//void swap_cols(int, int);
//void cdelete(std::vector<int>,std::vector<int>);
void rdelete(std::vector<int>);
void sort(int);
//void loop(std::string (*func)(int,int));
bool operator==( const csv_file& lhs);
//std::string operator()(int , int );
//csv_file operator()(int,int,int,int);
//void collapse();
void repair();
void uppercase();

//csv_file& operator=(const csv_file &);
//void insert(std::string);
//csv_file operator+(const csv_file& lhs);
//csv_file operator*(const csv_file& lhs);


private:

siterator offset;
std::vector<siterator> targets;
bool file_is_OK;
std::string file;
siterator file_begin;
siterator file_end;
std::string file_temp;
std::vector<siterator> indices;
std::vector<siterator> lindex;
char delimiter;
//std::vector<siterator> line_break;
std::vector<int> errors;
int rows,cols;
int current_col;
int size;
};
