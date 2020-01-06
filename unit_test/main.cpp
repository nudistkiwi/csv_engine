#include <csv_engine.h>
#include <chrono>
int main(){
int i,j;
int k;

//string all=ingest_xlsx(fi);

char file[]="ab.csv";
csv_file test(file);
std::cout<<"cols  "<<test.Ncols()<<std::endl;
std::cout<<"rows  "<<test.Nrows()<<std::endl;
//test.transponse0();

test.transponse();
test.print();
//test.write("test.csv");
//test.check();
//test.status();
std::vector<int> as{2};
std::vector<int> bs{2};
//test.print();
//test.delete_cr(as,bs);
std::cin >> i;
test.print();

test.check();
test.status();
while(0==0){
std::cin>>i;
std::cin>>j;
std::cout<<test.cell(i,j)<<std::endl;

}
test.show_header();
std::cin>>i;
//cout<<sizeof(char)*all.size()<<" bytes"<<endl;
}
