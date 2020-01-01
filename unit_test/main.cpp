#include <csv_engine.h>
int main(){
int i,j;
int k;

//string all=ingest_xlsx(fi);

char file[]="BA_DATA.csv";
csv_file test(file);
std::cout<<"cols  "<<test.Ncols()<<std::endl;
std::cout<<"rows  "<<test.Nrows()<<std::endl;
//test.print();
//test.transponse();
std::vector<int> as{2};
std::vector<int> bs{2};
//test.print();
//test.delete_cr(as,bs);
//test.print();
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
