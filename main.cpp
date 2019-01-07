#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

bool esManuel(int num);
bool esRavenclaw(int num);
bool primo(int num);
bool isRorM(int num, char mode);

int main(){
  ofstream mfile;
  ofstream rfile;
  ofstream ifile;
  ofstream ufile;
  int rango;
  bool c=true;
  while(c){
    mfile.open("Manuel.txt");
    rfile.open("Ravenclaw.txt");
    ifile.open("primosdemanuel.txt");
    ufile.open("unionRavenclawManuel.txt");
    cout<<"Range?: ";
    cin>>rango;
    int contm=0;
    int contr=0;
    int conti=0;
    int contu=0;
    for(int i=0;i<rango;i++){
      int unity=0;
      if(isRorM(i,'m')){
         contm++;
         mfile<<i<<endl;
         if(primo(i)){
           conti++;
           ifile<<i<<endl;
         }
         unity++;
       }
      if(isRorM(i,'r')){
         contr++;
         unity++;
         rfile<<i<<endl;
       }
       if(unity==2){
         ufile<<i<<endl;
         contu++;
       }
    }
    cout<<" Range "<<rango<<endl;
    cout<<"There are "<<contm<<" manuel numbers"<<endl;
    cout<<"There are "<<contr<<" ravenclaw numbers"<<endl;
    cout<<"There are "<<conti<<" primes man-numbers"<<endl;
    cout<<"There are "<<contu<<" numbers at the intersection"<<endl;
    mfile.close();
    rfile.close();
    ifile.close();
    ufile.close();
    cout<<"Continue? (1=Yes, 0=No): ";
    cin>>c;
  }
}

bool primo(int num){
  int cont=0;
  for(int i=2;i<=num/2;i++){
    if(num%i==0){
      cont++;
      i=num;//Se que esto es muy warro pero es que no quiero hacer el while
    }
  }
  if(cont>0){
    return false;
  }else{
    return true;
  }
}

bool isRorM(int num, char mode){
  int dig=0;
  bool ans;
  int a=num;
  int fnum;
  while(a/10!=0){
    a/=10;
    dig++;
  }
  a=num;
  if(mode=='m'){
    int cont=0;
    for(int i=dig;i>=0;i--){
      int p=pow(10,i);
      cont+=a/p;
      a=a%p;
    }
    fnum=cont;
  }else if(mode=='r'){
    int cont=1;
    for(int i=dig;i>=0;i--){
      int p=pow(10,i);
      cont*=a/p;
      a=a%p;
    }
    fnum=cont;
  }
  if(fnum>9){
    if(mode=='m'){
      ans=isRorM(fnum,'m');
    }else{
      ans=isRorM(fnum,'r');
    }
  }else if(fnum==8){
    ans=true;
  }else{
    ans=false;
  }
  return ans;
}
