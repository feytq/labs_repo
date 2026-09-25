#include <iostream>
#include "Segment.h"

int main() {
    Segment seg1(0.0, 0.0, 4.0, 4.0);
    Segment seg2(0.0, 4.0, 4.0, 0.0);
    Segment segVertical(3.0, -2.0, 3.0, 5.0);
    Segment inputSeg;

    std::cout << "Enter a segment inputSeg (x1 y1 x2 y2): ";
    inputSeg.input(); // example input: 1.0 1.0 5.0 5.0

    std::cout << "seg1: ";
    seg1.output();
    std::cout << "seg2: ";
    seg2.output();
    std::cout << "segVertical: ";
    segVertical.output();
    std::cout << "inputSeg: ";
    inputSeg.output();

    double midX = 0.0;
    double midY = 0.0;
    seg1.computeMidpoint(midX, midY); // x = 2, y = 2
    std::cout << "\nMidpoint seg1: (" << midX << "; " << midY << ")" << std::endl;

    double partX = 0.0;
    double partY = 0.0;
    const double targetRatio = 2.0 / 3.0;
    seg1.computePartitionPoint(targetRatio, partX, partY);
    std::cout << "Partition 2:3 seg1: (" << partX << "; " << partY << ")" << std::endl;

    std::cout << "\nseg1 == seg2: " << (seg1 == seg2) << std::endl; // return 1 (true)

    std::cout << "segVertical isParallelToY: " << segVertical.isParallelToY() << std::endl; // return 1 (true)

    std::cout << "seg1 isPerpendicularTo seg2: " << seg1.isPerpendicularTo(seg2) << std::endl; // return 1 (true)

    std::cout << "segVertical isIntersectingX: " << segVertical.isIntersectingX() << std::endl; // return 1 (true)

    std::cout << "\nseg1 isIntersectingLine: " << seg1.isIntersectingLine(0.0, 1.0, -2.0) << std::endl; // return 1 (true)

    std::cout << "seg1 isPointOnLine: " << seg1.isPointOnLine(partX, partY) << std::endl; // return 1 (true)

    double restoredRatio = 0.0;
    if (seg1.computeRatio(partX, partY, restoredRatio)) {
        std::cout << "\nseg1 computeRatio (for the found point): " << restoredRatio << " (2/3)" << std::endl;
    }

    Segment segScaled = seg1 * 2.0;
    std::cout << "seg1 * 2.0: ";
    segScaled.output(); // [(0; 0), (8; 8)]

    Segment segScaled1 =  4.0 * seg1;
    std::cout << "4.0 * seg1: ";
    segScaled1.output(); // [(0; 0), (16; 16)]

    return 0;
}