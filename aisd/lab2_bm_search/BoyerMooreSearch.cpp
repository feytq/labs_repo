#include "BoyerMooreSearch.h"
#include <string>
#include <vector>

namespace {

    const int ALPHABET_SIZE = 256;

    std::vector<int> buildShiftTable(const std::string& pattern) {
        int length = static_cast<int>(pattern.length());

        std::vector<int> shiftTable(ALPHABET_SIZE, length);

        for (int i = 0; i < length - 1; i++) {
            int indexASCII = static_cast<unsigned char>(pattern[i]);
            shiftTable[indexASCII] = length - 1 - i;
        }

        return shiftTable;
    }

}

int findFirst(const std::string& text, const std::string& pattern) {
    int patternLength = static_cast<int>(pattern.length());
    int textLength = static_cast<int>(text.length());

    if (patternLength == 0 || textLength < patternLength) {
        return -1;
    }

    std::vector<int> shiftTable = buildShiftTable(pattern);
    int windowEnd = patternLength - 1;

    while (windowEnd < textLength) {
        int patternIndex = patternLength - 1;
        int textIndex = windowEnd;

        while (patternIndex >= 0 && text[textIndex] == pattern[patternIndex]) {
            textIndex--;
            patternIndex--;
        }

        if (patternIndex < 0) {
            return textIndex + 1;
        }

        unsigned char symbol = static_cast<unsigned char>(text[windowEnd]);
        windowEnd += shiftTable[symbol];
    }
    return -1;
}   