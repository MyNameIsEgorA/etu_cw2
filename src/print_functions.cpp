#include "print_functions.h"

void printHelp() {
    std::cout << "Course work for option 5.2, created by Egor Anakhin\n\n"; // default info
    std::cout << "This program can help you transform your images\n\
Available flags:\n\n\
-info (use with --input) - prints info about an image \n\
-help (this param) - shows help info\n\n\
(for all commands below you must use --input and --output flags)\n\n\
--mirror (use with:\n\
    --axis - takes 'x' or 'y'\n\
    --left_up and --right_down - takes X.Y where x and y are coords by x and y)\n\n\
--copy (use with:\n\
    --left_up and --right_down\n\
    --dest_left_up - takes X.Y where x and y are coords where image will be copied)\n\n\
--color_replace (use with:\n\
    --old_color - takes rrr.ggg.bbb where rrr.ggg.bbb is color in RGB format\n\
    --new_color - same as --old_color)\n\n\
--split (use with:\n\
    --number_x - takes integer number. Used to set amount of columns\n\
    --number_y - same as --numbex_x but for rows\n\
    --thickness - takes integer number. Used to set thickness of split lines\n\
    --color - takes rrr.ggg.bbb color to set split line color)\n";
}

void printFileInfo(BMPInfoHeader infoHeader) {
    std::cout << "Информация о файле\n";
    std::cout << "Количество цветов на пиксель: " <<  infoHeader.colorDepth;
    std::cout << "\nРазмер заголовка: " << infoHeader.headerSize;
    std::cout << "\nШирина файла: " <<  infoHeader.width;
    std::cout << "\nВысота файла: " << infoHeader.height;
    std::cout << std::endl;
}