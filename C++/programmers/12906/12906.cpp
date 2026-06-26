#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for(int i = 0 ; i < arr.size() ; ++i) {
        if(answer.empty() || answer.back() != arr[i])
            answer.push_back(arr[i]);
    }

    return answer;
}

int main() {
    vector<int> arr = {1, 1, 3, 3, 0, 1, 1};
    vector<int> result = solution(arr);

    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}