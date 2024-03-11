#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

class IntegerSet {
private:
    std::vector<bool> set;

public:
    IntegerSet() : set(101, false) {}

    IntegerSet(const std::array<int, 101>& arr) {
        for (int i = 0; i < 101; ++i) {
            set[i] = std::find(arr.begin(), arr.end(), i) != arr.end();
        }
    }

    IntegerSet unionOfSets(const IntegerSet& other) {
        IntegerSet result;
        for (int i = 0; i < 101; ++i) {
            result.set[i] = set[i] || other.set[i];
        }
        return result;
    }

    IntegerSet intersectionOfSets(const IntegerSet& other) {
        IntegerSet result;
        for (int i = 0; i < 101; ++i) {
            result.set[i] = set[i] && other.set[i];
        }
        return result;
    }

    void insertElement(int k) {
        if (k >= 0 && k <= 100) {
            set[k] = true;
        }
    }

    void deleteElement(int m) {
        if (m >= 0 && m <= 100) {
            set[m] = false;
        }
    }

    void printSet() {
        bool isEmpty = true;
        for (int i = 0; i < 101; ++i) {
            if (set[i]) {
                std::cout << i << " ";
                isEmpty = false;
            }
        }
        if (isEmpty) {
            std::cout << "---";
        }
        std::cout << std::endl;
    }

    bool isEqualTo(const IntegerSet& other) {
        return set == other.set;
    }
};

int main() {
    IntegerSet set1;
    set1.insertElement(10);
    set1.insertElement(30);

    IntegerSet set2;
    set2.insertElement(10);
    set2.insertElement(30);

    IntegerSet set3 = set1.unionOfSets(set2);
    IntegerSet set4 = set1.intersectionOfSets(set2);

    std::cout << "Set 1: ";
    set1.printSet();
    std::cout << "Set 2: ";
    set2.printSet();
    std::cout << "Union of Set 1 and Set 2: ";
    set3.printSet();
    std::cout << "Intersection of Set 1 and Set 2: ";
    set4.printSet();

    std::cout << "Is Set 1 equal to Set 2? ";
    if (set1.isEqualTo(set2)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    IntegerSet set5;
    set5.insertElement(40);
    set5.insertElement(50);
    set5.insertElement(60);

    std::cout << "Set 5: ";
    set5.printSet();

    return 0;
}