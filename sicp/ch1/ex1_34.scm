(define (f g) (g 2))

(print (f square))
(print (f (lambda (z) (* z (+ z 1)))))

(print (f f))
;; 2に対して2を適用しようとしてエラーになる