file = open('SPATrace.dat', "r")
lines = file.readlines()
file.close()
ch = []
for line in lines:
	ch.append(int(line.strip()))
def moy(tab):
	return sum(tab)//len(tab)
def tt(tab):
	i = 0
	f = ""
	cpt = 0
	while i+55 < len(tab):
		t = tab[i:i+55]
		m = moy(t)
		if m >= 65 :
			i += 100
			f+="1"
			cpt += 1
		else :
			i += 45
			f+="0"
	return f
print(int(tt(ch) ,2))
