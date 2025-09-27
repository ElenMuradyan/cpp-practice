class Circle{
    private:
        double radius;
        const double pi = 3.14159265358979323846;
    public:
        Circle(double radius): radius(radius) {}

        double getArea() const {
            return pi * radius * radius;
        }
};