s=''.join(map(lambda x : str(min(int(x), (9-int(x)))), str(raw_input())))
if s[0] == '0': s='9'+s[1:]
print s