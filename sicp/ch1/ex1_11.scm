;; 再帰的プロセス
(define (f n)
  (if (< n 3)
    n
    (+ (f (- n 1))
       (* 2 (f (- n 2)))
       (* 3 (f (- n 3))))))

;; 反復的プロセス
(define (f n)
  (define (f-iter a b c count)
    (if (= count n)
      c
      (f-iter (+ a (* 2 b) (* 3 c))
              a
              b
              (+ count 1))))
  (f-iter 2 1 0 0))

(print (f 1))
(print (f 2))
(print (f 3))
(print (f 4))
(print (f 5))
