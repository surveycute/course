#include <iostream>

template <typename T>
class ObjectCounter {
private:
    static size_t counter;
protected:
    ObjectCounter() {
        ++ObjectCounter<T>::counter;
    }
    ObjectCounter(const ObjectCounter&) {
        ++ObjectCounter<T>::counter;
    }
    ~ObjectCounter() {
        --ObjectCounter<T>::counter;
    }
public:
    static size_t getCounter() {
        return ObjectCounter<T>::counter;
    }
};

template <typename T>
size_t ObjectCounter<T>::counter = 0;

class C: public ObjectCounter<C> {
};

class D: public ObjectCounter<D> {
};


int main () {
    C c;
    D d;
    std::cout << C::getCounter() << "\n";
    std::cout << D::getCounter() << "\n";
    {
        D d2 = d;
        std::cout << D::getCounter() << "\n";
    }
    std::cout << D::getCounter() << "\n";
}
