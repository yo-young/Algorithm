#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, string> uidNamePair;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    // unordered_map<string, string> uidNamePair;
    unordered_map<string, unordered_map<string, string>> behaviourMap;
    
    for(auto& recordString : record) {
        string buffer;
        istringstream ss(recordString);
        int wordIndex=0;
        int bufIdx=0;
        string tmp="";
        while(getline(ss, buffer, ' ')) {
            cout << "idx :" << bufIdx << " " <<buffer << endl;
            bufIdx++;
            if(bufIdx == 1) {
                tmp = buffer;
            }
            if(buffer != "") {
                uidNamePair[tmp] = buffer;
            }
        }
    }
    
    
    return answer;
}

int main() {
    vector<string> answer;
    vector<string> record = {"Enter uid1234 Muzi",
                             "Enter uid4567 Prodo",
                              "Leave uid1234",
                              "Enter uid1234 Prodo",
                              "Change uid4567 Ryan"};

    answer = solution(record);
    string tmp = uidNamePair["uid1234"];
    cout << "answer : " << tmp << endl;;

    return 0;
}