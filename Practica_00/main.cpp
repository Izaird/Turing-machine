#include <iostream>
#include <fstream>
#include <string>
#include <vector>





std::vector<std::string> str_to_vect(std::string str);

int main(){
  std::fstream file;
  std::string line;
  std::vector<std::string> states, alphabet, start, accept;
  file.open("archivo2.txt");
  file >> line;  
  states = str_to_vect(line);
  file >> line;  
  alphabet = str_to_vect(line);
  file >> line;  
  start.push_back(line);
  file >> line;  
  accept = str_to_vect(line);
    for (std::size_t i = 0; i < states.size(); i++)
        std::cout << states[i] << std::endl;

  
}




std::vector<std::string> str_to_vect(std::string str){
  std::vector<std::string> vect;
  std::string aux;
  for(int i=0; i < str.length(); i++){
    if(str[i]==44){
      vect.push_back(aux);
      aux.clear();
    }
    else
      aux += str[i];
  }
  vect.push_back(aux);
  aux.clear();

  return vect;
}