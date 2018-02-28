(define (even? n)
    (= (remainder n 2) 0))

(define (expmod base exp m)
    (cond ((= exp 0) 1)
          ((even? exp)
            (remainder (* (expmod base (/ exp 2) m)
                          (expmod base (/ exp 2) m))
                       m))
          (else
            (remainder (* base (expmod base (- exp 1) m))
                       m))))

(print (expmod 3 3 5))

;; 線形探索ではなく、木の探索になってしまう。
;; つまり、 `*` のたびに経路が2つに分かれていく。
;; 木の深さがlog2(n)であることを踏まえると、 O(2^log2(n)) = O(n) となる。
;; ref. http://ochaochaocha3.hateblo.jp/entry/2015/04/12/sicp-ex-1-26