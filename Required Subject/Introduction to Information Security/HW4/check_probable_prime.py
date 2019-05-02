#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/12/1 14:43
# @Author  : William Ren(创建者,可自定义)
# @Site    :
# @File    : check_probable_prime.py
# @Software: PyCharm

#!/usr/bin/python
# -*- coding: UTF-8 -*-
import random
def is_probable_prime(n, trials = 10):
    assert n >= 2
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    s = 0
    d = n - 1
    while True:
        quotient, remainder = divmod(d, 2)
        if remainder == 1:
            break
        s += 1
        d = quotient
    assert(2 ** s * d == n - 1)

    def try_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2 ** i * d, n) == n - 1:
                return False
        return True
    for i in range(trials):
        a = random.randrange(2, n)
        if try_composite(a):
            return False

    return True
