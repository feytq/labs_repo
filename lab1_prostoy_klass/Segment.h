#pragma once

class Segment{
    public:
        // Конструкторы

        Segment() = default;
        Segment(const double x1, const double y1, const double x2, const double y2);

        // Ввод и вывод
        
        void input();
        void output() const;

        // Геттеры и сеттеры

        double getX1() const;
        double getY1() const;

        double getX2() const;
        double getY2() const;

        void setX1(const double x);
        void setY1(const double y);
    
        void setX2(const double x);
        void setY2(const double y);
        
        // Методы (основные)

        void midpoint(double& x, double& y) const;
        void partition(const double ratio, double& x, double& y) const;

        bool operator==(const Segment& other) const;
        bool parallel_y() const;
        bool perpendicular(const Segment& other) const;
        bool intersection_x() const;

    private:

        double x1_ = 0.0, y1_ = 0.0;
        double x2_ = 0.0, y2_ = 0.0;
};