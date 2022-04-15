#include <iostream>
#include <vector>

template<typename T, typename Q>
class MyMap {
private:
    std::vector<std::pair<T, Q>> items;
public:
    explicit MyMap() {}

    Q& operator[](T index) {

    }
};

int main() {
    MyMap<std::string, int> catalog;
    catalog["Ion"] = 10;
//    std::cout << catalog["Ion"];

    return 0;
}
