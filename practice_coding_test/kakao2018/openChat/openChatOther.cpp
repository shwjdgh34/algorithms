#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

struct log
{
    string name;
    string io;
};

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<struct log> log_arr;
    map<string, string> id_match;

    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string buf;
        vector<string> tokens;
        while (ss >> buf)
            tokens.push_back(buf);
        if (tokens[0] == "Enter")
        {
            struct log temp;
            temp.name = tokens[1];
            temp.io = tokens[0];
            log_arr.push_back(temp);
            id_match[tokens[1]] = tokens[2];
        }
        else if (tokens[0] == "Leave")
        {
            struct log temp;
            temp.name = tokens[1];
            temp.io = tokens[0];
            log_arr.push_back(temp);
        }
        else
        {
            id_match[tokens[1]] = tokens[2];
        }
    }
    for (int i = 0; i < log_arr.size(); i++)
    {
        if (log_arr[i].io == "Enter")
        {
            string text = id_match[log_arr[i].name] + "님이 들어왔습니다.";
            answer.push_back(text);
        }
        else
        {
            string text = id_match[log_arr[i].name] + "님이 나갔습니다.";
            answer.push_back(text);
        }
    }
    return answer;
}
int main()
{
    vector<string> answer;
    vector<string> record{"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};
    answer = solution(record);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    return 0;
}