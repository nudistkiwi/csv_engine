
#include <csv_engine.h>



std::vector<int> csv_file::index(char delimiter)
{//	
	//std::cout<<sizeof(siterator)<<" "<<sizeof(int)<<std::endl;
	//std::cout<<"Indexing File..."<<std::endl;
	file_begin=file.begin();
	file_end=file.end();	
	std::vector<int> errors;
	char newline='\n';
	int k;
	int i=1;
	cols=-1;
	rows=1;
	file_is_OK=true;
	siterator iter;
	indices.clear();
	lindex.clear();
	iter=file_begin;
	bool line_empty=false;
	bool delimiter_found;
	indices.push_back(iter);
	lindex.push_back(iter);
	int escape_count=0;

	for(iter=file_begin;iter!=file_end; ++iter)
	{
	//std::cout<<int(*iter)<<" ";
	

	if(int(*iter)==13){iter++;}

	if ('"' == *iter) {
		iter++;
		while('"'!=*iter){
		iter++;
			}
	 
	}

/*
	if('{' ==*iter)
	{
	
	escape_count=1;
	
	indices_sub_csv.push_back(iter+1);	
	while(escape_count!=0)
	{
	iter++;	
	if('}'==*iter){escape_count--;}	
	if('{'==*iter){escape_count++;}	
		
	}
	indices_sub_csv.push_back(iter);
	}
*/
	

	
		if (delimiter == *iter ) {
			
		//	line_empty=false;
			
			
			indices.push_back(iter);//std::cout<<std::endl;
			int los;
			
			i++;
		//
		}

		if ((newline == *iter || int(*iter) == 10)  && line_empty==false)
		{	//std::cin>>k;
			
			indices.push_back(iter);
			//lindex.push_back(iter+1);
				lindex.push_back(iter+1);
			if (cols != i && cols < 0) { cols = i; }
			if (cols != i && cols > 0)
			{	file_is_OK=false;
				
				errors.push_back(rows);
			}
			i = 1;
			++rows;		
		}
	
	}
	if(rows==1){cols=i;}

	indices.push_back(iter);
//	--rows;

	return(errors);
}




std::vector<int> csv_file::index()
{
	int a=0;
	int b=0;
	int c=0;
	
	clean();
	
	for(auto it:file){
	
	//std::cout<<int(it)<<" ";	
	if(it==';'){a++;}	
	if(it==','){b++;}	
	if(it=='\t'){c++;}	
	if(it=='\n'){break;}
	}
	for(auto it:file){
//	std::cout<<int(it)<<" ";	
	}
	int l;
//	std::cin>>l;

	
	char delimiter;
	if(a==b && a==c){delimiter=';';}
	if(a>b && a>c){delimiter=';';}
	if(b>c && b>a){delimiter=',';}
	if(c>a && c>b){delimiter='\t';}
	//std::vector<int> errors;
	std::cout<<a<<" "<<b<<" "<<c<<std::endl;
	//for(auto it:file){std::cout<<it;}
	errors=index(delimiter);
	//std::vector<int> error2;
//	std::vector<int>::iterator iter;
//	int j=1;

	

	
	//std::cin>>i;
	for(int i=0; i<errors.size();i++)
	{std::cout<<errors[i]<<" ";}
	std::cout<<std::endl;
	if(errors.size()!=0){
//	for(iter=errors.begin();iter!=errors.end();iter++)
//	{
//	while(*iter!=j){error2.push_back(j);j++;}	
//	}
//	std::vector<int> dummy;
//	rcdelete(error2,dummy);
//	index(';');

	}

	return errors;

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
//
/*
csv_file::csv_file(siterator&  start,siterator&  end)
	{
		file_begin=start;
		file_end=end;
		auto vec=index();
		if (csv_file::index().size()!=0) //{ std::cout << "File Status OK" << std::endl; } 
		std::cout << "File Status Not OK" << std::endl;
	}
*/

csv_file::csv_file(std::string input)
	{
		file=input;
		file_begin=file.begin();
		file_end=file.end();
		if (csv_file::index().size()!=0) 
		//{ std::cout << "File Status OK" << std::endl; }
		 std::cout << "File Status Not OK" << std::endl;
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
	file_begin=file.begin();
	file_end=file.end();
	if (csv_file::index().size()!=0) 
	//{ std::cout << "File Status OK" << std::endl; }
	 std::cout << "File Status Not OK" << std::endl;
 }

csv_file::csv_file()
{
file="test";	
file_begin=file.begin();
file_end=file.end();
csv_file::index();
lindex.clear();
}


csv_file::~csv_file()
{
indices.clear();
file.clear();
//indices_sub_csv.clear();
//delete sub_csv;
//std::cout<<"deleted"<<std::endl;

}


 void csv_file::write(char* filename)
	{
		std::ofstream stream(filename);
		stream<<file;
		stream.close();

	}

std::string csv_file::cell(int i,int j)const
	{
	if (j > cols) { j = cols; }
	if (i > rows) { i = rows; }
	int k = cols * (i - 1) + (j - 1);
	//std::cout<<k<<std::endl;
	siterator start = indices[k];
	siterator end = indices[k + 1];
	//siterator iter;
	
//	for(iter=start+1;iter!=end; ++iter)
//	{std::cout<<int(*iter)<< " ";}
	
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


void csv_file::replace(std::string A, std::string B)
{
	siterator iter;
	siterator iterN=file_temp.begin();
	siterator help;
	int i=0;
	std::vector<siterator> hits;

	for (iter = file_begin; iter != file_end; ++iter)
	{	

		if (*iter == A[0]) { 
			help=iter;
			i=0;
			while(A[i]==*iter && i<A.length())
			{
				++iter;
				i++;
			}
			if(A.length()==(i))
			{
			//for(i=0;i<B.size();i++)
			//{*iterN=B[i];}
			hits.push_back(help);
			}
		}
	}
	
	
	int delta= (B.size()-A.size())*hits.size();	
	file_temp.reserve(file.size()+delta);
	
	hits.push_back(file_end);
	iter=file_begin;
	file_temp.append(iter,hits[0]);
	for(i=1;i<hits.size();i++)
	{
	file_temp.append(B);
	file_temp.append(hits[i-1]+A.size(),hits[i]);
	}
	file=file_temp;
	file_temp.clear();
	file_begin=file.begin();
	file_end=file.end();
	index();
//	std::cout<<file<<std::endl;
	}

void csv_file::clean()
{
		
		

//for(auto o:lines){
//k = cols * (o - 1) ;

//file_temp.append(std::string(indices[k]+1,indices[k+cols]));
//}
bool co=true;

while(file.back()=='\n'){file.pop_back();}
//}




file_temp.reserve(file.size());

for(auto it=file.begin();it!=file.end();it++)
{
if(int(*it)==0 || *it=='\r'){
targets.push_back(it);
//*it='A';
}
//if(int(*it)>10){co=false;}
//if(int(*it)<0 && co){targets.push_back(it);}

}
std::cout<<"found  "<<targets.size()<<std::endl;

if(targets.size()>0){
auto it=file.begin();
for(auto iter:targets){
file_temp.append(it,iter);
it=iter+1;

}
file_temp.append(it,file.end());
file=file_temp;


file_temp.clear();
file_begin=file.begin();
file_end=file.end();
targets.clear();


}

}
void csv_file::uppercase(){

//for(auto it=file.begin();it!=file.end();it++)
for(auto & it:file)
{
if(it>=97 && 123>=it){
it=it-32;
}
//std::cout<<it;
}


}


void csv_file::repair(){

int flag=0;
int l;
		int k=1;

		std::vector<int> lines;
	bool line_ko=true;
while(line_ko){

	line_ko=false;
	for(int i=1;i<=cols;i++){
		if(cell(k,i)==""){
			line_ko=true;
			lines.push_back(k);
			//std::cout<<k<<" ";
			break;
		}
		
		}

k++;
}

if(lines.size()>0){
rdelete(lines);
std::cout<<"repaired"<<std::endl;
}

//file=file_temp;
//file_temp.clear();



}

void csv_file::swap_rows(int m, int n)
{
	int l,k;
	if(m>n){k=m;m=n;n=k;}

	file_temp.clear();
	file_temp.reserve(file.size());
	for (int i = 1; i <= rows; i++)
	{	l=i;
		if(i==m){l=n;}
		if(i==n){l=m;}
		for (int j = 1; j < cols; j++)
		{
			file_temp.append(cell(l, j));
			file_temp.append(";");
		}
		file_temp.append(cell(i, cols));
		if(i<rows) file_temp.append("\n");
	}
	file = file_temp;
	file_temp.clear();
	file_begin=file.begin();
	file_end=file.end();
	index();


}



void csv_file::swap_rows(std::vector<int> order)
{	int m=1;
	std::vector<int> check=order;
	std::sort(check.begin(),check.end());
	std::vector<int>::iterator niter;
	for(niter=check.begin();niter!=check.end();niter++)
	{if(*niter!=m){return;}m++;}
	m=0;
	//	while(m<rows && check[m]==(m+1)) std::cout<< check[m]<<" ";
//	std::cout << m << "  " << rows;
//	if(m==rows){
	int l;
	file_temp.clear();
	file_temp.reserve(file.size());
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= cols; j++)
		{	l=order[i-1];
		//std::cout << l << std::endl;
			file_temp.append(cell(l, j));
			if(j<cols) file_temp.append(";");
			if(j==cols && i!=rows) file_temp.append("\n");
		}
		//file_temp.append(cell(i, cols));
		//if(l!=rows) file_temp.append("\n");
	}
	file = file_temp;
	
	file_temp.clear();
	file_begin=file.begin();
	file_end=file.end();
	index();
//	}

}


void csv_file::rdelete(std::vector<int> delete_rows)
{	int i;
	if(delete_rows.size()>0){
	file_temp.clear();
	file_temp.reserve(file.size());
	std::sort(delete_rows.begin(),delete_rows.end());
siterator it=file.begin();
//file_temp.append(lindex[0],lindex[delete_rows[0]-1]);
//std::cout<<lindex.size()<<std::endl;
std::vector<siterator> pair;
pair.push_back(file.begin());
for(auto it=delete_rows.begin();it!=delete_rows.end();it++)	{
pair.push_back(lindex[*it-1]);
pair.push_back(lindex[*it]);
}
pair.push_back(file.end());
std::cout<<pair.size();


if(pair.size()>2 && pair.size()%2==0){
for(int i=0;i<pair.size()/2;i++ )	{
auto k=pair[2*i+1];
auto j=pair[2*i];
file_temp.append(j,k);
}
}


file=file_temp;
file_temp.clear();
file_begin=file.begin();
file_end=file.end();
index();
}
}


void csv_file::sort(int m) 
{
	int i;
	std::vector<std::pair<std::string,int>> arr;


	for(int i=1;i<=rows;i++){
	arr.push_back(std::make_pair(cell(i,m),i));
	}
	std::sort(arr.begin(),arr.end());

	std::vector<int> num;
	for(int i=0;i<rows;i++){
	num.push_back(arr[i].second);
	//std::cout << num.back();
	}
	arr.clear();
	swap_rows(num);

}






//void csv_engine::search_primary_key() {







//}

bool csv_file::status(){
double  nice_size;
int i=0;
std::vector<std::string> Byte;
Byte.push_back("Bytes");
Byte.push_back("KiloBytes");
Byte.push_back("MegaBytes");
Byte.push_back("GigaBytes");
std::cout<<"number of characters.."<<file.size()<<std::endl;
//std::cout<<"primary key is unique...."<<primary_key_unique<<std::endl;
if(errors.size()==0){
std::cout<<"file is healthy...."<<"Yes"<<std::endl;}
if(errors.size()!=0){
std::cout<<"file is healthy...."<<"No"<<std::endl;}
//std::cout<<"File has " <<Nsub_csv<<" Sub Files"<<std::endl;
std::cout<<"file has size...";
nice_size=file.size();
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
//if (primary_key_unique && file_is_OK) return true;
//std::cout<<file<<std::endl;
 return false;

}
