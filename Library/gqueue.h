template<typename T> struct gqueue {
private:
    std::array<std::stack<T>, 2> left, right;

    void push_(std::array<std::stack<T>, 2> &S, T x) {
        S[0].push(x);
        T gcd = S[1].empty() ? x : std::__gcd(x, S[1].top());
        S[1].push(gcd);
    }

    void pop_(std::array<std::stack<T>, 2> &S) {
        S[0].pop();
        S[1].pop();
    }

    void refill() {
        if (left[0].empty()) {
            while (!right[0].empty()) {
                push_(left, right[0].top());
                pop_(right);
            }
        }
    }

public:
    void push(T x) { push_(right, x); }

    void pop() {
        assert(!empty());
        refill();
        pop_(left);
    }

    bool empty() {
        return (left[0].empty() && right[0].empty());
    }

    T size() {
        return left[0].size() + right[0].size();
    }

    T front() {
        assert(!empty());
        refill();
        return left[0].top();
    }

    T gcd() {
        T a = left[0].empty() ? 0 : left[1].top();
        T b = right[0].empty() ? 0 : right[1].top();
        assert(!empty());
        return std::gcd(a, b);
    }
};