#include "nRoots.h"

typedef int nPassedTests;

struct funcSolveQuadEquationTest{
    dataForSolvingTests forTest;
    const numRoots nRootsRef;
};



enum fileParseResult{
    PARSE_FAILURE,
    PARSE_SUCCESS
};

const int NUMBER_OF_TESTS = 2;
const char* const TESTING_FAILURE_PRINT = "Не удалось открыть файл с тестами.Тестирования не будет\n";

int RunTest();
nPassedTests OneTest(funcSolveQuadEquationTest all_tests);