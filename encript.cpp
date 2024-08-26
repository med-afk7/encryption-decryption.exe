#include <iostream>
#include<fstream>
#include <string>
#include "encrypt.h"


 using namespace std ;



int main (){

string filename ;
char mode ; 

cout<<"Enter a file name ;"<<endl;
cin>> filename ;

cout<<"Press E to encrypt and D to decrypt"<<endl;
cin >> mode ;

if (mode == 'e' || mode == 'E'){
  if(encryptfile(filename , true )){
    cout<<"File encrypted !"<<endl;
  }
  else{
    cerr<<"Couldn't encrypt the file "<<endl ;
  }

}
else if (mode == 'd' || mode == 'D'){
  if(encryptfile(filename , false)){
    cout<<"File decrypted !"<< endl;
  }
  else{
    cerr<<"Couldn't decrypt the file "<<endl;
  }
}
else{
  cerr<<"Error : Invalid mode selection Use 'e' or 'd' for encryption or decryption "<<endl;
}


}
