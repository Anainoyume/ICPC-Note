import sys
import math

'''
    ���� + ��շ�
'''

n, m = map(int,input().split())

sys.set_int_max_str_digits(1000000) # �������λ��

a = 1
for i in range(n-m+4,n+4):
    a *= i
for i in range(1,n+3):
    a *= i

b = 1
for i in range(n-m+3,n+3):
    b *= i
for i in range(1,n+2):
    b *= i
b *= 2

print(a-b)