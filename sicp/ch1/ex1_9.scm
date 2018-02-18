(define (inc a)
  (+ a 1))

(define (dec a)
  (- a 1))

;; 1つ目の+は、再帰的
(define (+ a b)
  (if (= a 0)
    b
    (inc (+ (dec a) b))))

;; 2つ目の+は、反復的
(define (+ a b)
  (if (= a 0)
    b
    (+ (dec a) (inc b))))

(print (+ 5 3))