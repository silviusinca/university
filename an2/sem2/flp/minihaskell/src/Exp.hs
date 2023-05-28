module Exp where

import Numeric.Natural

newtype Var = Var { getVar :: String }
  deriving (Show)

data ComplexExp                         
  = CX Var 
  | Nat Natural 
  | CLam Var ComplexExp 
  | CApp ComplexExp ComplexExp 
  | Let Var ComplexExp ComplexExp 
  | LetRec Var ComplexExp ComplexExp 
  | List [ComplexExp]  
  deriving (Show)


data IndexedVar = IndexedVar
  { ivName :: String
  , ivCount :: Int
  } deriving (Eq, Read, Show)

makeIndexedVar :: String -> IndexedVar
makeIndexedVar name = IndexedVar name 0

data Exp
  = X IndexedVar
  | Lam IndexedVar Exp
  | App Exp Exp
  deriving (Show)
