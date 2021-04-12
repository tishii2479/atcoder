r, x, y = map(int, input().split())
dist = x*x + y*y
rr = r*r
left = 0
right = int(1e50)
if rr > dist:
    print(2)
    exit(0)
while right - left > 1:
    m = (left + right) // 2
    if m * m * rr >= dist:
        right = m
    else:
        left = m
print(int(right))
