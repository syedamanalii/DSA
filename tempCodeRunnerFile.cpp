#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    void solve(string digits, int index, string output, string mapping[], vector<string>& ans){
        //base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        //processing
        int number = digits[index] - '0';
        string value = mapping[number];

        //Recursive Call
        for(int i =0; i< value.length(); i++){
            output.push_back(value[i]);
            solve(digits, index + 1, output, mapping, ans);
            output.pop_back();
        }
    }
    public:
    vector<string> letterCombination(string digits){
        vector<string> ans;   //vector to store the final combination
        if(digits.length() == 0){
            return ans;
        }
        string output = "";   //empty string initiated to build combination
        int index = 0;        
        string mapping[10] = {"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, index, output,mapping, ans);
        return ans;
    }
};

int main(){
    Solution sol;
    string digits = "23";
     vector <string> result = sol.letterCombination(digits);

     for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
     }
}