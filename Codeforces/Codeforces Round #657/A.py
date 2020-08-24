from sys import stdin
T=int(stdin.readline())
for _ in range(T):
    fail=True
    n=int(stdin.readline())
    s=stdin.readline()[:n]
    if s.count("abacaba")<2:
        for i in range(n-6):
            sample="abacaba"
            for j in range(7):
                if s[i+j]=="?":
                    sample=sample[:j] + "?" + sample[j + 1:]
            if s[i:i+7]==sample:
                rep = s[:i]+"abacaba"+s[i+7:]
                if fail==True:
                    if rep.find("abacaba",rep.find("abacaba")+1) == -1:
                        fail=False
                        print("Yes")
                        fp=s.replace("?","z")
                        print(fp[:i]+"abacaba"+fp[i+7:])
    if fail==True:
        print("No")
