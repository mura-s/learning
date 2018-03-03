(use compat.sicp)

;; 1.3.1
(define (cube x) (* x x x))

(define (inc n) (+ n 1))

(define (sum term a next b)
    (if (> a b)
        0
        (+ (term a)
           (sum term (next a) next b))))

(define (sum-cubes a b)
    (sum cube a inc b))

;; (print (sum-cubes 3 5))

(define (identity x) x)

(define (sum-integers a b)
    (sum identity a inc b))

;; (print (sum-integers 3 5))

(define (pi-sum a b)
    (define (pi-term x)
        (/ 1.0 (* x (+ x 2))))
    (define (pi-next x) (+ x 4))
    (sum pi-term a pi-next b))

;; (print (* 8 (pi-sum 1 1000)))

(define (integral f a b dx)
    (define (add-dx x) (+ x dx))
    (* (sum f (+ a (/ dx 2.0)) add-dx b)
       dx))

;; (print (integral cube 0 1 0.01))
;; (print (integral cube 0 1 0.001))

;; 1.3.2
(define (pi-sum-lambda a b)
    (sum (lambda (x) (/ 1.0 (* x (+ x 2))))
         a
         (lambda (x) (+ x 4))
         b))

;; (print (* 8 (pi-sum-lambda 1 1000)))

(define (f x y)
    (let ((a (+ 1 (* x y)))
          (b (- 1 y)))
        (+ (* x (square a))
           (* y b)
           (* a b))))

(print (f 2 3))