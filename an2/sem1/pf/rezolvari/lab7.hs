data Expr = Const Int
          | Expr :+: Expr -- adunare
          | Expr :*: Expr -- inmultire

data Operation = Add | Mult deriving (Eq, Show)

data Tree = Lf Int -- frunza
          | Node Operation Tree Tree -- muchie
          deriving (Eq, Show)

-- 1.1
instance Show Expr where
  show (Const x) = show x
  show (a :+: b) = "(" ++ show a ++ " + " ++ show b ++ ")"
  show (a :*: b) = "(" ++ show a ++ " * " ++ show b ++ ")"

-- 1.2
exp1 = ((Const 2 :*: Const 3) :+: (Const 0 :*: Const 5))
exp2 = (Const 2 :*: (Const 3 :+: Const 4))
exp3 = (Const 4 :+: (Const 3 :*: Const 3))
exp4 = (((Const 1 :*: Const 2) :*: (Const 3 :+: Const 1)) :*: Const 2)

evalExp :: Expr -> Int
evalExp (Const x) = x
evalExp (a :+: b) = evalExp a + evalExp b
evalExp (a :*: b) = evalExp a * evalExp b

-- 1.3
arb1 = Node Add (Node Mult (Lf 2) (Lf 3)) (Node Mult (Lf 0) (Lf 5))
arb2 = Node Mult (Lf 2) (Node Add (Lf 3) (Lf 4))
arb3 = Node Add (Lf 4) (Node Mult (Lf 3) (Lf 3))
arb4 = Node Mult (Node Mult (Node Mult (Lf 1) (Lf 2)) (Node Add (Lf 3) (Lf 1))) (Lf 2)

evalArb :: Tree -> Int
evalArb (Lf x) = x
evalArb (Node Add a b) = evalArb a + evalArb b
evalArb (Node Mult a b) = evalArb a * evalArb b

-- 1.4
expToArb :: Expr -> Tree
expToArb (Const x) = Lf x
expToArb (a :+: b) = (Node Add (expToArb a) (expToArb b))
expToArb (a :*: b) = (Node Mult (expToArb a) (expToArb b))

class Collection c where
    empty :: c key value
    singleton :: key -> value -> c key value
    insert :: Ord key => key -> value -> c key value -> c key value
    lookup :: Ord key => key -> c key value -> Maybe value 
    delete :: Ord key => key -> c key value -> c key value
    keys :: c key value -> [key]
    values :: c key value -> [value]
    toList :: c key value -> [(key, value)]
    fromList :: Ord key => [(key, value)] -> c key value

