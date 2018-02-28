(define (fast-expt b n)
    (cond ((= n 0) 1)
          ((even? n) (square (fast-expt b (/ n 2))))
          (else (* b (fast-expt b (- n 1))))))

(define (even? n)
    (= (remainder n 2) 0))

(define (expmod base exp m)
    (remainder (fast-expt base exp) m))

(print (expmod 3 3 5))

;; 正しいが、fast-exptが中間データとして大きな値を計算してしまうので、パフォーマンスに影響がある。