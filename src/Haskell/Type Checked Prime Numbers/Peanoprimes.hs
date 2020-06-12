{-# LANGUAGE DataKinds            #-}
{-# LANGUAGE GADTs                #-}
{-# LANGUAGE NoImplicitPrelude    #-}
{-# LANGUAGE TypeFamilies         #-}
{-# LANGUAGE TypeOperators        #-}
{-# LANGUAGE UndecidableInstances #-}
{-# LANGUAGE TypeInType           #-}

import qualified Prelude as P

data Bool = True | False
data Nat = Z | S Nat

data SBool b where
    STrue :: SBool True
    SFalse :: SBool False

data SNat n where
    SZ :: SNat Z
    SS :: SNat n -> SNat (S n)

decode :: SNat n -> P.Int
decode SZ      = 0
decode (SS sn) = 1 P.+ decode sn

instance P.Show (SNat n) where
    show = P.show P.. decode

instance P.Show (SBool b) where
    show STrue  = "True"
    show SFalse = "False"

infixl 5 $==
infixl 5 $||
infixl 6 $&&
infixl 5 $/=
infixl 5 :==
infixl 5 :/=
infixl 6 :+
infixl 6 :-
infixl 7 :*
infixl 7 :~
infixl 7 :<
infixl 7 :>

data Eq a b where
    Eq :: Eq a a
    Neq :: Eq a b

data Check a where
    Yes :: Check True
    No  :: Check False

type family Not (a :: Bool) :: Bool
type instance Not True = False
type instance Not False = True

type family (a :: Bool) $== (b :: Bool) :: Bool
type instance True  $== True  = True
type instance False $== False = True
type instance True  $== False = False
type instance False $== True  = False

type family (a :: Bool) $&& (b :: Bool) :: Bool
type instance True  $&& b  = b
type instance False $&& _ = False

type family (a :: Bool) $|| (b :: Bool) :: Bool
type instance True  $|| _  = True
type instance False $|| b = b

type family (a :: Bool) $/= (b :: Bool) :: Bool
type instance a $/= b = Not (a $== b)

type family (a :: Nat) :+ (b :: Nat) :: Nat
type instance Z   :+ b = b
type instance S a :+ b = S (a :+ b)

type family (a :: Nat) :- (b :: Nat) :: Nat
type instance Z   :- _ = Z
type instance S a :- Z = S a
type instance S a :- S b = a :- b

type family (a :: Nat) :* (b :: Nat) :: Nat
type instance Z   :* _   = Z
type instance S a :* Z   = Z
type instance S a :* S b = S a :+ (S a :* b)

type family (a :: Nat) :== (b :: Nat) :: Bool
type instance Z   :== Z   = True
type instance Z   :== S b = False
type instance S a :== Z   = False
type instance S a :== S b = a :== b

type family (a :: Nat) :/= (b :: Nat) :: Bool
type instance a :/= b = Not (a :== b)

type family (a :: Nat) :> (b :: Nat) :: Bool
type instance Z   :> _ = False
type instance S a :> Z = True
type instance S a :> S b = a :> b

type family (a :: Nat) :< (b :: Nat) :: Bool
type instance Z   :< _ = True
type instance S a :< Z = False
type instance S a :< S b = a :< b

type family (a :: Nat) :~ (b :: Nat) :: Bool
type instance a :~ Z = False
type instance a :~ S b = a :== S b $|| a :~ (S b :- a)

type family Cond (p :: Bool) :: Nat
type instance Cond False = Zero
type instance Cond True  = One

type family HelpDivisors (m :: Nat) (n :: Nat) :: Nat
type instance HelpDivisors Z n     = Zero
type instance HelpDivisors (S m) n = HelpDivisors m n :+ Cond (S m :~ n)

type family Divisors (n :: Nat) :: Nat
type instance Divisors n = HelpDivisors n n

type Zero = Z
type One = S Zero
type Two = S One
type Three = S Two
type Six = Two :* Three

type family Prime (n :: Nat) :: Bool
type instance Prime a = Divisors a :== Two

onePlusOneEqualsTwo :: Eq (S Z :+ S Z) (S (S Z))
onePlusOneEqualsTwo = Eq

onePlusOneEqualsThree :: Eq (S Z :+ S Z) (S (S (S Z)))
onePlusOneEqualsThree = Neq

does1Lt2 :: Check (One :< Two)
does1Lt2 = Yes

does3Lt6 :: Check (Three :< Six)
does3Lt6 = Yes

does3Div6 :: Check (Three :~ Six)
does3Div6 = Yes

is2Prime :: Check (Prime Two)
is2Prime = Yes

is3Prime :: Check (Prime Three)
is3Prime = Yes

is6Prime :: Check (Prime Six)
is6Prime = No

main :: P.IO ()
main = P.pure ()