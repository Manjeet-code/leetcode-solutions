class Solution {
public:
bool fun(unordered_map<char,int>have,unordered_map<char,int>need){
    for(auto i : need){
    char c = i.first;
    int fneed = i.second;
    int fhave = have[c];
    if(fneed>fhave) return false;
    }
    return true;
    
}
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>have;
        unordered_map<char,int>need;
        for(int i=0;i<magazine.size();i++){
            have[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            need[ransomNote[i]]++;
        }
        return fun(have,need);
    }
};