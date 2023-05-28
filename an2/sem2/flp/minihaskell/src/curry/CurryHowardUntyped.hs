import Prelude (undefined)
import Distribution.Compat.Lens (_1)

newtype False = False { getFalse :: forall t. t }
newtype True = True { getTrue :: forall t . t -> t }
newtype And a b = And { getAnd :: forall t. (a -> b -> t) -> t }
newtype Or a b = Or { getOr :: forall t . (a -> t) -> (b -> t) -> t}
type Not a = a -> False
type Iff a b = And (a -> b) (b -> a)


trueIntro :: True 
trueIntro = True (\x -> x)
falseElim :: False -> b   
falseElim f = getFalse f 
implIntro :: (a -> b) -> (a -> b) 
implIntro = undefined
implElim :: (a -> b) -> a -> b  
implElim = undefined
andIntro :: a -> b -> And a b  
andIntro = undefined
andElimL :: And a b -> a 
andElimL = undefined
andElimR :: And a b -> b 
andElimR = undefined
orIntroL :: a -> Or a b  
orIntroL = undefined
orIntroR :: b -> Or a b 
orIntroR = undefined
orElim :: Or a b -> (a -> c) -> (b -> c) -> c  
orElim = undefined
notElim :: Not p -> p -> c 
notElim = undefined
notIntro :: (forall p. a -> p) -> Not a 
notIntro _ = undefined
iffIntro :: (a -> b) -> (b -> a) -> Iff a b 
iffIntro = undefined
iffElimL :: Iff a b -> a -> b  
iffElimL = undefined
iffElimR :: Iff a b -> b -> a 
iffElimR = undefined
ax1 :: a -> b -> a
ax1 = undefined
ax2 :: (a -> b) -> (a -> (b -> c)) -> a -> c
ax2 = undefined
ax3 :: a -> b -> And a b
ax3 = undefined
ax4 :: And a b -> a
ax4 = undefined
ax5 :: And a b -> b
ax5 = undefined
ax6 :: a -> Or a b
ax6 = undefined
ax7 :: b -> Or a b
ax7 = undefined
ax8 :: (a -> c) -> (b -> c) -> Or a b -> c
ax8 = undefined
ax9 :: (a -> b) -> (a -> Not b) -> Not a
ax9 = undefined
ax10 :: Not a -> a -> b
ax10 = undefined
modusPonens :: (a -> b) -> a -> b
modusPonens = undefined

pNPFalse :: p -> Not p -> False
pNPFalse = undefined

deMorgan1 :: And (Not p) (Not q) -> Not (Or p q)
deMorgan1 = undefined

deMorgan2 :: Not (Or p q) -> And (Not p) (Not q)
deMorgan2 = undefined

deMorgan3 :: Or (Not p) (Not q) -> Not (And p q)
deMorgan3 = undefined

excludedMiddleImplDoubleNeg :: Or a (Not a) -> (Not (Not a) -> a)
excludedMiddleImplDoubleNeg = undefined

doubleNegImplExcludedMiddle :: (forall a. Not (Not a) -> a) -> Or b (Not b)
doubleNegImplExcludedMiddle dn = undefined
