vector<string> split(string text, char delim) {
    vector<string> res;

    string temp;

    for(char &c: text){
        if (c == delim){
            res.push_back(temp);
            temp = "";        
        } else {
            temp += c;
        }
    }

    if (temp.length() > 0) 
        res.push_back(temp);

    return res;
}

