template<typename T, typename T_iterable>
vector<pair<T, int>> run_length_encoding(const T_iterable &items) {
    vector<pair<T, int>> encoding;
    T previous;
    int count = 0;
 
    for (const T &item : items)
        if (item == previous) {
            count++;
        } else {
            if (count > 0)
                encoding.emplace_back(previous, count);
 
            previous = item;
            count = 1;
        }
 
    if (count > 0)
        encoding.emplace_back(previous, count);
 
    return encoding;
}