cmake_minimum_required(VERSION 3.2)

project(cw_2)

add_executable(
    cw
    src/consts.h
    src/main.cpp
    src/print_functions.cpp
    src/input_functions/check_args_amount.cpp
    src/input_functions/validate_args.cpp
    src/images_functions/imageStructs.h
    src/images_functions/color_replace.cpp
    src/images_functions/getFileInfo.cpp
    src/images_functions/new_file.cpp
    src/images_functions/copy_part.cpp
    src/images_functions/mirror.cpp
    src/images_functions/split.cpp
    src/images_functions/parsing_functions.cpp
)