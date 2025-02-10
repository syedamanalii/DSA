#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    void solve(string digit, int index, string output, vector<string>& ans, string mapping[]){
        //base case
            if(index>=digit.length()){
                ans.push_back(output);   //taking final data from output and store it in ans
                return;
        }
        //Processing
        int number = digit[index] - '0';    //converting the current character to its integer value
        string value = mapping[number];     //get the corresponding string 
        //Recursion Call
        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digit, index+1, output, ans, mapping);
            output.pop_back();
        }

    }
    public:
    vector <string> letterCombination(string digits){
        vector <string> ans;     //created to store the final letter combination
        if(digits.length()==0){
            return ans;
        }
        string output = "";    //empty string initiated to build combination
        int index = 0;         
        string mapping[10] = {"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, index, output, ans, mapping);
        return ans;
    }


};
int main(){
    Solution sol;
    string digits = "23";
    vector <string> result = sol.letterCombination(digits);

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    
return 0;
}