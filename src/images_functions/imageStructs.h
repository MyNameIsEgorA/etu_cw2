#include <iostream>

#pragma once
#pragma pack(push, 1)

struct BMPHeader {
    uint16_t bitmapSignatureBytes;
    uint32_t sizeOfBitmapFile;
    uint32_t reservedBytes;
    uint32_t pixelDataOffset;
};

struct BMPInfoHeader {
    uint32_t headerSize;
    int32_t width;
    int32_t height;
    uint16_t numberOfColorPlanes;
    uint16_t colorDepth;
    uint32_t compressionMethos;
    uint32_t imageSize;
    int32_t horizontalResolution;
    int32_t verticalResolution;
    uint32_t colorTableEntries;
    uint32_t importantColors;
};

struct Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

#pragma pack(pop)