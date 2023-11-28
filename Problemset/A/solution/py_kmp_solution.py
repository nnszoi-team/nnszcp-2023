s = "nnsz" + input()
ans = "no\n"
fail = [0]

for i in range(1, len(s)):

    j = fail[i - 1]
    while j and s[i] != s[j]:
        j = fail[j - 1]
    if s[i] == s[j]:
        j += 1
    
    if j >= 4:
        ans = "yes\n"
        break
    fail.append(j)

print(ans)
