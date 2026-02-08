#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<bool> visited;

void Log(const vector<string>& log_answer)
{
    for (const auto& element : log_answer)
    {
        cout << "\"" << element << "\"" << " ";
    }
    cout << "\n";
    
}

string find_match(const string& start, const vector<vector<string>>& tickets)
{
    string next_candidate;
    int idx=0;
    for (int i=0; i<tickets.size(); i++)
    {
        if (tickets[i][0]==start && !visited[i])
        {
            if(next_candidate=="") 
            {
                next_candidate=tickets[i][1];
                idx=i;
            }
            else if(tickets[i][1]<next_candidate) 
            {
                next_candidate=tickets[i][1];
                idx=i;
            }
        }        
    }
    visited[idx]=true;
    return next_candidate;
}

vector<string> solution(vector<vector<string>> tickets) {
    // 초기화
    vector<string> answer; answer.clear();
    visited.resize(tickets.size(), false);

    string next_destination;
    for (int i=0; i<tickets.size(); i++)
    {
        if (answer.size()==0) 
        {
            answer.push_back("ICN");
            next_destination=find_match("ICN", tickets);
            answer.push_back(next_destination);
        }
        else
        {
            next_destination=find_match(next_destination, tickets);
            answer.push_back(next_destination);
        }
    }

    return answer;
}



int main ()
{
    vector<vector<string>> tickets;
    vector<string> log_answer;

    //tickets={{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    tickets={{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
    log_answer=solution(tickets);
    Log(log_answer);
}