#include <iostream>
#include "Solution.hpp"

struct testcase {
    vector<int> nums;
    int output;
};

class UnitTest {
private:
    vector<testcase> testcases;
    Solution obj;
public:
    UnitTest() {
        testcases = {{{10,4,-8,7}, 2}, 
                     {{2,3,1,0}, 2}};
    }

    void test() {
        for(int i = 0; i < testcases.size(); ++i) {
            int result = obj.waysToSplitArray(testcases[i].nums);
            cout << "TestCase " << i+1 << ": " << ((result == testcases[i].output)? "passed":"failed") << endl;
        }
    }
};

int main() {
    UnitTest test;
    test.test();
}