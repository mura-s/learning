(define (square x) (* x x))

(define (sum-of-square x y)
  (+ (square x) (square y)))

(define (large-two-num-sum-of-square x y z)
  (cond ((= x (min x y z)) (sum-of-square y z))
        ((= y (min x y z)) (sum-of-square x z))
        ((= z (min x y z)) (sum-of-square x y))
  ))

;; test
(print (large-two-num-sum-of-square 1 2 3))
(print (large-two-num-sum-of-square 2 1 3))
(print (large-two-num-sum-of-square 1 1 3))