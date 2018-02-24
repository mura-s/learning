(define (double n) (* n 2))

(define (halve n) (/ n 2))

(define (even? n)
  (= (remainder n 2) 0))

(define (fast-multiply a b)
  (fast-multiply-iter a b 0))

(define (fast-multiply-iter a counter x)
  (cond ((= counter 0) x)
        ((even? counter) (fast-multiply-iter (double a)
                                             (halve counter)
                                             x))
        (else (fast-multiply-iter a
                                  (- counter 1)
                                  (+ a x)))))

(print (fast-multiply 3 4))
(print (fast-multiply 4 3))
(print (fast-multiply 4 0))