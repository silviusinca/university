#include <iostream>
#include <string.h>

class Student {
private:
    char *name;
    int group;

public:
    Student(const char *name_, int group_) {
        size_t len = strlen(name_);
        name = new char[len];
        strcpy(name, name_);
        group = group_;
    }

    ~Student() {
        delete[] name;
    }

    const char *getName() const {
        return name;
    }

    void setName(const char *name_) {
        delete[] name;
        size_t len = strlen(name_);
        name = new char[len];
        strcpy(name, name_);
    }

    int getGroup() const {
        return group;
    }

    void setGroup(int group) {
        Student::group = group;
    }

    bool operator==(const Student &rhs) const {
        return strcmp(name, rhs.name) == 0 &&
               group == rhs.group;
    }

    bool operator!=(const Student &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << "Student: Name: " << student.name << " Group: " << student.group;
        return os;
    }
};

int main() {
    char buf[100];
    int group;

    std::cout << "Name: ";
    std::cin >> buf;
    Student s1(buf, 133);


    std::cout << s1;
}
