#include <csv_engine.h>



void csv_file::collapse(){


}


void csv_file::show_header()
	{
	int i;
	for(i=1;i<=cols;++i)
	 {
    std::cout<<i<<". "<<csv_file::cell(1,i)<<std::endl;
	 }	
	}




void csv_file::print()
{int i,j;

//std::cout<<cell(1,1)<<" ";
for(i=1;i<=rows;i++)
	{
		for(j=1;j<cols;j++)
		{
			std::cout<<cell(i,j)<<" ";
		}
	std::cout<<cell(i,cols);
	std::cout<<std::endl;
	}
}









void csv_file::swap_cols(int m, int n)
{
	int l,k;
	if(m>n){k=m;m=n;n=k;}
	file_temp.clear();
	file_temp.reserve(file.size());
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			if ( j == n) { file_temp.append(cell(i, m)); }
			if ( j == m) { file_temp.append(cell(i, n)); }
			if(j!=m && j!=n){ file_temp.append(cell(i, j));}
			file_temp.append(";");
		}
		if(n==cols)file_temp.append(cell(i,m ));
		else file_temp.append(cell(i, cols));
		if(i<rows) file_temp.append("\n");
	}
	file = file_temp;
	file_temp.clear();
	file_begin=file.begin();
	file_end=file.end();
	index();


}




void csv_file::cdelete(std::vector<int> delete_cols)
{	if(delete_rows.size()>0 || delete_cols.size()>0){
	file_temp.clear);
	file_temp.reserve(file.size());
	int i,j,l,m,n,k;
	k=0;
	std::sort(delete_rows.begin(),delete_rows.end());
	std::sort(delete_cols.begin(),delete_cols.end());
	std::vector<int> index_col;
	std::vector<int> index_row;

	i=0;
 	k=0;
	while(i++<cols)
	{
	if(i!=delete_cols[k]){index_col.push_back(i); }
	else {k++; while(delete_cols[k]==delete_cols[k-1]){k++;}}
	}

	 i=0;
 	k=0;
	while(i++<rows)
	{
	if(i!=delete_rows[k]){index_row.push_back(i); }
	else {k++; while(delete_rows[k]==delete_rows[k-1]){k++;}}
	}

	for(i=0;i<index_row.size();++i){
		{
			l=index_row[i];
		for(j=0;j<index_col.size()-1;++j)
		{
		//	std::cout<<cell(j,i)<<" ";
			m=index_col[j];
			file_temp.append(cell(l,m));
		//	std::cout << cell(j, i)<<std::endl;
			file_temp.append(";");
					    }
		}
		file_temp.append(cell(l,index_col.back()));
			if(i<index_row.size()-1) file_temp.append("\n");
	}


file=file_temp;
file_temp.clear();
file_begin=file.begin();
file_end=file.end();
index();
}
}













void csv_file::loop(std::string (*func)(int, int))
{


	file_temp.clear();
	file_temp.reserve(file.size());
	for (int i = 1; i <= rows; i++)
	{


		for (int j = 1; j < cols; j++)
		{
			file_temp.append(func(i, j));
			file_temp.append(";");
		}
		file_temp.append(func(i, cols));
		//file_temp.append(1, '\r');
		file_temp.append(1,'\n');
	}
	file = file_temp;
	file_temp.clear();
	file_begin=file.begin();
	file_end=file.end();
	index();

}





void csv_file::transponse()
{	//file_temp.clear();

file_temp.clear();
	file_temp.reserve(file.size());
	
	for (int j = 1; j <= cols; j++)
		{	
	for (int i = 1; i <= rows; i++)
	{
		
		//std::cout << l << std::endl;
			file_temp.append(cell(i, j));
			std::cout<<cell(i, j)<<std::endl;
			if(i<rows) file_temp.append(";");
			if(j!=cols && i==rows) file_temp.append("\n");
		}
		//file_temp.append(cell(i, cols));
		//if(l!=rows) file_temp.append("\n");
	}
	file = file_temp;
	write("gjsg.csv");
	file_temp.clear();
	file_begin=file.begin();
	file_end=file.end();
	index();


}


void csv_file::insert(std::string str){

if(cols>0){
if(current_col>0){	
if(current_col<cols){file.append(";");file.append(str);current_col++;}
else if(current_col==cols){file.append("\n");file.append(str);current_col=1;}
}
else
{
file.clear();
file.append(str);
current_col=1;
}

}
}
/*
void sort(int k,int l){
//csv_file temp=*this;
csv_file temp();
//sort(k);
int=1;
int j=1;
int start=1;
int end;
for(int i=1;i<rows;i++)
{
if(cell(i,k)!=cell(i+1,k)){
end=i;
csv_file help=sub_csv(start,end,1,cols);
help.sort(l);
temp=temp+help;
start=end+1;
}


}

}
/*
void sort(){
//csv_file temp=*this;
csv_file temp();
//sort(k);
int=1;
int j=1;
int start=1;
int end;
sort(1);
for(int i=1;i<cols;i++)
{	
sort(i,i+1);


}

}*/


csv_file csv_file::operator+(const csv_file& lhs)
{



if(cols==lhs.cols){
}

csv_file temp("");

for (int i = 1; i <= rows; i++)
	{	
		for (int j = 1; j < cols; j++)
		{
			
			temp.file.append(cell(i, j));
			temp.file.append(";");
		}
		temp.file.append(cell(i, cols));
		if(i<rows ) temp.file.append("\n");
	}	



for (int i = 1; i <= lhs.rows; i++)
	{	
		for (int j = 1; j < lhs.cols; j++)
		{
		//	std::string asdf=lhs.cell(i, j);
			temp.file.append(lhs.cell(i, j));
			temp.file.append(";");
		}
		temp.file.append(cell(i, lhs.cols));
		if(i<lhs.rows ) temp.file.append("\n");
	}	




temp.index();
return temp;


}



csv_file csv_file::operator*(const csv_file& lhs)
{

csv_file temp("");
if(rows==lhs.rows){



for (int i = 1; i <= rows; i++)
	{	
		for (int j = 1; j < cols; j++)
		{
			
			temp.file.append(cell(i, j));
			temp.file.append(";");
		}
			for (int j = 1; j < lhs.cols; j++)
		{
			
			temp.file.append(lhs.cell(i, j));
			temp.file.append(";");
		}
		
		temp.file.append(lhs.cell(i, lhs.cols));
		if(i<rows ) temp.file.append("\n");
	}	





}
temp.index();
return temp;
}


bool csv_file::operator== (const csv_file& lhs)
{
	if (file == lhs.file){ return(true);}
	else{ return(false);}


}



csv_file csv_file::operator()(int m, int n,int k,int l)
{



csv_file temp("");
if(k==1 && l==cols){
int g=cols*(m-1);
temp.file.append(indices[m],indices[n]);

}
else{
for (int i = m; i <= n; i++)
	{	
		for (int j = k; j < l; j++)
		{
			
			temp.insert(cell(i, j));
			temp.insert(";");
		}
		temp.insert(cell(i, l));
		if(i<n ) temp.insert("\n");
	}	

}
temp.index();
return temp;

}



std::string csv_file::operator()(int i, int j)
{
/*
siterator end=line_break[i];
siterator start;
int k=0;
while(k!=j)
{ 


if(';'==end || '/n'==end ){k++;}

start=end;
end++;
}
*/
return("");

}


void csv_file::check()
{
/*

std::vector<int> del1;
std::vector<int> del2;


int l;
		int k=1;
if(errors.size()==0){

	bool line_ko=true;
while(line_ko){

	line_ko=false;
	for(int i=1;i<=cols;i++){
		if(cell(k,i)==""){
			//std::cout<<k<<std::endl;
		//	std::cin>>l;
			line_ko=true;
			//del1.push_back(k);
			break;
		}
		
		}

k++;
}

k = cols * (k - 2) ;
std::cout<<k<<std::endl;

file_temp=std::string(indices[k]+1,file.end());
std::cin>>k;
file=file_temp;
write("jgsdasj.csv");

file_temp.clear();
index();
//rcdelete(del1);
//std::cout<<file<<std::endl;
//
*/
size=sizeof(char)*int(file_end-file_begin);
int i=1;

int duplicates=0;
//std::sort(primary.begin(),primary.end());

//			}
siterator iter;
int rowc=0;
int colc=0;


//std::vector<int> row_cols;
//for(iter=file_begin;iter!=file_end;++iter){
//if(*iter==';'){++colc;}
//if(*iter=='\n'){colc=0;row_cols.push_back(colc);}
//}

//std::sort(row_cols.begin(),row_cols.end());
//if(row_cols.front()==row_cols.back()){file_is_OK=true;}



}

