class Automat:
    def __init__(self, stari = [], tranzitii = {}, stareInitiala = 0, stariFinale = [], alfabet = []): 
        self.stari = stari
        self.tranzitii = tranzitii
        self.stareInitiala = stareInitiala
        self.stariFinale = stariFinale
        self.alfabet = alfabet

    def get_stari(self):
        return self.stari

    def set_stari(self, stari):
        self.stari = stari

    def get_tranzitii(self):
        return self.tranzitii

    def set_tranzitii(self, tranzitii):
        self.stari = tranzitii 

    def get_stareInitiala(self):
        return self.stareInitiala
    
    def set_stareInitiala(self, stareInitiala):
        self.stareInitiala = stareInitiala

    def get_stariFinale(self):
        return self.stariFinale

    def set_stariFinale(self, stariFinale):
        self.stariFinale = stariFinale

    def get_alfabet(self):
        return self.alfabet

    def set_alfabet(self, alfabet):
        self.alfabet = alfabet


class DFA(Automat):
    def checkDFA(self, cuv):
        st = self.stareInitiala  # voi lua st drept stare curenta si o voi initializa cu S; voi verifica pe parcurs daca tranzitiile exista
        for lit in cuv:
            for tranzitie in self.tranzitii:
                if st == tranzitie[0][0] and lit == tranzitie[1]:
                    st = tranzitie[0][1]
                    # print(st, end=" ")
                    break
            else:
                print("NU\n")
                break
        else:
            if st in self.stariFinale:
                print("DA\n")
            else:
                print("NU\n")
            print("")

class NFA(Automat):
    def checkNFA(self, cuv):
        listaStari = [self.stareInitiala]  # listaStari reprezinta o lista cu starile posibile; incepe cu starea initiala
        for lit in cuv:
            listaStariActuale = []  # in lista asta adaug toate starile noi
            for tranzitie in self.tranzitii:
                for stare in listaStari:
                    if stare == tranzitie[0][0] and lit == tranzitie[1]:
                        listaStariActuale.append(tranzitie[0][1])
            listaStari = listaStariActuale
        print(listaStari)

        for stare in listaStari:
            if stare in self.stariFinale:
                print("DA\n")
                break
        else:
            print("NU\n")


input = open("input.txt")

dfa = DFA()
nfa = NFA()

coloana = []  #nodul curent
tranzdfa = []

noduri = int(input.readline())
nrNFA = int(input.readline()) # numar de tranzitii nfa

tranzitiiNFA = []
for i in range(nrNFA):
    aux = [input.readline().strip().split()]
    aaux = [aux[0], aux[1]]
    aux = aux[2:]
    aux = [int(x) for x in aux]
    tranzitiiNFA.append([int(aaux[0]), aaux[1], aux])

nfa.set_stareInitiala(int(input.readline()))
nfa.set_stariFinale([int(x) for x in input.readline().strip().split()])
nfa.set_alfabet([input.readline().strip().split()])

coloana.append((nfa.get_stareInitiala(),))

auxDict = {}
for tranzitie in tranzitiiNFA:
    auxDict[(tranzitie[0], tranzitie[1])] = tranzitie[2]
nfa.set_tranzitii(auxDict)

for stare in coloana:
    tranzitiiDFA = {}
    for lit in nfa.get_alfabet():
        if len(stare) == 1 and (stare[0], lit) in nfa.get_tranzitii():
            tranzitiiDFA[(stare, lit)] = nfa.get_tranzitii()[(stare[0], lit)]
            if tuple(tranzitiiDFA[(stare, lit)]) not in coloana:
                coloana.append(tuple(tranzitiiDFA[(stare, lit)]))

        else:
            tuplu = []
            tupluf = []

            for st in stare:
                if (st, lit) in nfa.get_tranzitii() and nfa.get_tranzitii()[(st, lit)] not in tuplu:
                    tuplu.append(nfa.get_tranzitii()[(st, lit)])

            if tuplu:
                for staremare in tuplu:
                    for staremica in staremare:
                        if staremica not in tupluf:
                            tupluf.append(staremica)

                tranzitiiDFA[(stare, lit)] = tupluf

                if tuple(tupluf) not in coloana:
                    coloana.append(tuple(tupluf))
    dfa.set_tranzitii(dfa.get_tranzitii().append(tranzitiiDFA))

auxTranzitiiDfa = []
for key, val in dfa.get_tranzitii().items():
    aux = [[key[0], key[1], val]] 
    auxTranzitiiDfa.extend(aux)

print("starea initiala: ", nfa.get_stareInitiala)
print(*auxTranzitiiDfa, sep="\n")

sfDFA = []
for col in coloana:
  for staref in nfa.get_stariFinale():
    if staref in col:
        sfDFA.append(i)

dfa.set_stariFinale(sfDFA)

print("Starile finale sunt:", end=": ")
print(*dfa.get_stariFinale())
