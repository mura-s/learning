(define (fast-expt b n)
  (fast-expt-iter b n 1))

(define (fast-expt-iter b counter a)
  (cond ((= counter 0) a)
        ((even? counter) (fast-expt-iter (* b b)
                                         (/ counter 2)
                                         a))
        (else (fast-expt-iter b
                             (- counter 1)
                             (* a b)))))

(define (even? n)
  (= (remainder n 2) 0))

(print (fast-expt 2 0))
(print (fast-expt 2 1))
(print (fast-expt 2 2))
(print (fast-expt 2 5))
(print (fast-expt 2 6))
(print (fast-expt 2 9))
(print (fast-expt 2 10))