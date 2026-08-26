#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

pair<string,int> parsing(string file) {
    int start = 0;
    while(start < file.size() && !isdigit(file[start])) ++start;
    int end = start;
    while(end < file.size() && isdigit(file[end]) && end < start + 5) ++end;
    string head = file.substr(0, start);
    int number = stoi(file.substr(start, end-start));
    return {head, number};
}

bool cmp(string a, string b) {
    auto [headA, numA] = parsing(a);
    auto [headB, numB] = parsing(b);
    
    for(char& c : headA) c = tolower(c);
    for(char& c : headB) c = tolower(c);
    
    if(headA != headB) return headA < headB;
    if(numA != numB) return numA < numB;
    return false;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}