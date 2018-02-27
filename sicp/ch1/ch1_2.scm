(use compat.sicp)

;; 1.2.1
(define (factorial n)
    (define (iter product counter)
        (if (> counter n)
            product
            (iter (* product counter)
                  (+ counter 1))))
    (iter 1 1))

;; (print (factorial 6))

;; 1.2.4
(define (expt b n)
    (expt-iter b n 1))

(define (expt-iter b counter product)
    (if (= counter 0)
        product
        (expt-iter b
                   (- counter 1)
                   (* b product))))

(define (fast-expt b n)
    (cond ((= n 0) 1)
          ((even? n) (square (fast-expt b (/ n 2))))
          (else (* b (fast-expt b (- n 1))))))

(define (even? n)
    (= (remainder n 2) 0))

;; (print (fast-expt 3 3))

;; 1.2.6
(define (smallest-divisor n)
    (find-divisor n 2))

(define (find-divisor n test-divisor)
    (cond ((> (square test-divisor) n) n)
          ((divides? test-divisor n) test-divisor)
          (else (find-divisor n (+ test-divisor 1)))))

(define (divides? a b)
    (= (remainder b a) 0))

(define (prime? n)
    (= n (smallest-divisor n)))

;; (print (prime? 10))
;; (print (prime? 13))

(define (expmod base exp m)
    (cond ((= exp 0) 1)
          ((even? exp) (remainder (square (expmod base (/ exp 2) m))
                                 m))
          (else (remainder (* base (expmod base (- exp 1) m))
                           m))))

(define (fermat-test n)
    (define (try-it a)
        (= (expmod a n n) a))
    (try-it (+ 1 (random (- n 1)))))

(define (fast-prime? n times)
    (cond ((= times 0) true)
          ((fermat-test n) (fast-prime? n (- times 1)))
          (else false)))

(print (fast-prime? 10 5))
(print (fast-prime? 13 5))