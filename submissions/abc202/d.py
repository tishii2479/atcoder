a, b, k = map(int, input().split())

def nCk(n, k):
    res = 1
    for i in range(1, n + 1):
        res *= i
    for i in range(1, k + 1):
        res //= i
    for i in range(1, n - k + 1):
        res //= i
    return res

ans = ""

n = a + b

for i in range(n):
    use_a = nCk(a + b - 1, a - 1)
    if a == 0:
        ans += 'b'
    elif b == 0:
        ans += 'a'
    else:
        if k > use_a:
            k -= use_a
            b -= 1
            ans += 'b'
        else:
            a -= 1
            ans += 'a'

print(ans)
