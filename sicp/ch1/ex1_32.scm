(use compat.sicp)

;; a
;; 再帰的プロセス
(define (accumulate combiner null-value term a next b)
    (if (> a b)
        null-value
        (combiner (term a)
                  (accumulate combiner null-value term (next a) next b))))

(define (sum term a next b)
    (accumulate + 0 term a next b))

(define (product term a next b)
    (accumulate * 1 term a next b))

(define (inc n) (+ n 1))
(define (identity x) x)

(print (sum identity 3 inc 5))
(print (product identity 3 inc 5))

;; b
;; 反復的プロセス
(define (accumulate-iter combiner null-value term a next b)
    (define (iter a result)
        (if (> a b)
            result
            (iter (next a) (combiner result (term a)))))
    (iter a null-value))

(define (sum-iter term a next b)
    (accumulate-iter + 0 term a next b))

(define (product-iter term a next b)
    (accumulate-iter * 1 term a next b))

(print (sum-iter identity 3 inc 5))
(print (product-iter identity 3 inc 5))