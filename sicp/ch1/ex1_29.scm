(define (cube x) (* x x x))

(define (odd? n)
    (= (remainder n 2) 1))

(define (sum term a next b)
    (if (> a b)
        0
        (+ (term a)
           (sum term (next a) next b))))

(define (simpson f a b n)
    (define h (/ (- b a) n))
    (define (inc x) (+ x 1))
    (define (coef k)
        (cond ((= k 0) 1)
              ((= k n) 1)
              ((odd? k) 4)
              (else 2)))
    (define (calc-y-and-coef k)
        (* (coef k)
           (f (+ a
                 (* k h)))))
    (* (/ h 3)
       (sum calc-y-and-coef 0.0 inc n)))

(print (simpson cube 0 1 100))
(print (simpson cube 0 1 1000))