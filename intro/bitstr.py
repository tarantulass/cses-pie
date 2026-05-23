# dont use that 1e9 in python it is for float operations
# for normal int we stick to 10**9 only as all float cant be converted to int
n = int(input())

print(2**n%(10**9+7))
