//
// Created by axelzucho on 19/11/18.
//

#ifndef PAGING_PAGER_H
#define PAGING_PAGER_H

#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>

using namespace std;

struct OrderBySecond
{
    bool operator() (const pair<char,int> &a, const pair<char,int> &b) { return a.second > b.second; }
};
typedef std::priority_queue<pair<char,int>, std::vector<pair<char,int>>, OrderBySecond> recently_used_queue;

class Pager {
private:
    int frame_number_;
    pair <int, string> min_path(const string& processes, int index, unordered_map<char, int> processes_in_frames, string steps){
        if(index >= processes.length()) return {0, steps};
        char process = processes[index];
        while(processes_in_frames.find(process) != processes_in_frames.end() && processes_in_frames[process] != -1){
            //cout << "Process " << process << " is already in frame " << processes_in_frames[process] << endl;
            if(++index >= processes.length()) return {0, steps};
            process = processes[index];
        }
        ++index;
        vector<pair<int, string>> results;
        for(auto it:processes_in_frames){
            if(it.second == -1) continue;
            char replaced_key = it.first;
            int replaced_frame = it.second;
            it.second = -1;
            processes_in_frames[process] = replaced_frame;

            results.push_back(min_path(processes, index, processes_in_frames, steps + replaced_key));
            it.second = replaced_frame;
        }
        pair<int, string> page_faults = {INT32_MAX, ""};
        for(auto const& it:results){
            page_faults = page_faults.first > it.first ? it : page_faults;
        }
        return {page_faults.first + 1, page_faults.second};
    }
    void print_optimal_steps(const string& processes, const string& steps){
        unordered_map<char, int> processes_in_frames;
        int occupied_frames = 0;
        int current_index = 0;
        for(auto it:processes){
            if(processes_in_frames.find(it) != processes_in_frames.end() && processes_in_frames[it] != -1){
                cout << "Process " << it << " is already in frame " << processes_in_frames[it] << endl;
                continue;
            }
            else if(occupied_frames < frame_number_){
                processes_in_frames.insert({it, ++occupied_frames});
                cout << "Process " << it << " enters frame " << occupied_frames << endl;
                continue;
            }
            else {
                cout << "Page fault for process " << it << endl;
                char replacing_process = steps[current_index++];
                cout << "Process " << replacing_process << " exits" << endl;
                processes_in_frames[it] = processes_in_frames[replacing_process];
                processes_in_frames[replacing_process] = -1;
                cout << "Process " << it << " enters frame " << processes_in_frames[it] << endl;
            }
        }
    }
public:
    explicit Pager(const int frame_number):frame_number_(frame_number){}

    int fifo(const string& file_path){
        unordered_map<char, int> processes_in_frames;
        int frame_number_track = 0;
        int page_faults = 0;
        queue<char> frames;
        ifstream file(file_path);

        if(!file.is_open()){
            cout << "File can't be opened!" << endl;
            return 0;
        }

        char process;

        while(file >> process){
            if(process > 'Z' || process < 'A') continue;
            if(processes_in_frames.find(process) != processes_in_frames.end() && processes_in_frames[process] != -1){
                cout << "Process " << process << " is already in frame " << processes_in_frames[process] << endl;
                continue;
            }
            else if(frames.size() < frame_number_){
                frames.push(process);
                processes_in_frames.insert({process, ++frame_number_track});
                cout << "Process " << process << " enters frame " << frame_number_track << endl;
                continue;
            }
            else {
                ++page_faults;
                cout << "Page fault for process " << process << endl;
                char process_replaced = frames.front();
                frames.pop();
                cout << "Process " << process_replaced << " exits" << endl;
                processes_in_frames[process] = processes_in_frames[process_replaced];
                processes_in_frames[process_replaced] = -1;
                frames.push(process);
                cout << "Process " << process << " enters frame " << processes_in_frames[process] << endl;
            }

        }
        return page_faults;
    }

    int lru(const string& file_path){
        //The first value contains the process, the pair is composed of the frame and the last time it was used
        unordered_map<char, pair<int, int>> processes_in_frames;
        int frame_number_track = 0;
        int time = 0;
        int page_faults = 0;
        recently_used_queue frames;
        ifstream file(file_path);

        if(!file.is_open()){
            cout << "File can't be opened!" << endl;
            return 0;
        }

        char process;

        while(file >> process){
            if(process > 'Z' || process < 'A') continue;
            if(processes_in_frames.find(process) != processes_in_frames.end() && processes_in_frames[process].first != -1){
                cout << "Process " << process << " is already in frame " << processes_in_frames[process].first << endl;
                frames.push({process, ++time});
                processes_in_frames[process].second = time;
                continue;
            }
            else if(frames.size() < frame_number_){
                frames.push({process, ++time});
                processes_in_frames.insert({process, {++frame_number_track, time}});
                cout << "Process " << process << " enters frame " << frame_number_track << endl;
                continue;
            }
            else {
                ++page_faults;
                cout << "Page fault for process " << process << endl;
                pair<char,int> process_replaced = frames.top();
                while (processes_in_frames[process_replaced.first].second != process_replaced.second){
                    frames.pop();
                    process_replaced = frames.top();
                }
                frames.pop();
                cout << "Process " << process_replaced.first << " exits" << endl;
                frames.push({process, ++time});
                processes_in_frames[process] = {processes_in_frames[process_replaced.first].first, time};
                processes_in_frames[process_replaced.first] = {-1, 0};
                cout << "Process " << process << " enters frame " << processes_in_frames[process].first << endl;
            }

        }
        return page_faults;
    }

    int optimal(const string& file_path){
        ifstream file(file_path);
        if(!file.is_open()){
            cout << "File can't be opened!" << endl;
            return 0;
        }
        char process;
        string all_processes;
        while(file >> process) {
            if(process > 'Z' || process < 'A') continue;
            all_processes += process;
        }

        int occupied_frames = 0;
        int current_frame = 0;
        unordered_map<char,int> processes_in_frames;

        while(current_frame < all_processes.length()){
            process = all_processes[current_frame++];
            if(processes_in_frames.find(process) != processes_in_frames.end()){
                //cout << "Process " << process << " is already in frame " << processes_in_frames[process] << endl;
                continue;
            }
            else if (occupied_frames < frame_number_){
                processes_in_frames[process] = ++occupied_frames;
                //cout << "Process " << process << " enters frame " << occupied_frames << endl;
            }
            else break;
        }
        pair<int, string> result;
        result = min_path(all_processes, --current_frame, processes_in_frames, "");
        print_optimal_steps(all_processes, result.second);
        return result.first;
    }

};


#endif //PAGING_PAGER_H
