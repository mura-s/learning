(use compat.sicp)

(define (even? n)
    (= (remainder n 2) 0))

(define (expmod base exp m)
    (define (check-nontrivial-sqrt-1 x)
        (cond ((or (= x 1)
                   (= x (- m 1))) 1)
              (else (let ((r (remainder (square x) m)))
                    (if (= r 1) 0 r)))))
    (cond ((= exp 0) 1)
          ((even? exp) (check-nontrivial-sqrt-1 (expmod base (/ exp 2) m)))
          (else (remainder (* base (expmod base (- exp 1) m))
                           m))))

(define (miller-rabin-test n)
    (define (try-it a)
        (= (expmod a (- n 1) n) 1))
    (try-it (+ 1 (random (- n 1)))))

(define (fast-prime? n times)
    (cond ((= times 0) true)
          ((miller-rabin-test n) (fast-prime? n (- times 1)))
          (else false)))

(print (fast-prime? 2465 10))
(print (fast-prime? 2821 10))
(print (fast-prime? 6601 10))

(print (fast-prime? 10 10))
(print (fast-prime? 13 10))