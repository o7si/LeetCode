class Solution {
public:
    string simplifyPath(string path) {
        
        stringstream stream(path);
        string file;

        vector<string> c;
        while (getline(stream, file, '/')) {
            
            cout << file << endl;
            if (file == "." || file == "")
                continue;

            if (file == "..") {

                if (!c.empty())
                    c.pop_back();
                continue;
            }

            c.push_back(file);
        }

        if (c.empty())
            return "/";

        string result;
        for (int i = 0; i < c.size(); ++ i)
            result += "/" + c[i];
        return result;
    }
};
