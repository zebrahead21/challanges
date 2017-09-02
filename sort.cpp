#include <algorithm>
#include <iostream>
#include <list>
#include <fstream>
#include <string>

bool compare(const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i]) < tolower(second[i])) return true;
    else if (tolower(first[i]) > tolower(second[i])) return false;
    ++i;
  }
  return (first.length() < second.length());
}

int main(int argc, char* argv[]) {

	std::ifstream myfile;
	std::string name;
	std::list<std::string> mylist; 

	myfile.open(argv[1]);

	while(std::getline(myfile, name)) {
		mylist.push_back(name);
	}

	mylist.sort(compare);
	for (std::list<std::string>::iterator it = mylist.begin(); it != mylist.end(); it++)
    std::cout<<*it<<std::endl;

	myfile.close();

}