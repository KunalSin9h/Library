std::istream& operator>>(std::istream &input, __int128_t &val){
    std::string str_input;
    input >> str_input;
    val = 0;
    int str_size = str_input.size();
    bool neg = str_input[0] == '-';
    for(int i = (neg ? 1 : 0); i < str_size; ++i){
        val = val*10 + (str_input[i] - 48);
    }
    neg ? val *= -1: val;
    return input;
}

std::ostream& operator<<(std::ostream &output, __int128_t &val){
    if(val == 0)return output << 0;
    std::string str_output;
    bool neg = false;
    if(val < 0){
        val *= -1;
        neg = true;
    }
    while(val){
        str_output.push_back(char(val%10 + 48));
        val /= 10;
    }
    if(neg)str_output.push_back('-');
    reverse(str_output.begin(), str_output.end());
    return output << str_output;
}

typedef __int128_t int128_t;
