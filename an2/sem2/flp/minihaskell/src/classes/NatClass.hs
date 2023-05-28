module NatClass where

import Prelude (Show(..), (<>), Num(fromInteger))
import qualified GHC.Natural as Natural (Natural, plusNatural, minusNatural)

import MyPrelude
import BoolClass
import MaybeClass
 
class NatClass n where
  zero :: n
  succ :: n -> n
  iter :: (a -> a) -> a -> n -> a

instance NatClass Natural.Natural where
  zero = 0
  succ n = n `Natural.plusNatural` 1
  iter f i 0 = i
  iter f i n = f (iter f i (n `Natural.minusNatural` 1))

one :: NatClass n => n
one = succ zero

isZero :: NatClass n => n -> CBool
isZero = iter (const false) true

add :: NatClass n => n -> n -> n
add = iter succ
mul :: NatClass n => n -> n -> n
mul m = iter (add m) zero

exp :: NatClass n => n -> n -> n
exp m = iter (mul m) one

pred :: NatClass n  => n -> CMaybe n
pred = iter (just . maybe zero succ) nothing

sub :: NatClass n  => n -> n -> CMaybe n
sub m = iter (maybe nothing pred) (just m)

lt :: NatClass n => n -> n -> CBool 
lt m n = isNothing (sub m n)

gt :: NatClass n => n -> n -> CBool 
gt = flip lt

gte :: NatClass n => n -> n -> CBool 
gte m n = not (lt m n)

lte :: NatClass n => n -> n -> CBool 
lte = flip gte

eq :: NatClass n => n -> n -> CBool 
eq m n = lte m n && lte n m

max :: NatClass n => n -> n -> n
max m n = bool m n (lte m n)

newtype CNat = CNat { getCNat :: forall a . (a -> a) -> a -> a }

instance NatClass CNat where
  iter f i n = getCNat n f i
  zero = CNat (\f i -> i)
  succ n = CNat (\f i -> f (getCNat n f i))

fromNatClass :: (NatClass n, NatClass m) => n -> m
fromNatClass = iter succ zero

instance Show CNat where
  show cn = "C" <> show (fromNatClass cn :: Natural.Natural)

instance Num CNat where
  fromInteger n = fromNatClass (fromInteger n :: Natural.Natural)
