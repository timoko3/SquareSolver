#include "nRoots.h"
#include "consoleColors.h"

#include <stdio.h>

typedef int nPassedTests;

struct testsData_t{
    equationData_t equationData;
    numRoots nRootsRef;
};

enum fileParseResult{
    PARSE_FAILURE = 0,
    PARSE_SUCCESS = 1
};

const char* const TESTS_OPEN_FILE_FAILURE_ALLERT = "Не удалось открыть файл с тестами.Тестирования не будет\n";
const char* const TEST_FAILURE_ALLERT = SET_STYLE_BLINKING_FONT_RED "Тест номер %d с кооэффицентами %lg, %lg, %lg провален!!!\n"
                                                                    "Корни должны быть %lg и %lg, a не %lg и %lg\n" RESET;

const char* const INF = "inf";
const char* const ZERO = "0";
const char* const ONE = "1";
const char* const TWO = "2";

nPassedTests RunTest(int* nAllTests);
