template<typename Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<typename ...Args>
    decltype(auto)

    operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<typename Fun> decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t < Fun>>(std::forward<Fun>(fun));
}