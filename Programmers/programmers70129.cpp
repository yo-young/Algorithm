#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int cntZero(string &s) {
    int cnt = 0;
    for(int i=0; i<s.length(); i++) {
        if(s.find("0") == -1){
			return 0;
		}else if(s.find("0",i)<=i){
			cnt+= 1;
		}
    }
    return cnt;
}

string toBinary(int s) {
    string bin = "";
    while(s != 0) {
        bin += (to_string(s%2));
        s /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

bool condForWhile(string s)
{
    if(s.length() == 1 && stoi(s) == 1) {
        return false;
    }
    else
        return true;
}

vector<int> solution(string s) {
    vector<int> answer;
    string tempStr = s;
    
    int zeroNum = 0;
    int cntConvert = 0;
    while(condForWhile(tempStr)) {
        //변환 수 증가
        cntConvert += 1;
        //제거한 0 개수 누적
        zeroNum += cntZero(tempStr);
        //0 제거
        tempStr.erase(remove(tempStr.begin(), tempStr.end(), '0'), tempStr.end());
        //2진수로 변환
        tempStr = toBinary(tempStr.length());
    }
    answer.push_back(cntConvert);
    answer.push_back(zeroNum);
    
    return answer;
}

int main() {
    string s = "110010101001";
    vector<int> answer;

    answer = solution(s);

    cout << answer[0] << ", " << answer[1] << endl;


    return 0;
}