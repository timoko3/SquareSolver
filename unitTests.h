#include "nRoots.h"

const int N_OF_TESTS = 3;

typedef int nPassedTests;

struct testsData_t{
    equationData_t equationData;
    numRoots nRootsRef;
};

enum fileParseResult{
    PARSE_FAILURE,
    PARSE_SUCCESS
};

const char* const TESTS_OPEN_FILE_FAILURE_ALLERT = "Не удалось открыть файл с тестами.Тестирования не будет\n";
const char* const TEST_FAILURE_ALLERT = "Тест номер %d провален\n";

bool parseTestsFromFile(testsData_t* testsData);
nPassedTests RunTest();
nPassedTests OneTest(testsData_t all_tests);