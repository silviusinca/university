
module Program where
import Exp
import Base ( Parser, endOfInput, whiteSpace, reserved, semiSep1, symbol, semi )
import Parsing ( expr, var, parseFirst )
import Sugar ( desugarExp, desugarVar )
import Eval ( substitute )

import Control.Applicative ( Alternative(..) )
import System.IO ( stderr, hPutStrLn )
import qualified Data.Map.Strict as Map

data Definition = Definition
  { defHead :: Var
  , defArgs :: [Var]
  , defBody :: ComplexExp
  }
  deriving (Show)

definition :: Parser Definition
definition = do
  x <- var
  y <- many var
  symbol ":="
  z <- expr
  return $ Definition x y z

program :: Parser [Definition]
program = do
  whiteSpace
  def <- semiSep1 definition
  semi
  endOfInput
  return def


definitionExp :: Definition -> ComplexExp
definitionExp def = undefined

type Environment = Map.Map IndexedVar Exp

programEnv :: [Definition] -> Environment
programEnv pgm = undefined

normalizeEnv :: Environment -> Exp -> Exp
normalizeEnv = undefined

