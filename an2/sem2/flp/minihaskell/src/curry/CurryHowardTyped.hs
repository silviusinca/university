import Prelude (undefined)

data False 
data True = True 
data And a b = And { proj1 :: a, proj2 :: b }
data Or a b
  = Left a
  | Right b

type Not a = a -> False
type Iff a b = And (a -> b) (b -> a)

trueIntro :: True 
trueIntro = True

falseElim :: False -> b 
falseElim x = case x of

implIntro :: (a -> b) -> (a -> b) 
implIntro f = f

implElim :: (a -> b) -> a -> b 
implElim f = f

andIntro :: a -> b -> And a b 
andIntro a b = And a b 

andElimL :: And a b -> a 
andElimL and = proj1 and

andElimR :: And a b -> b  
andElimR and = proj2 and 

orIntroL :: a -> Or a b  
orIntroL a = Left a

orIntroR :: b -> Or a b  
orIntroR b = Right b

orElim :: Or a b -> (a -> c) -> (b -> c) -> c  
orElim orAB fac fbc = case orAB of
  Left a -> fac a
  Right b -> fbc b

notElim :: Not p -> p -> c  
notElim notA a = falseElim (notA a)

notIntro :: (forall p. a -> p) -> Not a  
notIntro f = f

iffIntro :: (a -> b) -> (b -> a) -> Iff a b 
iffIntro fab fba = And fab fba 

iffElimL :: Iff a b -> a -> b  
iffElimL (And fab _fba) a = fab a

iffElimR :: Iff a b -> b -> a  
iffElimR (And _fab fba) b = fba b

ax1 :: a -> b -> a
ax1 a b = implIntro (\a -> implIntro (\b -> a)) a b 

ax2 :: (a -> b) -> (a -> (b -> c)) -> a -> c
ax2 f g a = implIntro (\a -> implIntro (\g -> implIntro (\a -> implElim (implElim g a) (implElim f a)))) f g a 

ax3 :: a -> b -> And a b
ax3 = implIntro (\a -> implIntro (\b -> andIntro a b)) a b 

ax4 :: And a b -> a
ax4 = andElimL

ax5 :: And a b -> b
ax5 = andElimR

ax6 :: a -> Or a b
ax6 = orIntroL

ax7 :: b -> Or a b
ax7 = orIntroR

ax8 :: (a -> c) -> (b -> c) -> Or a b -> c
ax8 ac bc ab = orElim ab ac bc

ax9 :: (a -> b) -> (a -> Not b) -> Not a
ax9 ab anb = notIntro (\a -> notElim (implElim anb a) (implElim ab a))

ax10 :: Not a -> a -> b
ax10 na a = notElim na a

modusPonens :: (a -> b) -> a -> b
modusPonens f = f 

pNPFalse :: p -> Not p -> False
pNPFalse = undefined

deMorgan1 :: And (Not p) (Not q) -> Not (Or p q)
deMorgan1 = implIntro (\andn -> (\or -> orElim or (andElimL andn) (andElimR andn)))

deMorgan2 :: Not (Or p q) -> And (Not p) (Not q)
deMorgan2 = undefined

deMorgan3 :: Or (Not p) (Not q) -> Not (And p q)
deMorgan3 = undefined

type DeMorgan4 = forall p q . Not (And p q) -> Or (Not p) (Not q)

type ExcludedMiddle = forall a. Or a (Not a)
type DoubleNegation = forall a. Not (Not a) -> a
type PeirceLaw = forall p q. ((p -> q) -> p) -> p

excludedMiddleImplDoubleNeg :: ExcludedMiddle -> DoubleNegation
excludedMiddleImplDoubleNeg em = undefined

doubleNegImplExcludedMiddle :: DoubleNegation -> ExcludedMiddle -- hard
doubleNegImplExcludedMiddle dn = undefined

classicDeMorgan4 :: ExcludedMiddle -> DeMorgan4
classicDeMorgan4 em = undefined

