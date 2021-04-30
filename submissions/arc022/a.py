s = input()
s = s.upper()
t = "ICT"
cur = 0

for c in s:
  if c == t[cur]:
    cur += 1
  if cur == 3:
    break
    
if cur == 3:
  print("YES")
else:
  print("NO")
