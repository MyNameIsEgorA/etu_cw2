#include "process_flags.h"


void processArguments(int& argc, char**& argv) {
    // Проверяем, есть ли флаг --input
    bool hasInputFlag = false;
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--input") {
            hasInputFlag = true;
            break;
        }
    }

    // Если флаг --input отсутствует, расширяем массив и добавляем его
    if (!hasInputFlag) {
        // Создаем новый динамический массив для хранения аргументов
        std::vector<char*> newArgv(argc + 2, nullptr); // +2 для флага --input и значения

        // Копируем старые аргументы в новый массив
        for (int i = 0; i < argc; ++i) {
            newArgv[i] = argv[i];
        }

        // Добавляем новый флаг --input и его значение в предпоследнее место
        newArgv[argc - 1] = const_cast<char*>("--input");
        newArgv[argc] = argv[argc - 1]; // Предполагается, что последний аргумент - имя файла

        // Освобождаем память, выделенную для старого argv
        delete[] argv;

        // Обновляем argc и argv
        argc += 1; // Увеличиваем argc на 1, так как добавили еще один аргумент
        argv = new char*[argc];
        for (int i = 0; i < argc; ++i) {
            argv[i] = newArgv[i];
        }

        // Освобождаем память, выделенную для нового argv, если он был расширен
        if (argc > newArgv.size()) {
            for (int i = newArgv.size(); i < argc; ++i) {
                delete[] argv[i];
            }
        }
    }
}