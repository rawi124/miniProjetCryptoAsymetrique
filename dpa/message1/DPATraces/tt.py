import random as rn
def moy(tab):
	"""
	tab : liste d entiers
	retourne la moyenne du tab
	"""
	return sum(tab)//len(tab)

def calcul_a(fichier):
	"""
	fichier : contient les donnees a analyser
	retourne la valeur probable de la cle secrete d Alice
	"""
	file = open(fichier, "r")
	lines = file.readlines()
	file.close()
	content = []
	for line in lines:
		content.append(int(line.strip()))
	i, n = 0, len(content)
	k = ""
	while i+55 < n:
		tmp = content[i:i+55]
		if moy(tmp) >= 65 :
			i += 100
			k+="1"
		else :
			i += 45
			k+="0"
	k = "".join(reversed(k))
	return k

def traitement_PTCT(fichier):
    """
    ouvre le fichier, recupere de chaque ligne A et C
    """
    file = open(fichier, "r")
    lines = file.readlines()
    file.close()
    C, P = [], []
    for line in lines:
        l = line.split()
        C.append(l[0])
        P.append(l[1])
    return C, P

def random_square(n, p):
    """
    n : A
    p : prime cst
    retourne n exp alea mod p
    """
    a = rn.getrandbits(223)
    X = "11"
    for i in range(222):
        X 





if __name__ == '__main__':
    C, P = traitement_PTCT("PTCT.dat")
    l = []
    for i in range(500):
        l.append(calcul_a("DPATrace"+str(i)+".dat"))
    print(len(l[150]))
