#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>  
#include <cstdlib>
std::string creatfile()
{
  srand((unsigned int)time(NULL));

  std::ofstream outfile;
  std::string name = "test.txt";
  outfile.open(name);
  outfile<<std::setw(10)<<"x"<<std::setw(10)<<"y"<<std::setw(10)<<"z"<<std::endl;

  int x,y,z;
  for (int i = 0;i<100;i++)
  {
    x = rand() % 100;
    y = rand() % 100;
    z = rand() % 100;

    outfile<<std::setw(10)<<x<<std::setw(10)<<y<<std::setw(10)<<z<<std::endl;
  }
  outfile.close();
  return name;
}
void readfile(std::string filename)
{
  std::ifstream in;;
  in.open(filename);
  char a[5],b[5],c[5];
  int x,y,z;
  int line = 0;
  in>>a>>b>>c;
  std::cout<<"title: "<<std::setw(3)<<a<<std::setw(10)<<b<<std::setw(10)<<c<<std::endl;

  while(1)
  {
    in>>x>>y>>z;
    if (in.eof())
      break;
    line++;
    if (line%10==0)
      std::cout<<std::setw(10)<<x<<std::setw(10)<<y<<std::setw(10)<<z<<std::endl;
  }
  in.close();
}

int main()
{
  std::string filename = creatfile();
  readfile(filename);
  std::cout<<"\n-----------end!"<<std::endl;
  return 0;
}

