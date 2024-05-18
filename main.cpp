#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
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
  std::string getName(){return name;}
  int getAge(){return age;}
  std::string getAddress(){return address;}
  
  void setName(std::string n){name = n;}
  void setAge(int a){age = a;}
  void setAddress(std::string ad){address = ad;}

};

class Student : public Person{
private: // since no inheritance, just put attributes private(?)
  std::string studentID; // assuming its alphanumeric, not just numeric
  std::string major;
  float gpa;
  std::map<std::string, char> grades; // whaaaat? you need a storage for grades to calculate GPA
  // it's [course], [letter grade]. following columbia's registrar, we'll need credits
  // so the str will be replaced with the Course class
  std::unordered_set<std::string> courses; //using a set is easier than searching through a array or vector to drop a course, and unordered sets are speedier than ordinary sets. also replace str with Course
public:
  Student(std::string id, std::string maj, std::unordered_set<std::string> c) : Person(std::string n, int a, std::string ad){
    studentID = id;
    major = maj;
    courses = c;
  }
  std::string getStudentID(){return studentID;}
  std::string getMajor(){return major;}
  float getGpa(){return gpa;}
  std::map<std::string, char> getGrades(){return grades;}
  std::unordered_set<std::string> getCourses(){return courses;}

  void setStudentID(std::string s){studentID = s;}
  void setMajor(std::string m){major = m;}
  void setGpa(float g){gpa = g;}
  void setGrades(std::map<std::string, char> g){grades = g;}
  void setCourses(std::unordered_set<std::string> c){courses = c;}

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
