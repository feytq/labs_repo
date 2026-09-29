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

std::vector<int> findAll(const std::string& text, const std::string& pattern) {
    int patternLength = static_cast<int>(pattern.length());
    int textLength = static_cast<int>(text.length());

    std::vector<int> indexTable;

    if (patternLength == 0 || textLength < patternLength) {
        return indexTable;
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
            indexTable.push_back(windowEnd + 1 - patternLength);
        }

        unsigned char symbol = static_cast<unsigned char>(text[windowEnd]);
        windowEnd += shiftTable[symbol];
    }
    
    return indexTable;
}

std::vector<int> findAll(const std::string& text, const std::string& pattern, int startIndex, int endIndex) {
    int patternLength = static_cast<int>(pattern.length());
    int textLength = static_cast<int>(text.length());

    std::vector<int> indexTable;

    if (startIndex < 0) startIndex = 0;
    if (endIndex > textLength) endIndex = textLength;

    if (patternLength == 0 || (endIndex - startIndex) < patternLength) {
        return indexTable;
    }
    
    std::vector<int> shiftTable = buildShiftTable(pattern);

    int windowEnd = startIndex + patternLength - 1;
    
    while (windowEnd < endIndex) {
        int patternIndex = patternLength - 1;
        int textIndex = windowEnd;

        while (patternIndex >= 0 && text[textIndex] == pattern[patternIndex]) {
            textIndex--;
            patternIndex--;
        }

        if (patternIndex < 0) {
            indexTable.push_back(windowEnd + 1 - patternLength);
        }

        unsigned char symbol = static_cast<unsigned char>(text[windowEnd]);
        windowEnd += shiftTable[symbol];
    }
    
    return indexTable;
}
