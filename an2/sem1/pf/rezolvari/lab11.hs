data List a = Nil | Cons a (List a) deriving (Eq, Show)

instance Functor List where
    fmap f Nil = Nil 
    fmap f (Cons a lst) = Cons (f a) (fmap f lst)




