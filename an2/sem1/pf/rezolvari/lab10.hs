-- instante pentru Functor: 
newtype Identity a = Identity a
instance Functor Identity where 
    fmap f (Identity a) = Identity (f a)

data Pair a = Pair a a
instance Functor Pair where
    fmap f (Pair a b) = Pair (f a) (f b)

data Constant a b = Constant b
instance Functor Constant where
    fmap f (Constant a) = Constant (f a)

data Two a b = Two a b
instance Functor (Two a) where
    fmap f (Two x y) = Two x (f y)

data Three a b c = Three a b c
instance Functor (Three a b) where
    fmap f (Three x y z) = Three x y (f z)

data Three' a b = Three' a b b
instance Functor (Three' a) where
    fmap f (Three' x y z) = Three' x (f y) (f z)

data Four a b c d = Four a b c d

data Four'' a b = Four'' a a a b

data Quant a b = Finance | Desk a | Bloor b


