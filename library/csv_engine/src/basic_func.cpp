
#include <csv_engine.h>




bool csv_file::index() {
	if (index(',')) return true;
	if (index(';')) return true;
	if (index('\t')) return true;
//	if (index('::')) return true;
	return false;
}

bool csv_file::index(char delimiter)
{//	std::cout<<sizeof(siterator)<<" "<<sizeof(int)<<std::endl;
	//std::cout<<"Indexing File..."<<std::endl;
	std::vector<siterator> deletion_targets;
	siterator last_valid_line;	
	row_items.clear();
	//char delimiter=',';
	char newline='\n';
	int k;
	int i=1;
	cols=-1;
	rows=1;
	file_is_OK=true;
	siterator iter;
	indices.clear();
	iter=file.begin();
	bool line_empty=false;
	bool delimiter_found;
	indices.push_back(iter);
	for(iter=file.begin();iter!=file.end(); ++iter)
	{
	
		//if (*iter == '\r') { *iter = 'a'; }
	if ('"' == *iter) {
		iter++;
			
			while ('"' != *iter) {// std::cout << *iter; ttttttttttttttt
			iter++; 
			}
	}
		if (delimiter == *iter ) {
			line_empty=false;
			indices.push_back(iter); ++i;//std::cout<<std::endl;

		}

		if ((newline == *iter || int(*iter) == 10) && line_empty==false)
		{	//std::cin>>k;
			//std::cout << int(*iter) <<" "<<int('\n')<< std::endl;
			//if (*iter == '\n') { *iter = '\r'; }
			
			//std::cout << " " << int(*iter);
			//std::cin >> k;
			++rows;
			line_empty=true;
			indices.push_back(iter);
			if (cols != i && cols < 0) { cols = i; }
			if ((cols != i && cols > 0) || i==1)
			{
				file_is_OK = false;
						
					//	std::cout<<"error  "<<rows<<" "<<i<<"   "<<rows<<std::endl;	
						return false;	
			}
			if (i == cols) { last_valid_line = iter; }
			row_items.push_back(i);

			i = 1;

		}
	
	}

	indices.push_back(iter);
	--rows;
	//if(file_is_OK) std::cout<<"OK"<<std::endl;
	//else std::cout<<"KO"<<std::endl;
	//std::cout<<indices.size()<<std::endl;
	if (cols == 1 && file_is_OK) file_is_OK = false;

	if (file_is_OK) return true;
	else return false;
}

//std::string string_analyzer(const std::string &Text ){
//Date, Location, City, Name , DB Name , Application Name, Description, 
//Application Code, Legal Entity
//yyyy/mm/dd
//dd/mm/yyyy
//dd.mm.yyyy
//dd-mm-yyyy
//Handynr
//Tel nr
//
//}
//
//

void csv_file::basic_type()
{
basic_types.push_back("last name");
basic_types.push_back("first name");
basic_types.push_back("name");
basic_types.push_back("email");
basic_types.push_back("ip");
basic_types.push_back("exceldate");
basic_types.push_back("server");
basic_types.push_back("mobilenr");
basic_types.push_back("other");

}



csv_file::csv_file(std::string input)
	{
		file=input;
		if (csv_file::index()) { std::cout << "File Status OK" << std::endl; }
		else std::cout << "File Status Not OK" << std::endl;
	}

csv_file::csv_file(char *filename)
{	
	int N;
	std::ifstream input(filename, std::ios::binary);
	input.seekg(0,input.end);
	N=input.tellg();
	input.seekg(0,input.beg);
	N=N-input.tellg();
	char* data= new char[N];
	input.read(data,N);
	std::string help(data,N);
	delete[] data;
	file=help;
	
	if (csv_file::index()) { std::cout << "File Status OK" << std::endl; }
	else std::cout << "File Status Not OK" << std::endl;
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
	if (i == 1 && j == 1)
	{
		std::string A(start , end);
		return(A);
	}
	else {
		std::string A(start+1, end);
		return(A);
	}

	}

void csv_file::show_header()
	{
	int i;
	for(i=1;i<=cols;++i)
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
/*
bool csv_file::OK()
	{
	if(file_is_OK) return(true);
	else return(false);
	}
	*/
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



void csv_file::check()
{
size=sizeof(char)*file.size();
int i=1;
int k;
int duplicates=0;
primary_key_unique=true; 
std::vector<std::string> primary;
for(int i=2;i<=rows;++i){
primary.push_back(cell(i,1));
}
std::sort(primary.begin(),primary.end());

for(int i=0;i<primary.size()-1;++i) {
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
std::cout<<"number of characters.."<<file.size()<<std::endl;
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
std::cout << indices.size()*sizeof(siterator)/1000000  <<"MB"<< std::endl;

std::cout<<"rows.."<<rows<<"  colums..."<<cols<<std::endl;
/*cout<<"file has uncomitted changes";
//cout<<"number of changes";
*/
if (primary_key_unique && file_is_OK) return true;
else return false;
}




//void csv_engine::search_primary_key() {





//}



bool csv_file::operator== (const csv_file& lhs)
{
	if (file == lhs.file) return true;
	else false;


}
