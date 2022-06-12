template <typename T> int sgn(T x) { return (x > 0) - (x < 0); }
template<typename T> struct Point{
    T x, y;
    Point(T _x = 0, T _y = 0) : x{_x}, y{_y}{} 
    template <typename U> explicit Point(const Point<U>& p) : x(p.x), y(p.y) {} 
    Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}
    Point(const std::complex<T>& p) : x(real(p)), y(imag(p)) {}
    explicit operator std::pair<T, T> () const { return std::pair<T, T>(x, y); }
    explicit operator std::complex<T> () const { return std::complex<T>(x, y); }

    friend std::ostream& operator << (std::ostream& o, const Point& p) { return o << '(' << p.x << ',' << p.y << ')'; }
    friend std::istream& operator >> (std::istream& i, Point& p) { return i >> p.x >> p.y; }
    friend bool operator == (const Point& a, const Point& b) { return a.x == b.x && a.y == b.y;}
    friend bool operator != (const Point& a, const Point& b) { return a.x != b.x || a.y != b.y;}

    Point operator+() const { return Point(+x, +y);}
    Point operator-() const { return Point(-x, -y);}

    Point& operator+=(const Point& p) { x += p.x, y += p.y; return *this;}
    Point& operator-=(const Point& p) { x -= p.x, y -= p.y; return *this;}
    Point& operator*=(const T& t) { x *= t, y *= t; return *this;}
    Point& operator/=(const T& t) { x /= t, y /= t; return *this;}

    friend Point operator+(const Point& a, const Point& b) { return Point(a.x+b.x, a.y+b.y);}
    friend Point operator-(const Point& a, const Point& b) { return Point(a.x-b.x, a.y-b.y);}
    friend Point operator*(const Point& a, const T& t) { return Point(a.x*t, a.y*t);}
    friend Point operator*(const T& t ,const Point& a) { return Point(t*a.x, t*a.y);}
    friend Point operator/(const Point& a, const T& t) { return Point(a.x/t, a.y/t);}

    // returns point rota    template <typename U> explicit Point(const Point<U>& p) : x(p.x), y(p.y) {}    template <typename U> explicit Point(const Point<U>& p) : x(p.x), y(p.y) {}ted ’a ’ radians ccw around the origin
    Point rotate(double a)const{
        return Point(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a));
    };

    Point perp_cw() const { return Point(y, -x);} // clock-wise
    Point perp_ccw() const { return Point(-y, x);}// anti

    T dist2()const{return x*x + y*y;};
    auto dist()const{return sqrt(dist2());};
    Point unit() const { return *this / this->dist();}
    auto angle() const { return atan2(y, x);}

    friend T dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y;}
    friend T cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x;}
    friend T cross3(const Point& a, const Point& b, const Point& c) { return cross(b-a, c-a);}
};
