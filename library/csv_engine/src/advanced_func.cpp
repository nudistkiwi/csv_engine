#include <csv_engine.h>
/*
void csv_file::swap_rows(int n,int m)
{
	std::pair<int,int> p(i,j);	
	swap_rows.push_back(p);
	int i,j;	
	for(i=1;i<=cols;++i)
	{	
		for(j=1;j<rows;++j)
		{
		//	std::cout<<cell(j,i)<<" ";
			file_temp.append(cell(j,i));
		//	std::cout << cell(j, i)<<std::endl;
			file_temp.append(";");
		}
		
		file_temp.append(cell(rows,i));
		file_temp.append("\n");
	}
file=file_temp;
file_temp.clear();
index();





}
void csv_file::swap_cols(int i,int j)
{
	std::pair<int,int> p(i,j);	
	swap_cols.push_back(p);

}

void csv_file::delete_col(int i)
{
	delete_col.push_back(i);

}

void csv_file::delete_row(int i)
{
	delete_row.push_back(i);

}


*/
void csv_file::set_data_type()
{
	std::string type;
	data_type.clear();
	for(int i=1;i<=cols;i++)
	{
	std::cout<<cell(1,i)<<"   "<<cell(2,i)<<std::endl;
	std::cin>>type;
	data_type.push_back(type);
	}

}

std::string csv_file::get_data_type(int i)
{
return(data_type[i]);

}

void csv_file::set_data_type(std::vector<std::string> A)
{
	data_type.clear();
	data_type=A;

}




void csv_file::deleteC(char A)
{


	siterator iter;
	int i;
	file_temp.reserve(file.size());
	for (iter = file.begin(); iter != file.end(); iter++)
	{
		if (*iter !=A ) { file_temp.append(1, *iter); }
	}
	

	file = file_temp;
	file_temp.clear();
	index();



}

void csv_file::replace(char A, char B) 
{
	siterator iter;
	for (iter = file.begin(); iter != file.end(); ++iter) 
	{
		if (*iter == A) { *iter = B; }
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
		file_temp.append("\n");
	}
	file = file_temp;
	file_temp.clear();
	index();


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
		file_temp.append("\n");
	}
	file = file_temp;
	file_temp.clear();
	index();


}

void csv_file::clean()
{
whitelist.push_back('\n');
whitelist.push_back(' ');
whitelist.push_back('\t');

siterator iter;
int i;
file_temp.reserve(file.size());
for(iter=file.begin();iter!=file.end();iter++ )
{
if(int(*iter)>31 || int(*iter) < 0){file_temp.append(1,*iter);}
else {
	//if (int(*iter) < 0) { std::cout << int(*iter) << " "; }
	//std::cout << int(*iter) << std::endl;
	//std::cin >> i;
for(i=0;i<whitelist.size();i++){
if(whitelist[i]==*iter){
	file_temp.append(1,*iter);
	break;}}

}
}

file=file_temp;
file_temp.clear();
index();




}


void csv_file::swap_rows(std::vector<int> order) 
{	int m=0;
	std::vector<int> check=order;
	std::sort(check.begin(),check.end());
//	while(m<rows && check[m]==(m+1)) std::cout<< check[m]<<" ";
//	std::cout << m << "  " << rows;
//	if(m==rows){
	int l;	
	file_temp.clear();
	file_temp.reserve(file.size());
	for (int i = 1; i <= rows; i++)
	{		
		for (int j = 1; j < cols; j++)
		{	l=order[i-1];
		//std::cout << l << std::endl;
			file_temp.append(cell(l, j));
			file_temp.append(";");
		}
		file_temp.append(cell(i, cols));
		file_temp.append("\n");
	}
	file = file_temp;
	file_temp.clear();
	index();
//	}

}




void csv_file::rcdelete(std::vector<int> delete_rows,std::vector<int> delete_cols)
{	if(delete_rows.size()>0 || delete_col.size()>0){
	file_temp.clear();
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
		file_temp.append("\n");
	}


file=file_temp;
file_temp.clear();
index();
}

}

void csv_file::search_primary_key()
{	int size;
	unique_col.clear();
	//std::vector<bool> unique;
	std::set<std::string> list;
	for(int j=1;j<=cols;j++){list.clear();
	for(int i=1;i<=rows;i++){
		size=list.size();
		list.insert(cell(i,j));
		if(size==list.size()){break;}
	}

	std::cout << rows << "  " << list.size() << std::endl;
	if (list.size() == rows)  unique_col.push_back(true); 
		else unique_col.push_back(false);
	
	}
	
	
	for (int i = 1; i <= cols; ++i)
	{
		std::cout << i << ". " << csv_file::cell(1, i) <<"..."<<unique_col[i-1]<< std::endl;
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
	index();
	
}





void csv_file::transponse() 
{	file_temp.clear();
	file_temp.reserve(file.size());
	int i,j;	
	for(i=1;i<=cols;++i)
	{
		for(j=1;j<rows;++j)
		{
		//	std::cout<<cell(j,i)<<" ";
			file_temp.append(cell(j,i));
		//	std::cout << cell(j, i)<<std::endl;
			file_temp.append(";");
		}
		
		file_temp.append(cell(rows,i));
		file_temp.append("\n");
	}
file=file_temp;
file_temp.clear();
index();

//cols=j;
//cols=rows;
//rows=j;

}

