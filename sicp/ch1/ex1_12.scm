(define (pascal row col)
  (if (or (= col 1) (= col row))
    1
    (+ (pascal (- row 1) (- col 1))
       (pascal (- row 1) col))))

(print (pascal 1 1))
(print (pascal 3 2))
(print (pascal 5 3))