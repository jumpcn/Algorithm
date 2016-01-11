#lang racket

(define (merge-list l1 l2)
  (if (null? l1)
      l2
      (if (null? l2)
          l1
          (if (< (car l1) (car l2))
                      (cons (car l1) (merge-list (cdr l1) l2))
                      (cons (car l2) (merge-list l1 (cdr l2)))))))

(define (divide l r seq)
  (if (null? seq)
      (list l r)
      (if (not (null? (cdr seq)))
          (divide (cons (car seq) l) (cons (car (cdr seq)) r) (cdr (cdr seq)))
          (divide (cons (car seq) l) r (list )))))

(define (merge-sort l)
  (let ([d (divide (list ) (list ) l)])
  (if (null? l)
      l
      (if (null? (cdr l))
          (merge-list (list (car l)) null)
          (merge-list (merge-sort (car d)) (merge-sort (cadr d)))))))

(merge-sort (list -1 0 10 3 100 -4 92 23))
(merge-sort (list ))
(merge-sort (list 5 4 3 2 1 0 -1 -2 -3 -4))

