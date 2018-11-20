#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>

#include "Pager.h"

using namespace std;

int main() {
    int frame_number;
    cout << "Please enter frame number" << std::endl;
    cin >> frame_number;
    Pager pager(frame_number);

    char option;
    cin >> option;

    string file_path;
    cin >> file_path;

    int faults = pager.fifo(file_path);
    cout << "The page fault amount for fifo is " << faults << endl;

    int faults2 = pager.lru(file_path);
    cout << "The page fault amount for lru is " << faults2 << endl;

    int faults3 = pager.optimal(file_path);
    cout << "The page fault amount for optimal is " << faults3 << endl;

    return 0;
}