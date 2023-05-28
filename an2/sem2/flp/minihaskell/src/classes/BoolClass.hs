module BoolClass where

import Prelude (Show (..), (<>), undefined) 
import qualified Data.Bool as Bool

import MyPrelude
class BoolClass b where
  false :: b
  true :: b
  bool :: a -> a -> b -> a

instance BoolClass Bool.Bool where
  true = Bool.True
  false = Bool.False
  bool = Bool.bool

ite :: BoolClass b => b -> a -> a -> a
ite c t e = bool e t c 

(&&) :: BoolClass b => b -> b -> b
(&&) t1 t2 = bool false t1 t2
(||) :: BoolClass b => b -> b -> b
(||) t1 t2 = bool t1 true t2
not :: BoolClass b => b -> b
not t = ite t false true
newtype CBool = CBool { getCBool :: forall a. a -> a -> a}

instance BoolClass CBool where
  true = CBool (\f t -> t)
  false = CBool (\f t -> f)
  bool f t b = getCBool b f t

fromBoolClass :: (BoolClass a, BoolClass b) => a -> b
fromBoolClass = bool false true
instance Show CBool where
  show cb = "C" <> show (fromBoolClass cb :: Bool.Bool)
