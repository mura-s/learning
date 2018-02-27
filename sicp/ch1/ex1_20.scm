(define (gcd a b)
    (if (= b 0)
        a
        (gcd b (remainder a b))))

(print (gcd 206 40))

;; 正規順序評価: remainder演算は合計18回実行される。
;;             if文での条件チェックで14回、最後のaの簡約で4回実行される。
;;             ref. http://community.schemewiki.org/?sicp-ex-1.20

;; 作用的順序評価: remainder演算は4回実行される。 (gcd呼び出し時にremainderも実行される。)