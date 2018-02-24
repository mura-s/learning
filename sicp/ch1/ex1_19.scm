;; p' = p^2 + q^2
;; q' = 2pq + q^2

(define (fib n)
    (fib-iter 1 0 0 1 n))

(define (fib-iter a b p q count)
    (cond ((= count 0) b)
          ((even? count) (fib-iter a
                                   b
                                   (+ (square p) (square q))
                                   (+ (* 2 p q) (square q))
                                   (/ count 2)))
          (else (fib-iter (+ (* b q) (* a q) (* a p))
                          (+ (* b p) (* a q))
                          p
                          q
                          (- count 1)))))

(print (fib 1))
(print (fib 2))
(print (fib 3))
(print (fib 4))
(print (fib 5))
(print (fib 6))
(print (fib 7))