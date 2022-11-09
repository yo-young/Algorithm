#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    // while 반복문
    // 1부터 증가해서 it이 size-1과 같아지면 '0' 추가하고 감소시작
    // it이 0이 되면 종료
    int it=1;
    bool sign = true;
    while (it > 0) {
        int limit = food.size();
        if (it == limit) {
            answer += "0";
            --it;
            sign = false;
        }
        if (sign) {
            for(int i=0; i<food[it]/2; i++) {
                answer += to_string(it);
            }

            ++it;
        }
        if (!sign) {
            for(int i=0; i<food[it]/2; i++) {
                answer += to_string(it);
            }
            --it;
        }
    }
    return answer;
}

int main() {
    vector<int> food = {1, 3, 4, 6};
    string answer;

    answer = solution(food);
    cout << "answer : " << answer << endl;

    return 0;
}