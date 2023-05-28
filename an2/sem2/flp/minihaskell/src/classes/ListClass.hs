module ListClass where

import Prelude (Show(..), (<>))
import qualified Data.List as List (foldr)

import MyPrelude
import BoolClass
import MaybeClass
import NatClass
import PairClass

data ListClass l a = ListClass { nil :: l a, cons :: a -> l a -> l a, foldr :: forall b. (a -> b -> b) -> b -> l a -> b }

list :: ListClass [] a
list = ListClass
  { nil = []
  , cons = (:)
  , foldr = List.foldr
  }

(++) :: ListClass l a -> l a -> l a -> l a
(++) l = flip (foldr l (cons l))

length :: ListClass l a -> l a -> CNat
length l = foldr l (const succ) zero

isNull :: ListClass l a -> l a -> CBool
isNull l = foldr l (const (const false)) true

map :: ListClass la a -> ListClass lb b -> (a -> b) -> la a -> lb b
map la lb f = foldr la (cons lb . f) (nil lb)

filter :: ListClass l a -> (a -> CBool) -> l a -> l a
filter la p = foldr la (\a l -> bool l (cons la a l) (p a)) (nil la)

foldl :: ListClass l a -> (b -> a -> b) -> b -> l a -> b
foldl l agg def xs = foldr l (\a f acc -> f (agg acc a)) id xs def

uncons :: ListClass l a -> l a -> CMaybe (CPair a (l a))
uncons l = foldr l (\a -> just . pair a . maybe (nil l) (uncurry (cons l))) nothing

head :: ListClass l a -> l a -> CMaybe a
head l = maybeFMap fst . uncons l

tail :: ListClass l a -> l a -> CMaybe (l a)
tail l = maybeFMap snd . uncons l

reverse :: ListClass l a -> l a -> l a
reverse l = foldl l (flip (cons l)) (nil l)

sum :: ListClass l CNat -> l CNat -> CNat
sum l = foldr l add zero

product :: ListClass l CNat -> l CNat -> CNat
product l = foldr l mul one

maximum :: ListClass l CNat -> l CNat -> CNat
maximum l = foldr l max zero

natToList :: ListClass l CNat -> CNat -> l CNat
natToList lnat = iter (\l -> maybe (cons lnat one (nil lnat)) (\p -> cons lnat (succ (fst p)) l) (uncons lnat l)) (nil lnat)

newtype CList a = CList { getCList :: forall b . (a -> b -> b) -> b -> b}

clist :: ListClass CList a
clist = ListClass
  { foldr = \f i l -> getCList l f i
  , nil = CList (\f i -> i)
  , cons = \x l -> CList (\f i -> f x (getCList l f i))
  }

fromListClass :: ListClass l1 a -> ListClass l2 a -> l1 a -> l2 a
fromListClass l1 l2 = map l1 l2 id

instance Show a => Show (CList a) where
  show cl = "{" <> show (fromListClass clist list cl) <> "}"

factorial :: ListClass l CNat -> CNat -> CNat
factorial l = product l . natToList l

