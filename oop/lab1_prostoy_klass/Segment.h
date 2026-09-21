#pragma once

class Segment {
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

        void setX1(const double x1);
        void setY1(const double y1);
    
        void setX2(const double x2);
        void setY2(const double y2);
        
        // Методы

        void computeMidpoint(double& x, double& y) const;
        void computePartitionPoint(const double ratio, double& x, double& y) const;
        bool operator==(const Segment& other) const;
        bool isParallelToY() const;
        bool isPerpendicularTo(const Segment& other) const;
        bool isIntersectingX() const;

        bool isIntersectingLine(const double a, const double b, const double c) const;
        bool isPointOnLine(const double x, const double y) const;

        bool computeRatio(const double x, const double y, double& ratio) const;
        Segment operator*(const double factor) const;

    private:

        double x1_ = 0.0, y1_ = 0.0;
        double x2_ = 0.0, y2_ = 0.0;
};