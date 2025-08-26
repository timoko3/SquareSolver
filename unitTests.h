#include "nRoots.h"
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
const char* const TEST_FAILURE_ALLERT = "Тест номер %d кооэффиценты %lg, %lg, %lg провален корни должны быть %lg, %lg, a не %lg, %lg\n";

const char* const INF = "inf";
const char* const ZERO = "0";
const char* const ONE = "1";
const char* const TWO = "2";

nPassedTests RunTest(int* nAllTests);
bool parseTestsFromFile(FILE* fileWithTests, testsData_t* curTest, int* nAllTests);
bool openFile(FILE** filewithTests);
bool getTestToFile(FILE* fileWithTests, testsData_t* curTest);
void createReferenceTest(equationData_t* reference, testsData_t* curTest);
bool isUnpassed(testsData_t* curTest, equationData_t* reference, numRoots nRoots, int nTest);
nPassedTests OneTest(testsData_t all_tests);
