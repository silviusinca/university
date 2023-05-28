module EitherClass where

import Prelude (Show(..), (<>), undefined)
import qualified Data.Either as Either (Either (..), either)

import MyPrelude
import BoolClass
class EitherClass e where
  left :: a -> e a b
  right :: b -> e a b
  either :: (a -> c) -> (b -> c) -> e a b -> c

instance EitherClass Either.Either where 
  left = Either.Left
  right = Either.Right
  either = Either.either
fromLeft :: (EitherClass e) => a -> e a b -> a
fromLeft = undefined

fromRight :: (EitherClass e) => b -> e a b -> b
fromRight = undefined

isLeft :: (EitherClass e, BoolClass b) => e l r -> b
isLeft = undefined

isRight :: (EitherClass e, BoolClass b) => e l r -> b
isRight = undefined
 
eitherLeftMap :: EitherClass e => (a -> a') -> e a b -> e a' b
eitherLeftMap = undefined

eitherRightMap :: EitherClass e => (b -> b') -> e a b -> e a b'
eitherRightMap = undefined

newtype CEither a b = CEither { getCEither :: forall c . (a -> c) -> (b -> c) -> c }

instance EitherClass CEither where
  left = undefined
  right = undefined
  either lHandle rHandle e = getCEither e lHandle rHandle

fromEitherClass :: (EitherClass m, EitherClass n) => m a b -> n a b
fromEitherClass = either left right

instance (Show a, Show b) => Show (CEither a b) where
  show cm = "C" <> show (fromEitherClass cm :: Either.Either a b)
