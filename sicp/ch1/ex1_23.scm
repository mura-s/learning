(use compat.sicp)

(define (odd? n)
    (= (remainder n 2) 1))

(define (smallest-divisor n)
    (find-divisor n 2))

(define (find-divisor n test-divisor)
    (cond ((> (square test-divisor) n) n)
          ((divides? test-divisor n) test-divisor)
          (else (find-divisor n (next test-divisor)))))

(define (divides? a b)
    (= (remainder b a) 0))

(define (next a)
    (if (= a 2) 3 (+ a 2)))

(define (prime? n)
    (= n (smallest-divisor n)))

(define (timed-prime-test n)
    (newline)
    (display n)
    (start-prime-test n (runtime)))

(define (start-prime-test n start-time)
    (if (prime? n)
        (report-prime (- (runtime) start-time))))

(define (report-prime elapsed-time)
    (display " *** ")
    (display elapsed-time))

(define (search-for-primes first last)
    (cond ((<= first last)
          (if (odd? first) (timed-prime-test first))
          (search-for-primes (+ first 1) last))))

(search-for-primes 1000 1019)
(newline)
(search-for-primes 10000 10037)
(newline)
(search-for-primes 100000 100043)
(newline)
(search-for-primes 1000000 1000037)