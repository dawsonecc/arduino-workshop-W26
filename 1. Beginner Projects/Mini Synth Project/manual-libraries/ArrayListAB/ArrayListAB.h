#ifndef ARRAYLISTAB_H
#define ARRAYLISTAB_H

template <typename T>
class ArrayListAB {

private:
    T data[32];
    int length = 0;

public:

    void add(T value) {
        if(length < 32){
            data[length++] = value;
        }
    }

    T operator[](int index) {
        return data[index];
    }

    int size() {
        return length;
    }

};

#endif