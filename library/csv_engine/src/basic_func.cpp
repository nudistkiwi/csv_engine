//#include <csv_engine.h>
#include <csv_engine.h>



void csv_file::append(std::string& str, siterator beg, siterator end)
{
	
	while (beg != end) 
	{
		str.append(1,*(++beg));
		

	}

}

void csv_file::append(std::string& str, int i, int j)
{	siterator beg;
	siterator end;
	cell_iter(i,j,beg,end);
	while (beg != end) 
	{
		str.append(1,*(++beg));
		

	}

}


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
	//--iter;
	indices.push_back(iter);
	
	for(iter=file.begin();iter!=file.end(); ++iter)
	{	
	//if('\n'!=*iter && ';'!=*iter){std::cout<<*iter;}
	if(';'==*iter){indices.push_back(iter-1);++i;//std::cout<<std::endl;
	}
	if('\n'==*iter)
		{
	++rows;
	indices.push_back(iter+1);
	if(cols!=i && cols<0){cols=i;}
	if(cols!=i && cols>0)
			{
		/*	std::cout<<"Error in row "<<row-1<<std::endl;
			std::cout<<"x..stop,c..cancel,s..skip"<<std::endl;
			string message;
			switch(message)
				{
				case("x") { for (int p = 0; p < cols; p++) { indices.pop_back(); } iter = indices.back(); break; }
				case("s"){for(int p=0;p<cols;p++){indices.pop_back();} iter = indices.back(); break;}
				case("c"){for(int p=0;p<cols;p++){indices.pop_back();} iter = indices.back(); break;}
				} */
			file_is_OK=false;cols=i;
			}
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


void csv_file::cell_iter(int i, int j, siterator& begin, siterator&  end) {
	if (j > cols) { j = cols; }
	if (i > rows) { i = rows; }
	int k = cols * (i - 1) + (j - 1);
	//std::cout<<k<<std::endl;
	begin = indices[k];
	end = indices[k + 1];

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

std::string  csv_file::cell(int i,int j)
	{
	if (j > cols) { j = cols; }
	if (i > rows) { i = rows; }
	int k = cols * (i - 1) + (j - 1);
	//std::cout<<k<<std::endl;
	siterator start = indices[k];
	siterator end = indices[k + 1];
	std::string A(start+1, end+1);
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
	siterator begin;
	siterator end;
	file_temp.reserve(file.size());
	int i,j;	
	for(i=1;i<=cols;++i)
	{
		for(j=1;j<=rows;++j)
		{
		//	std::cout<<cell(j,i)<<" ";
			//file_temp.append(cell(j,i));
			cell_iter(i, j, begin, end);
			append(file_temp, begin,end);
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

void csv_file::transponse0() 
{
	siterator begin;
	siterator end;
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

void csv_file::delete_cr(std::vector<int>& dcolumns,std::vector<int>& drows)
{
	
std::sort(drows.begin(),drows.end());
std::sort(dcolumns.begin(),dcolumns.end());
std::vector<int> x;
std::vector<int> y;


int k=0;
int i=1;
while(i<=rows){
if(i==drows[k]){k++; while(drows[k-1]==drows[k]){k++;} }    
else {x.push_back(i);}
i++;
}

k=0;
i=1;	
while(i<=cols){
if(i==dcolumns[k]){k++; while(dcolumns[k-1]==dcolumns[k]){k++;} }    
else {y.push_back(i);}
i++;
}
	

file_temp.reserve(file.size());
	int j;	
	for(i=0;i<x.size();++i)
	{
		for(j=0;j<y.size();++j)
		{
		//	std::cout<<cell(j,i)<<" ";
			file_temp.append(cell(x[i],y[j]));
			file_temp.append(";");
		}
	file_temp.append("\n");
	}
file=file_temp;
file_temp.clear();
index();


}

void csv_file::delete_cr(int dcolumns, int drows)
{

	std::vector<int> x;
	std::vector<int> y;



	int i = 1;
	while (i <= rows) {
		if (i == drows) {}
		else { x.push_back(i); }
		i++;
	}


	i = 1;
	while (i <= cols) {
		if (i == dcolumns) {}
		else { y.push_back(i); }
		i++;
	}


	file_temp.reserve(file.size());
	int j;
	for (i = 0; i < x.size(); ++i)
	{
		for (j = 0; j < y.size(); ++j)
		{
			//	std::cout<<cell(j,i)<<" ";
			//append(file_temp,)
			file_temp.append(cell(x[i], y[j]));
			file_temp.append(";");
		}
		file_temp.append("\n");
	}
	file = file_temp;
	file_temp.clear();
	index();


}

void csv_file::check()
{
size=sizeof(char)*file.size();
int i=1;
int k;
int duplicates;
primary_key_unique=true; 
std::vector<std::string> primary;
for(int i=2;i<=rows;++i){
primary.push_back(cell(1,i));
}
std::sort(primary.begin(),primary.end());

for(int i=2;i<rows;++i) {
if(primary[i]==primary[i+1]){primary_key_unique=false; ++duplicates;}
			}
siterator iter;
int rowc=0;
int colc=0;
std::vector<int> row_cols;
for(iter=file.begin();iter!=file.end();++iter){
if(*iter==';'){++colc;}
if(*iter=='\n'){colc=0;row_cols.push_back(colc);}
}

std::sort(row_cols.begin(),row_cols.end());
if(row_cols.front()==row_cols.back()){file_is_OK=true;}

}

bool csv_file::status(){
double  nice_size;
int i=0;
std::vector<std::string> Byte;
Byte.push_back("Bytes");
Byte.push_back("KiloBytes");
Byte.push_back("MegaBytes");
Byte.push_back("GigaBytes");

std::cout<<"primary key is unique...."<<primary_key_unique<<std::endl;
std::cout<<"file is healthy...."<<file_is_OK<<std::endl;
std::cout<<"file has size...";
nice_size=size;
while(nice_size>1000 && i<4)
{
nice_size=nice_size/1000;
++i;
}
std::cout<<nice_size<<" "<<Byte[i]<<std::endl;
std::cout<<"rows.."<<rows<<"  colums..."<<cols<<std::endl;
/*cout<<"file has uncomitted changes";
//cout<<"number of changes";
*/
if (primary_key_unique && file_is_OK) return true;
else return false;
}




/*
void csv_file::loop(std::vector<std::pair<int, int  >> LIST)
{

	

	file_temp.reserve(file.size());
	int i,j;
	for (i = 0; i < LIST.size(); ++i)
	{
		
			file_temp.append(cell(LIST[i].first, LIST[i].second));
			file_temp.append(";");
		
		file_temp.append("\n");
	}
	file = file_temp;
	file_temp.clear();
	index();



}

*/