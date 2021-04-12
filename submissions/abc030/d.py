n, a = map(int, input().split())
k = int(input())
b = list(map(int, input().split()))
b = [0] + b
memo = [-1] * (n + 1)
cur = 0
while memo[a] == -1:
    if cur == k:
        print(a)
        exit(0)
    memo[a] = cur
    a = b[a]
    cur += 1
loop = cur - memo[a]
k -= memo[a]
k %= loop
for _ in range(k):
    a = b[a]
print(a)