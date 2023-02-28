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
        return infoNod in self.scop

    def succesori(self, nod):
        noduri = []

        for liste in self.graf:
            for vecin in liste:
                if vecin.parinte == nod or nod.parinte == vecin:
                    noduri.append(vecin)
        
        return noduri

solutii = []

def dfs(graf, nod, NSOL):
    if graf.scop(nod.informatie):
        solutii.append(nod)
        NSOL -= 1

    if NSOL == 0:
        return

    for succesor in graf.succesori(nod):
        if not succesor.vizitat():
            dfs(graf, succesor, NSOL)

