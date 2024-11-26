n, m = input().split()

n, m = int(n), int(m)

l = []

for i in range(n):
    s = input()
    temp = []
    for j in range(m):
        temp.append(s[j])
    l.append(temp)
count = 0
print(l)
for i in range(n):
    for j in range(m):
        if l[i][j] == ".":
            if i == 0 or j == 0 or i == (n - 1) or j == (m - 1):
                count += 1
            elif l[i][j - 1] == "." or l[i][j + 1] == "." or l[i + 1][j]== "." or l[i - 1][j] == ".":
                count += 1

print(count)
