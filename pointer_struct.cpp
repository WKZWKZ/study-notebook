
#include <iostream>
#include <cstring>
struct Student
{
    char name[4];
    int born;
    bool male;
};

int main()
{
    Student stu = {"Yu", 2000, true};
    Student *pStu = &stu;

    std::cout << stu.name << "was born in " << stu.born
              << " Gender: " << (stu.male ? "male" : "female")
              << std::endl;

    strncpy(pStu->name, "Li", 4);
    pStu->born = 2001;
    pStu->male = false;

    std::cout << pStu->name << "was born in " << pStu->born
              << " Gender: " << (pStu->male ? "male" : "female")
              << std::endl;

    printf("Address of stu: %p\n", pStu);
    std::cout << "Address of stu: " << pStu << std::endl;
    std::cout << "Address of stu: " << &stu << std::endl;
    std::cout << "Address of member name: " << &(pStu->name) << std::endl;
    std::cout << "Address of member born: " << &(pStu->born) << std::endl;
    std::cout << "Address of member male: " << &(pStu->male) << std::endl;

    std::cout << "sizeof(pStu): " << sizeof(pStu) << std::endl;

    return 0;
}