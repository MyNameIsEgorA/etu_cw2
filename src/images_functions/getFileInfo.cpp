#include "getFileInfo.h"

std::vector < std::vector < Pixel >> readBMP(const std::string & filename, BMPHeader & header, BMPInfoHeader & infoHeader) {
  std::ifstream file(filename, std::ios::binary);
  if (!file.is_open()) {
    throw std::runtime_error("Error opening file: no such file\n");
  }

  file.read(reinterpret_cast < char * > ( & header), sizeof(header));
  file.read(reinterpret_cast < char * > ( & infoHeader), sizeof(infoHeader));

  if (header.bitmapSignatureBytes != 0x4D42) { // 'BM'
    throw std::runtime_error("The file is not a bitmap image\n");
  }

  if (infoHeader.colorDepth != 24) {
    throw std::runtime_error("Unsupported color depth. Only 24-bit BMP files are supported.\n");
  }

  if (infoHeader.compressionMethos != 0) {
    throw std::runtime_error("Unsupported compression method. Only uncompressed BMP files are supported.\n");
  }

  int padding = (4 - (infoHeader.width * sizeof(Pixel)) % 4) % 4;

  std::vector < std::vector < Pixel >> pixels(abs(infoHeader.height), std::vector < Pixel > (infoHeader.width));

  file.seekg(header.pixelDataOffset, std::ios::beg);

  for (int i = 0; i < abs(infoHeader.height); i++) {
    for (int j = 0; j < infoHeader.width; j++) {
      Pixel pixel;
      file.read(reinterpret_cast < char * > ( & pixel), sizeof(pixel));
      pixels[i][j] = pixel;
    }
    file.seekg(padding, std::ios::cur);
  }

  file.close();
  return pixels;
}