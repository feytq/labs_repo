#include "Segment.h"
#include <iostream>
#include <cmath>

Segment::Segment(const double x1, const double y1, const double x2, const double y2) 
    : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {
}

void Segment::input() {
    std::cin >> x1_ >> y1_ >> x2_ >> y2_;
}

void Segment::output() const {
    std::cout << "[(" << x1_ << "; " << y1_ << "), (" << x2_ << "; " << y2_ << ")]" << std::endl;
}

double Segment::getX1() const {
    return x1_;
}

double Segment::getY1() const {
    return y1_;
}

double Segment::getX2() const {
    return x2_;
}

double Segment::getY2() const {
    return y2_;
}

void Segment::setX1(const double x1) {
    x1_ = x1;
}

void Segment::setY1(const double y1) {
    y1_ = y1;
}

void Segment::setX2(const double x2) {
    x2_ = x2;
}

void Segment::setY2(const double y2) {
    y2_ = y2;
}

void Segment::computeMidpoint(double& x, double& y) const {
    x = (x1_ + x2_) / 2.0;
    y = (y1_ + y2_) / 2.0;
}

void Segment::computePartitionPoint(const double ratio, double& x, double& y) const {
    if (std::abs(ratio + 1.0) < 1e-9) {
        return;
    }
    x = (x1_ + ratio * x2_) / (1.0 + ratio);
    y = (y1_ + ratio * y2_) / (1.0 + ratio);
}

bool Segment::operator==(const Segment& other) const {
    const double len1 = std::hypot(x2_ - x1_, y2_ - y1_);
    const double len2 = std::hypot(other.x2_ - other.x1_, other.y2_ - other.y1_);

    return std::abs(len1 - len2) < 1e-9;
}

bool Segment::isParallelToY() const {
    return std::abs(x1_ - x2_) < 1e-9;
}

bool Segment::isPerpendicularTo(const Segment& other) const {
    const double dx1 = x2_ - x1_;
    const double dy1 = y2_ - y1_;
    const double dx2 = other.x2_ - other.x1_;
    const double dy2 = other.y2_ - other.y1_;

    const double dotProduct = dx1 * dx2 + dy1 * dy2;
    return std::abs(dotProduct) < 1e-9;
}

bool Segment::isIntersectingX() const {
    return (y1_ * y2_) <= 0.0;
}

bool Segment::isIntersectingLine(const double a, const double b, const double c) const{
    double f1 = a * x1_ + b * y1_ + c;
    double f2 = a * x2_ + b * y2_ + c;

    return (f1 * f2) <= 0.0;
}

bool Segment::isPointOnLine(const double x, const double y) const {
    const double crossProduct = (x - x1_) * (y2_ - y1_) - (x2_ - x1_) * (y - y1_);
    return std::abs(crossProduct) < 1e-9;
}