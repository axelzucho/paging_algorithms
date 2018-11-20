#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>

#include "Pager.h"

using namespace std;

int main() {
    int frame_number;
    cout << "Frame Number: ";
    cin >> frame_number;
    Pager pager(frame_number);

    cout << "Reference Sequence: ";
    string file_path;
    cin >> file_path;

    cout << "Algorithm to use. Options are A. FIFO, B. LRU, C. Optimal: ";
    char option;
    cin >> option;

    int faults;

    switch (option){
        case 'a':
        case 'A':
            faults = pager.fifo(file_path);
            break;
        case 'b':
        case 'B':
            faults = pager.lru(file_path);
            break;
        case 'c':
        case 'C':
            faults = pager.optimal(file_path);
            break;
        default:
            cout << "Option not recognized" << endl;
            return 0;

    }

    cout << "The page fault amount is " << faults << endl;

    return 0;
}