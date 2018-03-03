(use compat.sicp)

;; a.
;; product
(define (product term a next b)
    (if (> a b)
        1
        (* (term a)
           (product term (next a) next b))))

(define (inc n) (+ n 1))

(define (identity x) x)

;; factorial
(define (factorial n)
    (product identity 1 inc n))

(print (factorial 5))

(define (even? n)
    (= (remainder n 2) 0))

;; πの近似値計算
(define (pi-product a b)
    (define (pi-term x)
        (if (even? x) (/ (+ x 2) (+ x 1))
                      (/ (+ x 1) (+ x 2))))
    (product pi-term a inc b))

(print (* 4 (pi-product 1.0 100.0)))

;; b.
;; product-iter
(define (product-iter term a next b)
    (define (iter a result)
        (if (> a b)
            result
            (iter (next a) (* result (term a)))))
    (iter a 1))

(define (factorial-iter n)
    (product-iter identity 1 inc n))

(print (factorial-iter 5))