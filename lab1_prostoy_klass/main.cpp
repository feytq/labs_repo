#include <iostream>
#include "Segment.h"

int main() {
    Segment seg1(0.0, 0.0, 4.0, 4.0);
    Segment seg2(0.0, 4.0, 4.0, 0.0);
    Segment segVertical(3.0, -2.0, 3.0, 5.0);

    std::cout << "seg1: ";
    seg1.output();
    std::cout << "seg2: ";
    seg2.output();
    std::cout << "segVertical: ";
    segVertical.output();

    double midX = 0.0;
    double midY = 0.0;
    seg1.computeMidpoint(midX, midY); // x = 2, y = 2
    std::cout << "\nMidpoint seg1: (" << midX << "; " << midY << ")" << std::endl;

    double partX = 0.0;
    double partY = 0.0;
    seg1.computePartitionPoint(1.0, partX, partY); // x = 2, y = 2
    std::cout << "Partition 1:1 seg1: (" << partX << "; " << partY << ")" << std::endl;

    std::cout << "\nseg1 == seg2: " << (seg1 == seg2) << std::endl; // return 1 (true)

    std::cout << "segVertical isParallelToY: " << segVertical.isParallelToY() << std::endl; // return 1 (true)

    std::cout << "seg1 isPerpendicularTo seg2: " << seg1.isPerpendicularTo(seg2) << std::endl; // return 1 (true)

    std::cout << "segVertical isIntersectingX: " << segVertical.isIntersectingX() << std::endl; // return 1 (true)

    return 0;
}