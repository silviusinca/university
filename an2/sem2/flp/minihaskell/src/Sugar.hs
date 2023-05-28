module Sugar where

import Exp

desugarVar :: Var -> IndexedVar
desugarVar = makeIndexedVar . getVar

sugarVar :: IndexedVar -> Var
sugarVar iv
  | ivCount iv == 0 = Var (ivName iv)
  | otherwise = Var (ivName iv ++ "_" ++ show (ivCount iv))

consExp, nilExp, zeroExp, succExp, fixExp :: Exp
consExp = X (makeIndexedVar ":")  
nilExp = X (makeIndexedVar "Nil")
zeroExp = X (makeIndexedVar "Z") 
succExp = X (makeIndexedVar "S") 
fixExp = X (makeIndexedVar "fix") 

desugarExp :: ComplexExp -> Exp
desugarExp (CX x) = X (desugarVar x)
desugarExp (CLam x e) = Lam (desugarVar x) (desugarExp e)
desugarExp (CApp e1 e2) = App (desugarExp e1) (desugarExp e2)
desugarExp (Let x ex e) = App (Lam (desugarVar x) (desugarExp e)) (desugarExp ex)
desugarExp (LetRec f ef e)
  = desugarExp (Let f (CApp (CX (Var "fix")) (CLam f ef)) e)
desugarExp (List ces)
  = foldr cons nilExp (map desugarExp ces)
  where
    cons e l = App (App consExp e) l
desugarExp (Nat n)
  = foldr successor zeroExp (replicate (fromIntegral n) ())
  where
    successor _ n = App succExp n

sugarExp :: Exp -> ComplexExp
sugarExp (X x) = CX (sugarVar x)
sugarExp (Lam x e) = CLam (sugarVar x) (sugarExp e)
sugarExp (App e1 e2) = CApp (sugarExp e1) (sugarExp e2)

