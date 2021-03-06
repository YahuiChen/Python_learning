;; Option Region
(set-option :timeout 5000)

;; Constant Declaration Region
(declare-const n Int)
(declare-const i Int)
(declare-const ^a (Array Int Int))
(declare-const a (Array Int Int))
(declare-const %^a Int)

;; Function Declaration Region
(declare-fun pointer-addr-_Array-Int-Int_ ((Array Int Int)) Int)
(declare-fun off-set (Int) Int)
(declare-fun leng-th (Int) Int)

;; Lemma Region

;; Prerequisite Region
(assert (> (pointer-addr-_Array-Int-Int_ a) 0))
(assert (> (pointer-addr-_Array-Int-Int_ ^a) 0))
(assert (= ^a a))

;; Goal Region
(assert (not (=> (and (= n 1000)
                      (= i n)
                      (forall ((!k Int))
                              (=> (and (>= !k 0)
                                       (<= !k (- i 2)))
                                  (<= (select ^a !k) (select ^a (+ !k 1)))))
                      (>= i n)
                      (and (= (pointer-addr-_Array-Int-Int_ a) (+ %^a 0))
                           (= (leng-th (pointer-addr-_Array-Int-Int_ a)) n)
                           (= (off-set (pointer-addr-_Array-Int-Int_ a)) 0))
                      (and (= (pointer-addr-_Array-Int-Int_ ^a) (+ %^a 0))
                           (= (leng-th (pointer-addr-_Array-Int-Int_ ^a)) n)
                           (= (off-set (pointer-addr-_Array-Int-Int_ ^a)) 0)))
                 false)))
(check-sat )

