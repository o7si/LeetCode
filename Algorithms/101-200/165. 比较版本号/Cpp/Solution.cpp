class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        vector<int> vec1 = stringToVector(version1);
        vector<int> vec2 = stringToVector(version2);
        
        while (vec1.size() < vec2.size())
            vec1.push_back(0);
        while (vec2.size() < vec1.size())
            vec2.push_back(0);

        if (vec1 > vec2)
            return 1;
        if (vec1 < vec2)
            return -1;
        return 0;
    }
private:
    vector<int> stringToVector(const string& version) {

        stringstream stream(version);
        string tmp;

        vector<int> result;
        while (getline(stream, tmp, '.'))
            result.push_back(stoi(tmp));
        return result;
    }
};
