#include <iostream>

class Uf
{
private:
    int size;
    int count;
    int* parent;

    int Find(int x) {
        if (x >= this->size || x < 0) {
            throw "Number must be greater than or equal to 0 and less than count";
            return -1;
        }
        return parent[x] == x ? x : parent[x] = Find(parent[x]);
    }

public:
    Uf(int size) {
        this->size = size;
        this->count = size;
        this->parent = new int[size];

        for (int i = 0; i < count; i++) {
            parent[i] = i;
        }
    }

    ~Uf() {
        delete[] this->parent;
    }

    Uf& Union(int first, int second) {
        try {
            parent[Find(first)] = parent[Find(second)];
            this->count -= 1;
            return *this;
        }
        catch (const char* msg) {
            std::cerr << msg << '\n';
            system("pause");
            exit(1);
        }
    }

    bool Connect(int first, int second) {
        try {
            return Find(first) == Find(second);
        }
        catch (const char* msg) {
            std::cerr << msg << '\n';
            system("pause");
            exit(1);
        }
    }

    int getCount() {
        return this->count;
    }
};