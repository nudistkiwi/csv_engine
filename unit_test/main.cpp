#include <csv_engine.h>
#include <chrono>
int main(){
int i,j;
int k;

//string all=ingest_xlsx(fi);
char file[]="BA_DATA.csv";

auto start_t=std::chrono::system_clock::now();
csv_file test(file);
auto end_t=std::chrono::system_clock::now();
std::chrono::duration<double> delta=end_t-start_t;
std::cout<<delta.count()<<std::endl;
test.check();
test.status();
std::cin>>i;
//std::cout<<"cols  "<<test.Ncols()<<std::endl;
//std::cout<<"rows  "<<test.Nrows()<<std::endl;
//test.transponse0();
//test.print();
start_t = std::chrono::system_clock::now();

test.transponse();
end_t = std::chrono::system_clock::now();
delta = end_t - start_t;
std::cout << delta.count() << std::endl;

test.check();
test.status();
//test.print();
//std::cin>>i;


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
/*
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
*/
while(0==0){
std::cin>>i;
std::cin>>j;
std::cout<<test.cell(i,j)<<std::endl;

}
test.show_header();
std::cin>>i;
//cout<<sizeof(char)*all.size()<<" bytes"<<endl;
}
