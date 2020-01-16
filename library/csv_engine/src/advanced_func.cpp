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

void csv_file::swap_rows(std::vector<int> order) 
{	int m=0;
	std::vector<int> check=order;
	std::sort(check.begin(),check.end());
	while(m++<rows) && check[m]==m);
	if(m==rows){
	int l;	
	file_temp.clear();
	file_temp.reserve(file.size());
	for (int i = 1; i <= rows; i++)
	{		
		for (int j = 1; j < cols; j++)
		{	l=order[i];
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
/*

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
*/
