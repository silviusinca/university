module MaybeClass where

import Prelude (Show(..), (<>), undefined) 
import qualified Data.Maybe as Maybe
import qualified Data.Bool as Bool 

import MyPrelude
import BoolClass

class MaybeClass m where
  nothing :: m a
  just :: a -> m a
  maybe :: b -> (a -> b) -> m a -> b

instance MaybeClass Maybe.Maybe where 
  nothing = Maybe.Nothing
  just = Maybe.Just
  maybe = Maybe.maybe

fromMaybe :: (MaybeClass m) => a -> m a -> a
fromMaybe a ma = maybe a id ma 

isNothing :: (MaybeClass m, BoolClass b) => m a -> b
isNothing ma = maybe true (const false) ma

isJust :: (MaybeClass m, BoolClass b) => m a -> b
isJust = maybe false (const true)

maybeFMap :: MaybeClass m => (a -> b) -> m a -> m b
maybeFMap f ma = maybe nothing (just . f) ma

maybeBind :: MaybeClass m => (a -> m b) -> m a -> m b
maybeBind f = maybe nothing f

newtype CMaybe a = CMaybe { getCMaybe :: forall b . b -> (a -> b) -> b }

instance MaybeClass CMaybe where
  nothing = CMaybe (\_nothing _just -> _nothing)
  just x = CMaybe (\_nothing _just -> _just x)
  maybe n j m = getCMaybe m n j

fromMaybeClass :: (MaybeClass m, MaybeClass n) => m a -> n a 
fromMaybeClass = maybe nothing just

instance Show a => Show (CMaybe a) where
  show cm = "C" <> show (fromMaybeClass cm :: Maybe.Maybe a)
