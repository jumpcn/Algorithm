#GOT TLE :(
s = str(raw_input())
d1 = map(int, raw_input().split(' '))
a, b = d1[0], d1[1]
num = int(s)
L = len(s)

MOD = [0 for x in xrange(L + 1)]

if L == 1:
	print "NO"
	exit(0)
A = 0
k = 1
for x in xrange(L - 1, 0, -1):
	MOD[x] = (int(s[x]) * k + MOD[x+1]) % b
	k = k * 10 % b

for x in xrange(L - 1):
	A = (A * 10 + int(s[x])) % a
	if A == 0 and MOD[x + 1] == 0 and s[x+1] != '0':
		print "YES"
		print s[0:x+1]
		print s[x+1:]
		exit(0)
print "NO"