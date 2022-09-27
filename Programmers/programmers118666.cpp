#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int indexMBTI(string c) {
    int index;
    cout << c << endl;
    if(c[0] == 'R' || c[0] == 'T') return 0;
    if(c[0] == 'C' || c[0] == 'F') return 1;
    if(c[0] == 'J' || c[0] == 'M') return 2;
    if(c[0] == 'A' || c[0] == 'N') return 3;
}

int signCheck(string s, int c) {
    if(s[0] == 'R' || s[0] == 'C' || s[0] == 'J' || s[0] == 'A') {
        return 0;
    }
    else {
        return 1;
    }
}

// survey_len은 배열 survey의 길이입니다.
// choices_len은 배열 choices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
string solution(vector<string> survey, vector<int> choices) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    string answer = "";
    int answerInt[4][2] = {{0,0}, {0,0}, {0,0}, {0,0}};
    unordered_map<char,int> answerMap;

    
    for(int i=0; i<survey.size(); i++) {
        // cout << "choice : "<< choices[i] << ", signCheck : " << signCheck(choices[i]) << endl;
        string c = survey[i];
        if(choices[i] == 1) {            
            // cout << "char : " << c[signCheck(survey[i], choices[i])] << ", 3" << endl;
            // answerInt[indexMBTI(survey[i])][signCheck(survey[i])] += 3;
            answerMap[c[0]] += 3;
        }
        else if(choices[i] == 2) {
            // cout << "char : " << c[signCheck(survey[i], choices[i])] << ", 2" << endl;
            // answerInt[indexMBTI(survey[i])][signCheck(survey[i])] += 2;
            answerMap[c[0]] += 2;
        }
        else if(choices[i] == 3) {
            // cout << "char : " << c[signCheck(survey[i], choices[i])] << ", 1" << endl;
            // answerInt[indexMBTI(survey[i])][signCheck(survey[i])] += 1;
            answerMap[c[0]] += 1;
        }
        else if(choices[i] == 5) {
            // cout << "char : " << c[signCheck(survey[i], choices[i])] << ", 1" << endl;
            // answerInt[indexMBTI(survey[i])][signCheck(survey[i])] += 1;
            answerMap[c[1]] += 1;
        }
        else if(choices[i] == 6) {
            // cout << "char : " << c[signCheck(survey[i], choices[i])] << ", 2" << endl;
            // answerInt[indexMBTI(survey[i])][signCheck(survey[i])] += 2;
            answerMap[c[1]] += 2;
        }
        else if(choices[i] == 7) {            
            // cout << "char : " << c[signCheck(survey[i], choices[i])] << ", 3" << endl;
            // answerInt[indexMBTI(survey[i])][signCheck(survey[i])] += 3;
            answerMap[c[1]] += 3;
        }
        // std::cout << "index " << indexMBTI(survey[i]) << std::endl;
        // cout << "answerInt : " << answerInt[indexMBTI(survey[i])] << endl;
    }
    // cout << answerMap['R'] << " " << answerMap['T'] << endl;
    // cout << answerMap['C'] << " " << answerMap['F'] << endl;
    // cout << answerMap['J'] << " " << answerMap['M'] << endl;
    // cout << answerMap['A'] << " " << answerMap['N'] << endl;
    // answer += answerInt[0][0] > answerInt[0][1] ? 'R' : 'T';
    // answer += answerInt[1][0] > answerInt[1][1] ? 'C' : 'F';
    // answer += answerInt[2][0] > answerInt[2][1] ? 'J' : 'M';
    // answer += answerInt[3][0] > answerInt[3][1] ? 'A' : 'N';
    answer += answerMap['R'] >= answerMap['T'] ? 'R' : 'T';
    answer += answerMap['C'] >= answerMap['F'] ? 'C' : 'F';
    answer += answerMap['J'] >= answerMap['M'] ? 'J' : 'M';
    answer += answerMap['A'] >= answerMap['N'] ? 'A' : 'N';
    
    cout << "answer : " << answer << endl;
    return answer;
}


int main() {
    vector<string> survey = {"AN", "CF", "MJ", "RT", "NA"};
    vector<int> choices = {5, 3, 2, 7, 5};

    string answer;
    answer = solution(survey, choices);
    cout << "ans : " << answer << endl;

    return 0;
}