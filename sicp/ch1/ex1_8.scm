(define (sqrt-iter guess old-guess x)
  (if (new-good-enough? guess old-guess)
      guess
      (sqrt-iter (average3 x guess)
                 guess
                 x)))

(define (average3 x y)
  (/ (+ (/ x (square y))
        (* 2 y)) 
     3))

(define (new-good-enough? guess old-guess)
  (< (abs (- guess old-guess)) (* guess 0.001)))

(define (sqrt x)
  (sqrt-iter 1.0 0.0 x))

;; test
(print (sqrt 27))
(print (sqrt 1000))
