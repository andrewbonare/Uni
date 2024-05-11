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

TEST(PersonTest, Getters){
  Person test("John Doe", 21, "1 Main St.");
  EXPECT_EQ(test.getName(), "John Doe");
  EXPECT_EQ(test.getAge(), 21);
  EXPECT_EQ(test.getAddress(), "1 Main St.");
}

TEST(PersonTest, Setters){
   Person test("John Doe", 21, "1 Main St.");
   test.setName("Taro Yamada"); // japanese john doe equiv
   test.setAge(20);
   test.setAddress("N/A"); // residency program?
   EXPECT_EQ(test.getName(), "Taro Yamada");
   EXPECT_EQ(test.getAge(), 20);
   EXPECT_EQ(test.getAddress(), "N/A");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
