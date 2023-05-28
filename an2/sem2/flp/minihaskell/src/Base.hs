{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Use $>" #-}
{-# HLINT ignore "Use <$>" #-}
module Base where

import Control.Applicative ( Alternative(..) )
import Data.Char ( digitToInt, isDigit, isSpace )

newtype Parser a = Parser { apply :: String -> [(a, String)] }

satisfy :: (Char -> Bool) -> Parser Char
satisfy p = Parser go
  where
    go [] = []   
    go (c:input)
      | p c = [(c, input)]
      | otherwise = [] 

anychar :: Parser Char
anychar = satisfy (const True)

char :: Char -> Parser Char
char c = satisfy (== c)

digit :: Parser Char
digit = satisfy isDigit

space :: Parser Char
space = satisfy isSpace

endOfInput :: Parser ()
endOfInput  = Parser go
  where
    go "" = [((), "")]
    go _ = []

instance Functor Parser where
    fmap f pa = Parser (\input -> [(f a, rest) | (a, rest) <- apply pa input])

instance Applicative Parser where
    pure a = Parser (\input -> [(a, input)])
    pf <*> pa = Parser (\input -> [(f a, resta) | (f, restf) <- apply pf input, (a, resta) <- apply pa restf])

parse :: Parser a -> String -> Either String a
parse p str
  | [(one, "")] <- candidates
  = Right one
  | otherwise
  = Left "Sirul de intrare nu a fost complet consumat sau parsare ambigua"
  where
    candidates = apply (p <* endOfInput) str

instance Monad Parser where
    pa >>= k = Parser (\input -> [(b, restb) | (a, resta) <- apply pa input, (b, restb) <- apply (k a) resta])

cifraSemn :: Parser Int
cifraSemn
  = do
    ch <- satisfy (`elem` "+-")
    d <- digitToInt <$> digit
    case ch of
      '-' -> return (-d)
      _ -> return d

cifraSemnApp :: Parser Int
cifraSemnApp = pure convert <*> satisfy (`elem` "+-") <*> (digitToInt <$> digit)
  where
    convert '+' d = d
    convert '-' d = -d

string :: String -> Parser String
string [] = return [] 
string (ch:s) = pure (:) <*> char ch <*> string s
-- și bineînțeles că merge și ca un foldr

instance Alternative Parser where
    empty = Parser (const [])
    p <|> p' = Parser (\input -> apply p input ++ apply p' input)

string2Int :: String -> Int
string2Int = foldl (\n d -> 10 * n + digitToInt d) 0

naiveNatural :: Parser Int
naiveNatural = string2Int <$> naiveNat
  where
    naiveNat = pure (:) <*> digit <*> naiveNat
            <|> pure (:[]) <*> digit

whiteSpace :: Parser ()
whiteSpace = many space *> return ()

nat :: Parser Int
nat = string2Int <$> some digit

lexeme :: Parser a -> Parser a
lexeme p = p <* whiteSpace

natural :: Parser Int
natural = lexeme nat

symbol :: String -> Parser String
symbol = lexeme . string

reserved :: String -> Parser ()
reserved s = symbol s *> return ()

comma :: Parser ()
comma = reserved ","

parens :: Parser a -> Parser a
parens p = reserved "(" *> p <* reserved ")"

brackets :: Parser a -> Parser a
brackets p = reserved "[" *> p <* reserved "]"

commaSep1 :: Parser a -> Parser [a]
commaSep1 p
  = do
    a <- p
    as <- many (comma *> p)
    return (a : as)

commaSep :: Parser a -> Parser [a]
commaSep p = commaSep1 p <|> pure []

ident :: Parser Char -> Parser Char -> Parser String
ident identStart identLetter
  = do
    s <- identStart
    ls <- many identLetter
    return (s:ls)

identifier :: Parser Char -> Parser Char -> Parser String
identifier start letter = lexeme (ident start letter)


semi :: Parser ()
semi = reserved ";"

semiSep1 :: Parser a -> Parser [a]
semiSep1 p
  = do
    a <- p
    as <- many (semi *> p)
    return (a : as)

parseFromFile :: Parser a -> FilePath -> IO (Either String a)
parseFromFile parser file
  = do
    str <- readFile file
    case apply parser str of
      [] -> return $ Left "Cannot parse"
      (a,_):_ -> return $ Right a

