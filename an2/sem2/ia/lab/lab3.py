class NodParcurgere:
    def __init__(self, info, g=0, h=0, parinte=None):
        self.info = info  # eticheta nodului, de exemplu: 0,1,2...
        self.parinte = parinte  # parintele din arborele de parcurgere
        self.g = g
        self.h = h
        self.f = g+h

    def drumRadacina(self):
        l = []
        nod = self
        while nod:
            l.insert(0, nod)
            nod = nod.parinte
        return l


    def vizitat(self): #verifică dacă nodul a fost vizitat (informatia lui e in propriul istoric)
        nodDrum = self.parinte
        while nodDrum:
            if (self.info == nodDrum.info):
                return True
            nodDrum = nodDrum.parinte

        return False

    def __str__(self):
        repr_barca = ":<barca>"
        repr_fara_barca = ""
        if self.info[2] == 1:
            barcaMalInitial = repr_barca
            barcaMalFinal = repr_fara_barca
        else:
            barcaMalInitial = repr_fara_barca
            barcaMalFinal = repr_barca
        return "(Stanga{}) {} canibali {} misionari  ......  (Dreapta{}) {} canibali  {} misionari\n\n".format(
            barcaMalInitial, self.info[1], self.info[0], barcaMalFinal, Graph.N - self.info[1],
            Graph.N - self.info[0])

    def afisSolFisier(self, fis):  # returneaza si lungimea drumului
        l = self.drumRadacina()
        for nod in l:
            if nod.parinte is not None:
                if nod.parinte.info[2] == 1:
                    mbarca1 = "stang"
                    mbarca2 = "drept"
                else:
                    mbarca1 = "drept"
                    mbarca2 = "stang"
                fis.write(
                    ">>> Barca s-a deplasat de la malul {} la malul {} cu {} canibali si {} misionari.\n".format(mbarca1,
                            mbarca2, abs( nod.info[1] - nod.parinte.info[1]), abs(nod.info[0] - nod.parinte.info[0])))
            fis.write(str(nod))



    def __repr__(self):
        sir = str(self.info) + "("
        drum = self.drumRadacina()
        sir += ("->").join([str(n.info) for n in drum])
        sir += ")"
        return sir


class Graph:  # graful problemei

    def __init__(self,start, scopuri, lista_h):
        self.start = start  # informatia nodului de start
        self.scopuri = scopuri  # lista cu informatiile nodurilor scop
        self.lista_h = lista_h

    # va genera succesorii sub forma de noduri in arborele de parcurgere
    def succesori(self, nodCurent):
        listaSuccesori = []
        for i in range(self.nrNoduri):
            if self.matrice[nodCurent.info][i] != 0:
                nodNou = NodParcurgere(info=i, g=nodCurent.g + self.matrice[nodCurent.info][i], h = self.estimeaza_h(i), parinte=nodCurent)
                if not nodNou.vizitat():
                    listaSuccesori.append(nodNou)
        return listaSuccesori

    def scop(self, infoNod):
        return infoNod in self.scopuri

    def estimeaza_h(self, nod):
        return self.lista_h[nod]



m = [
    [0, 3, 5, 10, 0, 0, 100],
    [0, 0, 0, 4, 0, 0, 0],
    [0, 0, 0, 4, 9, 3, 0],
    [0, 3, 0, 0, 2, 0, 0],
    [0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 4, 0, 5],
    [0, 0, 3, 0, 0, 0, 0]
]

start = 0
scopuri = [4, 6]
lista_h = [0, 1, 6, 2, 0, 3, 0]
gr = Graph(m, start, scopuri, lista_h)

def bin_search(lista_noduri, nodDeInserat, ls, ld):
    mij = (ls + ld)//2
    if mij >= len(lista_noduri):
        return mij
    if mij < 0:
        return 0
    if ls == ld:
        if lista_noduri[ls].f < nodDeInserat.f:
            return ls+1
        elif lista_noduri[ls].f > nodDeInserat.f:
            return ls-1
        elif lista_noduri[mij].f == nodDeInserat.f:
            if lista_noduri[mij].g == nodDeInserat.g:
                return ls
            elif lista_noduri[mij].g > nodDeInserat.g:
                return ls+1
            else:
                return ls-1
    if lista_noduri[mij].f == nodDeInserat.f:
        if lista_noduri[mij].g == nodDeInserat.g:
            return mij
        elif lista_noduri[mij].g > nodDeInserat.g:
            return bin_search(lista_noduri, nodDeInserat, mij+1, ld)
        else:
            return bin_search(lista_noduri, nodDeInserat, ls, mij)
    elif lista_noduri[mij].f > nodDeInserat.f:
        return bin_search(lista_noduri, nodDeInserat, ls, mij)
    else:
        return bin_search(lista_noduri, nodDeInserat, mij+1, ld)

def aStarSolMultiple(gr, nrSolutiiCautate=1):
    # in coada vom avea doar noduri de tip NodParcurgere (nodurile din arborele de parcurgere)
    c = [NodParcurgere(gr.start, 0, gr.estimeaza_h(gr.start))]

    while len(c) > 0:
        #print("Coada actuala: " + str(c))
        #input()
        nodCurent = c.pop(0)

        if gr.scop(nodCurent.info):
            print("Solutie:")
            drum = nodCurent.drumRadacina()
            print(("->").join([str(n.info) for n in drum]))
            print("Cost " + str(nodCurent.f))
            print("\n----------------\n")
            #input()
            nrSolutiiCautate -= 1
            if nrSolutiiCautate == 0:
                return
        for s in gr.succesoi(nodCurent):
            indice = bin_search(c, s, 0, len(c)-1)
            if indice == len(c):
                c.append(s)
            else:
                c.insert(indice, s)


#### algoritm BF
# presupunem ca vrem mai multe solutii (un numar fix) prin urmare vom folosi o variabilă numită nrSolutiiCautate
# daca vrem doar o solutie, renuntam la variabila nrSolutiiCautate
# si doar oprim algoritmul la afisarea primei solutii

def breadth_first(gr, nrSolutiiCautate=1):
    # in coada vom avea doar noduri de tip NodParcurgere (nodurile din arborele de parcurgere)
    c = [NodParcurgere(gr.start)]

    while len(c) > 0:
        #print("Coada actuala: " + str(c))
        #input()
        nodCurent = c.pop(0)

        if gr.scop(nodCurent.info):
            print("Solutie:")
            drum = nodCurent.drumRadacina()
            print(("->").join([str(n.info) for n in drum]))
            print("\n----------------\n")
            #input()
            nrSolutiiCautate -= 1
            if nrSolutiiCautate == 0:
                return
        c+=gr.succesori(nodCurent)


def depth_first(gr, nrSolutiiCautate=1):
    # vom simula o stiva prin relatia de parinte a nodului curent
    df(NodParcurgere(gr.start), nrSolutiiCautate)


def df(nodCurent, nrSolutiiCautate):
    if nrSolutiiCautate <= 0:  # testul acesta s-ar valida doar daca in apelul initial avem df(start,if nrSolutiiCautate=0)
        return nrSolutiiCautate
    #print("Stiva actuala: " + repr(nodCurent.drumRadacina()))
    #input()
    if gr.scop(nodCurent.info):
        print("Solutie: ", end="")
        drum = nodCurent.drumRadacina()
        print(("->").join([str(n.info) for n in drum]))
        print("\n----------------\n")
        #input()
        nrSolutiiCautate -= 1
        if nrSolutiiCautate == 0:
            return nrSolutiiCautate
    lSuccesori = gr.succesori(nodCurent)
    for sc in lSuccesori:
        if nrSolutiiCautate != 0:
            nrSolutiiCautate = df(sc, nrSolutiiCautate)

    return nrSolutiiCautate


# df(a)->df(b)->df(c)->df(f)
#############################################


def df_nerecursiv(nrSolutiiCautate):
    stiva = [NodParcurgere(gr.start)]
    #consider varful stivei in dreapta
    while stiva: #cat timp stiva nevida
        nodCurent=stiva.pop() #sterg varful
        if gr.scop(nodCurent.info):
            print("Solutie:")
            drum = nodCurent.drumRadacina()
            print(("->").join([str(n.info) for n in drum]))
            print("\n----------------\n")
            #input()
            nrSolutiiCautate -= 1
            if nrSolutiiCautate == 0:
                return
        stiva+=gr.succesori(nodCurent)[::-1] #adaug in varf succesoii in ordine inversa deoarece vreau sa expandez primul succesor generat si trebuie sa il pun in varf

"""
Mai jos puteti comenta si decomenta apelurile catre algoritmi. Pentru moment e apelat doar breadth-first
"""

print("====================================================== \nBreadthfirst")
breadth_first(gr, nrSolutiiCautate=4)
print("====================================================== \nDepthFirst recursiv")
depth_first(gr, nrSolutiiCautate=4)
print("====================================================== \nDepthFirst nerecursiv")
df_nerecursiv(nrSolutiiCautate=4)