class Rectangle {
    private:
        double width;
        double length;

    public:
        Rectangle(double w, double l): width(w), length(l) {}

        void setLength(double a) {
            if(a >= 0){
                length = a;
            }
        }

        void setWidth(double a) {
            if(a >= 0){
                width = a;
            }
        }

        double getLength () {
            return length;
        }

        double getWidth() {
            return width;
        }

        double getArea() {
            return length * width;
        }

        double getPerimeter() {
            return 2 * length + 2 * width;
        }
};