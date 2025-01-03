from timeout_decorator import timeout
from Solution import Solution
import unittest

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testcases = {1: ([10,4,-8,7], 2), 2: ([2,3,1,0], 2)}
        self.__obj = Solution()
        return super().setUp()
    
    @timeout(0.5)
    def test_case_1(self):
        nums, output = self.__testcases[1]
        result = self.__obj.waysToSplitArray(nums = nums)
        self.assertIsInstance(result, int)
        self.assertEqual(result, output)

    @timeout(0.5)
    def test_case_2(self):
        nums, output = self.__testcases[2]
        result = self.__obj.waysToSplitArray(nums = nums)
        self.assertIsInstance(result, int)
        self.assertEqual(result, output)

if __name__ == '__main__': unittest.main()