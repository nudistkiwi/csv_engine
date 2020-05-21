#include <csv_engine.h>
#include <chrono>
#include <stdio.h>
#include <string.h>

std::string testd(int i, int j) {
	return("hallo");
}

/*
void testcases(csv_file A,csv_file B) {
	if(A==B){std::cout<<"Passed"<<std::endl;}
	else{std::cout<<"Failed"<<std::endl;}
}

*/

int main(){
int i,j;
int k;




//csv_file *testfiles= new csv_file[9];
//delete[] testfiles;

//testfiles[0]=csv_file("test0.csv");
//csv_fil
//char file[]="files.csv";

std::string filess="files.csv";
filess="DAL_DB-en.csv";
char *filer= new char[filess.length()+1];
copy(filess.begin(),filess.end(),filer);
std::cout<<filer<<std::endl;

std::cout<<filess<<std::endl;
//char file[]="BIA_DR_Readiness_Details-en.csv";
csv_file A(filer);
A.status();
//A.clean();
delete[] filer;
std::string done;


while(0==0){
std::cin>>i;
std::cin>>j;
//std::string ad=A.celli,j);
//char ls=ad[0];
std::cout<<A.celll(i,j)<<std::endl;
//std::cout<<int(ls)<<std::endl;

}

for(int k=1;k<=A.Nrows();k++){
	std::cout<<A.cell(k,1)<<std::endl;

	char *arr=new char[A.cell(k,1).length()+1];
	strcpy(arr, A.cell(k,1).c_str()); 
	//std::cout<<arr;
	csv_file B(arr);
	B.repair();
	for(int j=1;j<=100;j++){
	if(j<=B.Ncols()){
	done.append(B.cell(1,j));}	
	done.append(";");	

			}
		
	done.append(1,'\n');	
	for(int j=1;j<=100;j++){
	if(j<=B.Ncols()){
	done.append(B.cell(2,j));}	
	done.append(";");	

			}
		
	done.append(1,'\n');	
	delete[] arr;



//std::cout<<int(ls)<<std::endl;



}
csv_file B(done);
B.write("absolut.csv");
//csv_file B("test3t.csv");

//A.replace("A","test");
//B.print();
//A.replace("B","hall");
//A.print();
//std::cout<<std::endl;
//A.check();
//A.clean();
//A.print();
//A(1,2,3,4);
//A.print();
//A.replace("\r","");
//A.transponser();
//A.print();
//A.swap_cols(2,6);
//A.swap_rows(std::vector<int>{1,3,2});
//A.write("hsdh.csv");
std::vector<int> As {1,2};

//A.uppercase();

//A.clean();
//A.repair();
//A.status();
A.write("hsdh.csv");

//csv_file B("hsdh.csv");
//B.check();
//B.status();

//A.print();
//A.rcdelete(std::vector<int>{1,4},std::vector<int>{2,3});
//A.transponse();
//B.check();
//B.status();

//A.status();
//std::cin>>i;
//A.replace("B","hall");
//A.print();
//A.check();
//A.status();


while(0==0){
std::cin>>i;
std::cin>>j;
std::string ad=A.cell(i,j);
//char ls=ad[0];
std::cout<<A.cell(i,j)<<std::endl;
//std::cout<<int(ls)<<std::endl;

}

std::cin>>i;






















/*
//string all=ingest_xlsx(fi);
char file[]="BA_DATA.csv";

auto start_t=std::chrono::system_clock::now();
csv_file test(file);
auto end_t=std::chrono::system_clock::now();
std::chrono::duration<double> delta=end_t-start_t;
std::cout<<delta.count()<<std::endl;
test.deleteC('\r');

//test.transponse();
std::vector<int> asd = {2,4,1,3,5};
test.sort(5);
//test.search_primary_key();
//test.check();
//test.status();
//test.clean();

//test.loop(&testd);
char f[] = "hi.csv";
test.write(f);
std::cin>>i;

//std::cout<<"cols  "<<test.Ncols()<<std::endl;
//std::cout<<"rows  "<<test.Nrows()<<std::endl;
//test.transponse0();
//test.print();
start_t = std::chrono::system_clock::now();
std::vector<int> Ax{25};
std::vector<int> Bx{25};
test.rcdelete(Ax,Bx);
test.check();
test.status();
test.swap_cols(1,24);
//test.transponse();
end_t = std::chrono::system_clock::now();
delta = end_t - start_t;
std::cout << delta.count() << std::endl;

test.check();
test.status();
//test.print();
//std::cin>>i;

/*
start_t = std::chrono::system_clock::now();

test.transponse();
end_t = std::chrono::system_clock::now();
delta = end_t - start_t;
std::cout << delta.count() << std::endl;

test.check();
test.status();
//test.print();
//std::cin >> i;


csv_file test2(file);

if (test2 == test) { std::cout << "success"; }
else std::cout << "nope";

start_t=std::chrono::system_clock::now();
test.transponse();
end_t=std::chrono::system_clock::now();
delta=end_t-start_t;
std::cout<<delta.count()<<std::endl;
//test.print();
test.print();
test.check();
test.status();

std::cin >> i;
start_t=std::chrono::system_clock::now();
test.transponse();
 end_t=std::chrono::system_clock::now();
std::chrono::duration<double> delta2=end_t-start_t;
std::cout<<delta2.count();
test.print();
std::cin >> i;
test.write("test.csv");
//test.check();
//test.status();
std::vector<int> as{2};
std::vector<int> bs{2};
//test.print();
//test.delete_cr(as,bs);

//test.print();

while(0==0){
std::cin>>i;
std::cin>>j;
std::cout<<test.cell(i,j)<<std::endl;

}
test.show_header();
std::cin>>i;
//cout<<sizeof(char)*all.size()<<" bytes"<<endl;
*/

}
