#include <fstream>
#include <string>
#include <iostream>
#include <vector>


static void show_usage(std::string name)
{
  std::cerr <<"Usage: " << argv[0] << " <> "<<std::endl;
}

int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    show_usage(argv[0]);
    return 1;
  }
  
  std::cout<< argv[1] << " says hello, "<<argv[2] <<"!"<<std::endl;
  return 0;
}
