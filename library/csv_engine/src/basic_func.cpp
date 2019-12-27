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


csv_file::csv_file(std::string input){
file=input;
csv_file::index();
}

