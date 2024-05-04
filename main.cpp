#include <iostream>
#include <string>
#include "gtest/gtest.h"

class Person{
protected:
  std::string name;
  int age;
  std::string address;
public:
  Person(std::string n, int a, std::string ad){ // constructor
    name = n;
    age = a;
    address = ad;
  }
  // Getters and setters, something I just learned about.
  // I assume that this would have S O M E administrative use (name changes, error correction)
  // but boy is it going to be tedious
  // but encapsulation yaaaaay

  std::string getName(){return name;}
  int getAge(){return age;}
  std::string getAddress(){return address;}
  
  void setName(std::string n){name = n;}
  void setAge(int a){age = a;}
  void setAddress(std::string ad){address = ad;}

};

int main(){
  std::cout << "I am alive (not really)" << '\n'; // make this cooler, like, a bios boot screen
  return 0; 
}
