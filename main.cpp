#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct comp{
    bool operator()(const string& a, const string& b){
        if(a.length() > b.length()) return true;
        else if(a.length() < b.length()) return false;
        else return a > b;
    }
};

class SolutionEighteen{
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        comp Comp;
        priority_queue<string,vector<string>,comp> heap;
        for(int i=0; i<k; i++){
            heap.push(nums[i]);
        }
        for(int i=k; i<nums.size(); i++){
            if(Comp(nums[i],heap.top())){
                heap.push(nums[i]);
                heap.pop();
            }
        }
        return heap.top();
    }
};

int main(){
    return 0;
}