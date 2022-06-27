#include <iostream>
#include "vector.hpp"
#include "Set.h"

int main() {
    setlocale(LC_ALL, "Russian");
    vector<String> v(String("Hello!"));
    v.push_back(String("������!"));
    v.push_back(String("������!"));
    v.push_back(String("������!"));
    v.push_back(String("������!"));
    v.push_back(String("������!"));
    std::cout<<"������ v: "<< v <<std::endl;
    v.push_back(String("������!"));
    v.push_back(String("������!"));
    v.push_back(String("������!"));
    std::cout<<"������ v: "<<v<<std::endl;
    vector v1=v;
    std::cout<<"������ v1: "<<v1<<std::endl;
    for(int i=0;i<5;i++)
        v1.pop(0);
    std::cout<<"������ v1: "<<v1<<std::endl;
    Set s("Yes"),s1,s2;
    s.push_back("������!");
    s.push_back("No");
    char* str="Hello!";
    s.push_back(str);
    std::cout<<"��������� s: "<<s<<std::endl;
    s1.push_back("Cat");
    s1.push_back("No");
    s1.push_back("������!");
    std::cout<<"��������� s1: "<<s1<<std::endl;
    s2=s1-s;
    std::cout<<"��������� s2=s1-s: "<<s2<<std::endl;
    std::cout<<"��������� s1: "<<s1<<std::endl;
    std::cout<<"��������� s: "<<s<<std::endl;
    s2=s-s1;
    std::cout<<"��������� s2=s-s1: "<<s2<<std::endl;
    std::cout<<"��������� s1: "<<s1<<std::endl;
    std::cout<<"��������� s: "<<s<<std::endl;
    s2=s1+s;
    std::cout<<"��������� s2=s1+s: "<<s2<<std::endl;
    std::cout<<"��������� s1: "<<s1<<std::endl;
    std::cout<<"��������� s: "<<s<<std::endl;
    s2=s1*s;
    std::cout<<"��������� s2=s1*s: "<<s2<<std::endl;
    std::cout<<"��������� s1: "<<s1<<std::endl;
    std::cout<<"��������� s: "<<s<<std::endl;
    Set s3=s2;
    std::cout<<"��������� s3=s2: "<<s3<<std::endl;
    if(s3==s2)
        std::cout<<"��������� s3=s2\n";
    else
        std::cout<<"��������� s3!=s2\n";
    if(s3==s1)
        std::cout<<"��������� s3=s1\n";
    else
        std::cout<<"��������� s3!=s1\n";
    if(s1==s3)
        std::cout<<"��������� s1=s3\n";
    else
        std::cout<<"��������� s1!=s3\n";
    return 0;
}
