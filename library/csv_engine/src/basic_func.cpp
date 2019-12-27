#include <csv_engine.h>
//#include "csv_engine.h"

void csv_file::index()
{int 	k;
	int i=1;
	cols=-1;
	rows=1;
	file_is_OK=true;
	siterator iter;
	iter=file.begin();
	--iter;
	indices.push_back(iter);
	for(iter=file.begin();iter!=file.end(); ++iter)
	{//cout<<*iter;	
	if(';'==*iter){indices.push_back(iter);++i;}
	if('\n'==*iter){++rows;
	indices.push_back(iter);
	if(cols!=i && cols<0){cols=i;}
	if(cols!=i && cols>0){file_is_OK=false;cols=i;}
	i=1;}
	}
	--rows;
}


csv_file::csv_file(std::string input)
	{
		file=input;
		csv_file::index();
	}

csv_file::csv_file(char *filename)
{	
	int N;
	ifstream input(filename);
	input.seekg(0,input.end);
	N=input.tellg();
	input.seekg(0,input.beg);
	N=N-input.tellg();
	char* data= new char[N];
	input.read(data,N);
	std::string help(data,N);
	file=help;
	index();
 }

 void csv_file::write(char* filename)
	{
		std::ofstream stream(filename);
		stream<<file;
		stream.close();

	}


std::string csv_file::cell(int i,int j)
	{
 		if(j>cols){j=cols;}
 		if(i>rows){i=rows;}
 		int k=cols*(i-1)+(j-1);
 		siterator start=indices[k];
 		++start;
 		siterator end=indices[k+1];
 		std::string A(start,end);
 		return(A);
	}

void csv_file::show_header()
	{
	int i;
	for(i=1;i<cols;++i)
	 {
    std::cout<<i<<". "<<csv_file::cell(1,i)<<std::endl;
	 }	
	}

int csv_file::Nrows()
	{
	if(file_is_OK) return(rows);
	else return(-1);
	}

int csv_file::Ncols()
	{
	if(file_is_OK) return(cols);
	else return(-1);
	}

bool csv_file::OK()
	{
	if(file_is_OK) return(true);
	else return(false);
	}

void csv_file::transponse() 
{
	file_temp.reserve(file.size());
	int i,j;	
	for(i=1;i<=cols;++i)
	{
		for(j=1;j<=rows;++j)
		{
			file_temp.append(cell(i,j));
			file_temp.append(";");
		}
	file_temp.append("\n");
	}
file=file_temp;
file_temp.clear();
}