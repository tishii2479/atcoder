a, b = map(int, input().split())

def gcd(a, b):
  if a % b == 0: return b
  else: return gcd(b, a % b)

def lcm(a, b):
  return a * b // gcd(a, b)

val = lcm(a, b)

if val > (int)(1e18):
  print("Large")
else:
  print(val)
