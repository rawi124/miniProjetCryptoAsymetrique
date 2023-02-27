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
	return int(k, 2)



if __name__ == "__main__":

	g=14789793378077042242120521274037173391261010897636027265546123991563081831117275602982548761034024939845068354539610331532179872637433915394357888709248768667015051009766903635340070489131469049935363547607412057386342667716086793042541140822036624962204941306851549581646548063457001829647969667092583879328471840523390686750127027177781732963459386987665454322343126115917897936842728751365823011567834334210685873039530186907858035417612336029663247537873925629446028254962335530541433683915420633067884365208203268094633097771062061842251521566768365548727309890441197387119672931485366288879688731042699119144292
	p=24614092481603675731022075504383970335861830446883656936098962383938382597155724410430243530965542885322619768354894043222329205609960639841580709735495389909590288527350912074671010178922728935676009317789070638187521776854607144456305976038124908544106052201710087045521190032822578138524094178173865986609218076580978974752369483329590199684056900183812362804154774158997198985445429752558493132015856469411654748592885301239734605491604776596101592931244982321392477545745244182551892125483837624577120046170422115391937038862227491891494491839783639103206553554356553358497274651923633629920203269526755664925609

	B=252239457474958630323587649045614330980454087958089912758321883097065199357012062435821061381302557994141635072505756697173021187014787421454581918982207576837250118591551044991118887437086949356274491383941570368025954469594549027397234677904485857955263227197003914644204898782555235259911490478613264643658581103118217743952922107042947593787435920882024938302871457082327241385815991148938988604347366502729389825202009422332357125151492081509759455308286993938956060533809328214598166969120779878536514116683282303638897632188692694483356969065533381327985880765560045988044692050472124712362603327613010909741

	a = calcul_a('SPATrace.dat')
	print("la cle secrete d alice est " , a)
	A = pow(g, a, p)
	print("la valeur de A " , A)
	k = pow(B, a, p)
	inv = k% (2**256)
	print("cle finale ",inv)

	f = open('SecretKey.dat','w')
	f.write(str(hex(inv)))
	f.close()