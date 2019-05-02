#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/11/24 19:16
# @Author  : William Ren(创建者,可自定义)
# @Site    : 
# @File    : HW3.py
# @Software: PyCharm



def IP(PlainText):
    assert len(PlainText) == 64
    # Initial permut matrix for the datas.
    IPtable = [58, 50, 42, 34, 26, 18, 10, 2,
               60, 52, 44, 36, 28, 20, 12, 4,
               62, 54, 46, 38, 30, 22, 14, 6,
               64, 56, 48, 40, 32, 24, 16, 8,
               57, 49, 41, 33, 25, 17, 9, 1,
               59, 51, 43, 35, 27, 19, 11, 3,
               61, 53, 45, 37, 29, 21, 13, 5,
               63, 55, 47, 39, 31, 23, 15, 7]
    ret = ""
    for i in IPtable:
        ret = ret + PlainText[i - 1]
    return ret


# Left Shift
def shift(a, s):
    try:
        if len(a) > 28:
            raise NameError
    except TypeError:
        pass

    a = a[s:] + a[0:s]
    return a



def createSubkey(key):
    assert len(key) == 64
    # Initial permut made on the key
    CP_1 = [57, 49, 41, 33, 25, 17, 9,
             1, 58, 50, 42, 34, 26, 18,
             10, 2, 59, 51, 43, 35, 27,
             19, 11, 3, 60, 52, 44, 36]

    # Permut applied on shifted key to get Ki+1
    CP_2 = [63, 55, 47, 39, 31, 23, 15,
             7, 62, 54, 46, 38, 30, 22,
             14, 6, 61, 53, 45, 37, 29,
             21, 13, 5, 28, 20, 12, 4]
    # 初试生成
    C0 = ""
    D0 = ""
    for i in CP_1:
        C0 += key[i - 1]
    for i in CP_2:
        D0 += key[i - 1]
    assert len(C0) == 28
    assert len(D0) == 28

    mvT = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]

    retkey = []
    PC_2 = [14, 17, 11, 24, 1, 5,
            3, 28, 15, 6, 21, 10,
            23, 19, 12, 4, 26, 8,
            16, 7, 27, 20, 13, 2,
            41, 52, 31, 37, 47, 55,
            30, 40, 51, 45, 33, 48,
            44, 49, 39, 56, 34, 53,
            46, 42, 50, 36, 29, 32]
    for i in range(0, 16):
        C0 = shift(C0, mvT[i])
        D0 = shift(D0, mvT[i])
        tem = C0 + D0
        temkey = ""
        for i in PC_2:
            temkey += tem[i - 1]
        assert len(temkey) == 48
        retkey.append(temkey)
        temkey = ""

    return retkey

#Expand matrix to get a 48bits matrix of datas to apply the xor with Ki
def ExpanReplace(Er):
    Elist = [
             32, 1, 2, 3, 4, 5,
              4, 5, 6, 7, 8, 9,
              8, 9, 10, 11, 12, 13,
             12, 13, 14, 15, 16, 17,
             16, 17, 18, 19, 20, 21,
             20, 21, 22, 23, 24, 25,
             24, 25, 26, 27, 28, 29,
             28, 29, 30, 31, 32, 1
            ]
    retEr = ""
    for i in Elist:
        retEr += Er[i - 1]
    assert len(retEr) == 48
    return retEr


S = [
        (14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
          0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
          4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
         15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13),
        (15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
        3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
        0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
        13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9),
        (10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
        13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
        13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
        1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12),
        (7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
        13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
        10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
        3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14),
        (2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
        14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
        4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
        11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3),
        (12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
        10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
        9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
        4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13),
        (4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
        13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
        1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
        6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12),
        (13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
        1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
        7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
        2, 1, 14, 7, 4, 10, 8, 13,15, 12, 9, 0, 3, 5, 6, 11)]

#f-function permutation
fFp = [16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10,
        2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25]



def S_sub(Ir, Er, subkey, oldEr):
    temresult = int(Er, base=2) ^ int(subkey, base=2)
    temresult = bin(temresult)[2:]
    while len(temresult) < 48:
        temresult = "0" + temresult
    index = 0
    retstr = ""
    for list in S:
        hang = int(temresult[index] + temresult[index + 5], base=2)
        lie = int(temresult[index + 1:index + 5], base=2)
        a = bin(list[hang * 16 + lie])[2:]
        while len(a) < 4:
            a = "0" + a
        retstr += a
        index += 6

    assert len(retstr) == 32
    tmp = ""
    for i in fFp:
        tmp += retstr[i - 1]

    a = int(tmp, base=2) ^ int(Ir, base=2)
    a = bin(a)[2:]
    while len(a) < 32:
        a = "0" + a
    assert len(a) == 32
    (Ir, Er) = (oldEr, a)
    w5555555555 = Ir + Er
    return (Ir, Er)


def P_1(L16, R16):
    tmp = L16 + R16
    list = [40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25]
    retstr = ""
    for i in list:
        retstr += tmp[i - 1]
    assert len(retstr) == 64
    return retstr


if __name__ == "__main__":
    key = "1010111110101111101011111010111110101111101011111010111110101111"
    PlainText = "1010101111001101111011110000000100100011010001010110011110001001"

    initialReplacement = IP(PlainText)
    subkeylist = createSubkey(key)
    Ir = initialReplacement[0:32]
    Er = initialReplacement[32:]
    for subkey in subkeylist:
        while len(Er) < 32:
            Er = "0" + Er
        while len(Ir) < 32:
            Ir = "0" + Ir
        Er_tuozhan = ExpanReplace(Er)
        (Ir, Er) = S_sub(Ir, Er_tuozhan, subkey, Er)

    (Ir, Er) = (Er, Ir)
    b = P_1(Ir, Er)
    print(hex(int(b, base=2)).upper())
