(define (A x y)
  (cond ((= y 0) 0)
        ((= x 0) (* 2 y))
        ((= y 1) 2)
        (else (A (- x 1)
                 (A x (- y 1))))))

(print (A 1 10))
(print (A 2 4))
(print (A 3 3))

(define (f n) (A 0 n))
;; (f n)は、2nを計算する

(define (g n) (A 1 n))
;; (g n)は、2^nを計算する

(define (h n) (A 2 n))
;; (h n)は、2^2^... (2がn個現れる)を計算する
