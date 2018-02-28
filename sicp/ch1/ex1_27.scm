(use compat.sicp)

(define (even? n)
    (= (remainder n 2) 0))

(define (expmod base exp m)
    (cond ((= exp 0) 1)
          ((even? exp) (remainder (square (expmod base (/ exp 2) m))
                                 m))
          (else (remainder (* base (expmod base (- exp 1) m))
                           m))))

(define (fermat-test n a)
    (define (try-it)
        (= (expmod a n n) a))
    (try-it))

(define (cheat-fermat-test n count)
    (cond ((= count n) true)
          ((fermat-test n count) (cheat-fermat-test n (+ count 1)))
          (else false)))

(print (cheat-fermat-test 561 1))
(print (cheat-fermat-test 1105 1))
(print (cheat-fermat-test 1729 1))
