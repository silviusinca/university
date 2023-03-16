class Nod:
    def __init__(self, _info, _parinte=None):
        self.info = _info
        self.parinte = _parinte

    def drumRadacina(self):
        drum = []
        nod = self
        while nod.parinte != None:
            drum.append(nod.info)
            nod.info = nod.parinte
        return drum

    def vizitat(self, nod):
        return nod.info in self.drumRadacina()

    def __repr__(self):
        str = self.info + " ("
        drum = drumRadacina()

        for nod in drum:
            if nod.info != self.info:
                str += nod.info + "->"
    
        str += ")"
        return str

    def __str__(self):
        return self.info

class Graf:
    def __init__(self, _graf, _scop):
        self.graf = _graf
        self.scop = _scop

    def scop(self, infoNod):
        

    def succesori(self, nod):
        noduri = []
        for vecin in graf[nod.info]:
            if vecin.parinte == nod:
                noduri.append(Nod(vecin, nod))
        
        return noduri

# Graf.N = ce s-a citit

f = open("fisier.txt", "r")
date = [int(x) for x in f.readline().split()]

N = date[0] # numarul de misionari si canibali
M = date[1] # numarul de locuri in barca
locatie = 1

stare = [N, M, locatie]



succesori(nod)
#mal curent = mal cu barca
#mal opus= mal fara barca
if nod.info[2] == 1: #mal stang(initial)
    NCmal_curent = nod.info[0]
    NMmal_curent = nod.info[1]
    NCmal_opus   = N - NCmal_curent
    NMmal_opus   = N - NMmal_curent
# else:
     
maxMisionariBarca = min(Graf.M, NMmal_curent)
for mb in range(maxMisionariBarca+1):
	if mb == 0:
		minCanB = 1
		maxCanBarca=min(Graf.M, NCmal_curent)
	else:
		minCanB=0
		maxCanBarca=min(Graf.M-mb, NCmal_curent, mb)
	for cb in range(minCanB, maxCanBarca+1):
		NCmal_curentNou=NCmal_curent-cb
		...
		NCmal_opusNou=NCmal_opus+cb
		#testare maluri
			#daca ok, atunci creez Nod(informatieNoua)
				# adaug in lista succesori daca nu e vizitat


