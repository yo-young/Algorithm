#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int answer;
    //hash map<이름, 카운트>
    unordered_map<string, int> hash;
    for(string name:participant) {
        hash[name] += 1;
    }
    for(string name:completion) {
        hash[name] -= 1;
        if(hash[name] < 0) {
            return name;
        }
    }
}

int main() {
    vector<string> participant = {"leo", "kiki", "eden" };
    vector<string> completion = { "eden", "kiki" };

    //printf("%c", words[1][0]);

    int a = solution(participant, completion);

    printf("answer = %d\n", a);

    return 0;
}