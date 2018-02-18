(define (count-change amount)
  (cc amount 5))

(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (= kinds-of-coins 0)) 0)
        (else (+ (cc amount
                     (- kinds-of-coins 1))
                 (cc (- amount (first-denomination kinds-of-coins))
                     kinds-of-coins)))))

(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 5) 50)
        ((= kinds-of-coins 4) 25)
        ((= kinds-of-coins 3) 10)
        ((= kinds-of-coins 2) 5)
        ((= kinds-of-coins 1) 1)))

(print (count-change 11))

;; スペース:
;;   木の最大の深さに比例するのでO(n)
;;
;; ステップ数:
;;   1枚のコイン (1セント) を利用した場合は、ステップ数は2n+1、つまり O(n)
;;   2枚 (1セントと5セント)の時は、5セントを使用するときのn/5回に対して、1枚のコインのケースがあるので、
;;   (n/5)*(2n+1)、つまり O(n^2)
;;   これを繰り返すと、5枚のときは O(n^5) であることがわかる
;;
;; ref. http://snufkon.hatenablog.com/entry/2013/04/22/143647