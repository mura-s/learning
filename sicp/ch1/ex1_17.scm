(define (double n) (* n 2))

(define (halve n) (/ n 2))

(define (even? n)
  (= (remainder n 2) 0))

(define (fast-multiply a b)
    (cond ((= b 0) 0)
          ((even? b) (double (fast-multiply a (halve b))))
          (else (+ a (fast-multiply a (- b 1))))))

(print (fast-multiply 3 4))
(print (fast-multiply 4 3))
(print (fast-multiply 4 0))