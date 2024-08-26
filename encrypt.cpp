#include "encrypt.h"
#include <fstream>
#include<cctype>

bool cipher (string& content , bool mode ){
  int shift  = mode ? 3 : -3 ;

  for(char& ch : content){
    if(isalpha(ch)){
      char base = isupper(ch)? 'A' : 'a';
      ch = static_cast<char>((ch-base +shift + 26) % 26+base);
    }
  }

return true ;
}

using namespace std;

bool encryptfile(const string &filename , bool mode){
  ifstream inFile(filename);

if(!inFile){
  return false ;
}

//read the file 

string content ((istreambuf_iterator<char>(inFile)),{});
inFile.close();

if (cipher(content , mode )){

ofstream outfile(mode ? "encrypted_" + filename : "decrypted_" + filename );
if(!outfile){
  return false;

}

outfile << content ;

outfile.close();

return true ;

}
return false;

}
