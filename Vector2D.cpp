
#include<iterator>
#include<vector>
using namespace std;

class Vector2D {
    
public:

    vector<vector<int>>::iterator row {};
    vector<int>::iterator column{};

    vector<vector<int>>::iterator begin {};
    vector<vector<int>>::iterator end {};

    Vector2D(vector<vector<int>>&vec) {

        begin = vec.begin();
        end = vec.end();

        row = begin;
        column = (row != end) ? (row->begin()) : column;
    }

    int next() {
        if (!hasNext()) {
            throw out_of_range("row = " + distance(begin, row) + " is out of bounds!");
        }
        return *column++;
    }

    bool hasNext() {
        if (row < end) {
            moveForward();
        }
        return row != end;
    }

    void moveForward() {
        while (row != end && column == row->end()) {
            row++;
            column = (row != end) ? (row->begin()) : column;
        }
    }
};
