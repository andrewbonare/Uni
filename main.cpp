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
  std::map<std::string, std::string> grades; // whaaaat? you need a storage for grades to calculate GPA
  // it's [course], [letter grade]. following columbia's registrar, we'll need credits
  // so the str will be replaced with the Course class
  std::unordered_set<std::string> courses; //using a set is easier than searching through a array or vector to drop a course, and unordered sets are speedier than ordinary sets. also replace str with Course
public:
  Student(std::string id, std::string maj, std::unordered_set<std::string> c) : Person("unnamed", 0, "N/A"){ // this means that students will need to have name,age,address set outside of constructor or i will have to fnagle a solution
    studentID = id;
    major = maj;
    courses = c;
  }
  std::string getStudentID(){return studentID;}
  std::string getMajor(){return major;}
  float getGpa(){return gpa;}
  std::map<std::string, std::string> getGrades(){return grades;}
  std::unordered_set<std::string> getCourses(){return courses;}

  void setStudentID(std::string s){studentID = s;}
  void setMajor(std::string m){major = m;}
  void setGpa(float g){gpa = g;}
  void setGrades(std::map<std::string, std::string> g){grades = g;}
  void setCourses(std::unordered_set<std::string> c){courses = c;}

  void checkGrades(){
    std::map<std::string, std::string>::iterator it;
    for(it = grades.begin(); it != grades.end(); ++it){
      std::cout << it->first << ", " << it->second << std::endl;
      // this all assumes we want it written to stdout

    }
  }

 };

class Professor : public Person{
private:
  std::string employeeID; // again, assume alphanumeric
  std::string department; // replace with class once Department made
  std::unordered_set<std::string> coursesTaught; // replace w/ Course
  std::map<std::string, std::string> courseMaterials;
public:
  Professor(std::string id, std::string dept, std::unordered_set<std::string> c, std::string n, int a, std::string addr) : Person("unnamed", 0, "N/A"){
    employeeID = id;
    department = dept;
    coursesTaught = c;
    this->setName(n); // experimental
    this->setAge(a);
    this->setAddress(addr);
  }
  std::string getEmployeeID(){return employeeID;}
  std::string getDepartment(){return department;}
  std::unordered_set<std::string> getCoursesTaught(){return coursesTaught;}
  std::map<std::string, std::string> getCourseMaterials(){return courseMaterials;}
  
  void setEmployeeID(std::string id){employeeID = id;}
  void setDepartment(std::string d){department = d;}
  void setCoursesTaught(std::unordered_set<std::string> c){coursesTaught = c;}
  void setCourseMaterials(std::map<std::string, std::string> m){courseMaterials = m;}

  // does not append!!! maybe i'll add modes to this tho
  void updateCourseMaterials(std::string course, std::string material){ // set course type to course
    courseMaterials[course] = material;
  }

  int addGrade(Student student, std::string course, std::string grade) {
    if(coursesTaught.find(course) == coursesTaught.end()){
      std::cout << "ERROR: You do not teach this course, and cannot assign grades for it!" << std::endl;
      return 1;
    }

    std::map<std::string, std::string> temp = student.getGrades();
    temp[course] = grade;
    student.setGrades(temp); // tis clunky because i'm pretty sure you cant access grades directly bc private

    return 0;
  } 
  
};



TEST(PersonTest, Getters){
  Person test("John Doe", 21, "1 Main St.");
  EXPECT_EQ(test.getName(), "John Doe");
  EXPECT_EQ(test.getAge(), 21);
  EXPECT_EQ(test.getAddress(), "1 Main St.");
}

TEST(PersonTest, Setters){
   Person test("John Doe", 21, "1 Main St.");
   test.setName("Taro Yamada"); // japanese john doe equivalent!
   test.setAge(20);
   test.setAddress("N/A"); // residency program?
   EXPECT_EQ(test.getName(), "Taro Yamada");
   EXPECT_EQ(test.getAge(), 20);
   EXPECT_EQ(test.getAddress(), "N/A");
}

TEST(StudentTest, Getters){
  std::unordered_set<std::string> courses = {"Tests 101", "Intro to Stuffometry"};
  Student test("1A2B3C4D", "Testology", courses); // testing inputting unordered_set
  EXPECT_EQ(test.getStudentID(), "1A2B3C4D");
  EXPECT_EQ(test.getMajor(), "Testology");
  EXPECT_EQ(test.getCourses(), courses);
  // not sure how to write an unordered set like that
}

TEST(StudentTest, Setters){
  std::unordered_set<std::string> courses = {"Tests 101", "Intro to Stuffometry"};
  Student test("1A2B3C4D", "Testology", courses); // testing inputting unordered_set
  test.setStudentID("223EEEE");
  EXPECT_EQ(test.getStudentID(), "223EEEE");
  test.setMajor("Not Testology(tm)");
  EXPECT_EQ(test.getMajor(), "Not Testology(tm)");
  std::unordered_set<std::string> cours = {"Physics 201", "Calculus 101"};
  test.setCourses(cours);
  EXPECT_EQ(test.getCourses(), cours);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
