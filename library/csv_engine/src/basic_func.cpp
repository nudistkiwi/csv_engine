//#include <csv_engine.h>
#include "csv_engine.h"

void csv_file::index()
{	std::cout<<"Indexing File...";
	int k;
	int i=1;
	cols=-1;
	rows=1;
	file_is_OK=true;
	siterator iter;
	indices.clear();
	iter=file.begin();
	--iter;
	indices.push_back(iter);
	
	for(iter=file.begin();iter!=file.end(); ++iter)
	{	
	//if('\n'!=*iter && ';'!=*iter){std::cout<<*iter;}
	if(';'==*iter){indices.push_back(iter);++i;//std::cout<<std::endl;
	}
	if('\n'==*iter)
		{
	++rows;
	indices.push_back(iter);
	if(cols!=i && cols<0){cols=i;}
	if(cols!=i && cols>0){file_is_OK=false;cols=i;}
	i=1;
	//std::cout<<std::endl;
	//std::cout<<cols<<std::endl;
		}
	}
	--rows;
//	std::cout<<indices.size()<<std::endl;
	if(file_is_OK) std::cout<<"OK"<<std::endl;
	else std::cout<<"KO"<<std::endl;
}


csv_file::csv_file(std::string input)
	{
		file=input;
		csv_file::index();
	}

csv_file::csv_file(char *filename)
{	
	int N;
	std::ifstream input(filename);
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
	//	try {
 		if(j>cols){j=cols;}
 		if(i>rows){i=rows;}
 		int k=cols*(i-1)+(j-1);
		//std::cout<<k<<std::endl;
 		siterator start=indices[k];
 		++start;
 		siterator end=indices[k+1];
 		std::string A(start,end);
 		return(A);
	//	 throw 99;
	//	  }
	//	catch(int x) {  return "some error";}  
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
		//	std::cout<<cell(j,i)<<" ";
			file_temp.append(cell(j,i));
			file_temp.append(";");
		}
	file_temp.append("\n");
	}
file=file_temp;
file_temp.clear();
index();

//cols=j;
//cols=rows;
//rows=j;

}

void csv_file::print()
{int i,j;
for(i=1;i<=rows;i++)
	{
		for(j=1;j<=cols;j++)
		{
			std::cout<<cell(i,j)<<" ";
		}
	std::cout<<std::endl;
	}
}

void delete_lr(vector<int>& dcolumns,vector<int>& drows)
{
sort(drows.begin(),drows.end());
sort(dcolumns.begin(),dcolumns.end());
vector<int> x;
vector<int> y;

int k=0;
int i=1;
while(i<rows){
if(i==drows[k]){k++; while(drows[k-1]==drows[k]){k++;} }    
else {x.push_back(i);}
i++;
}

k=0;
i=1;	
while(i<cols){
if(i==dcolumns[k]){k++; while(dcolumns[k-1]==dcolumns[k]){k++;} }    
else {y.push_back(i);}
i++;
}
	
	
file_temp.reserve(file.size());
	int i,j;	
	for(i=0;i<=x.size();++i)
	{
		for(j=0;j<y.size();++j)
		{
		//	std::cout<<cell(j,i)<<" ";
			file_temp.append(cell(x[i],[j]));
			file_temp.append(";");
		}
	file_temp.append("\n");
	}
file=file_temp;
file_temp.clear();
index();


}

/*
void delete_lines(vector<int>& lines)
{
int k;
siterator sbegin;
siterator send;
file_temp.clear();
file_temp.reserve(file.size());
sort(lines.begin(),lines.end());
sbegin=file.begin();
for(int i=0;i<lines.size();++i){
k=cols*(lines[i]-1);
send=indices[k];
file_temp.append(sbegin,send);
k=cols*(lines[i]);
sbegin=indices[k];

}
send=file.end();
file_temp.append(sbegin,send);
}
*/
