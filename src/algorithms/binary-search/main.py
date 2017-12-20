import math
import unittest

class TestSearch(unittest.TestCase):

    def test_small_search(self):
        l = [i for i in range(3)]
        self.assertEqual(0, bsearch(l, 0))

    def test_end_range(self):
        l = [i for i in range(100)]
        self.assertEqual(99, bsearch(l, 99))

    def test_successful_search(self):
        l = [i for i in range(100)]
        self.assertEqual(31, bsearch(l, 31))

    def test_failed_search(self):
        l = [i for i in range(10)]
        self.assertEqual(-1, bsearch(l, 15))

def bsearch(l, x):
    ''' Binary search

    Precondition: l should be sorted

    Args:
        l: input list
        x: element to find
    Returns: index of `x` if x is in `l`, -1 otherwise
    '''
    n = len(l)
    search_len = n//2
    cur_idx = search_len
    while (cur_idx > 0 and cur_idx < n):
        search_len = max(search_len//2, 1)
        if l[cur_idx] == x:
            break
        elif l[cur_idx] < x:
            cur_idx += search_len
        else:
            cur_idx -= search_len
    if cur_idx == n or cur_idx < 0:
        return -1
    else:
        return cur_idx

if __name__ == '__main__':
    unittest.main()
