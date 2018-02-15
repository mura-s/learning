(define (sqrt-iter guess old-guess x)
  (if (new-good-enough? guess old-guess)
      guess
      (sqrt-iter (improve guess x)
                 guess
                 x)))

(define (improve guess x)
  (average guess (/ x guess)))

(define (average x y)
  (/ (+ x y) 2))

;;(define (good-enough? guess x)
;;  (< (abs (- (square guess) x)) 0.001))

(define (new-good-enough? guess old-guess)
  (< (abs (- guess old-guess)) (* guess 0.001)))

(define (sqrt x)
  (sqrt-iter 1.0 0.0 x))

;; test
(print (sqrt 9))
(print (sqrt 0.000000000001))
(print (sqrt 100000000000000000000000000000000000000000000000000))

;; answer
;; 非常に小さい数の場合、(square guess)が0.001より小さくなった時点で終了してしまう。
;; 非常に大きい数の場合、(- (square guess) x))で値が切り捨てされてしまい、無限ループになる。

;; new-good-enough?の場合、非常に小さい数でも非常に大きい数でも上手くいく。