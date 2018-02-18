;; 1.1.7
(define (sqrt-iter guess x)
  (if (good-enough? guess x)
      guess
      (sqrt-iter (improve guess x)
                 x)))

(define (improve guess x)
  (average guess (/ x guess)))

(define (average x y)
  (/ (+ x y) 2))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.001))

(define (sqrt x)
  (sqrt-iter 1.0 x))

;; (print (sqrt 9))

;; 1.2.1
(define (factorial n)
  (define (iter product counter)
    (if (> counter n)
      product
      (iter (* product counter)
            (+ counter 1))))
  (iter 1 1))

;;(print (factorial 6))