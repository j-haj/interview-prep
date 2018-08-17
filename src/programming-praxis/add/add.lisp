
(defun add_neg (x y)
  "Adds two integers together where the first is negative."
  (cond ((equal x 0)  y)
        (t (add_neg (+ x 1) (- y 1)))))

(defun add_pos (x y)
  "Adds two integers together where the first integer is positive."
  (cond ((equal x 0)  y)
        (t (add_pos (- x 1) (+ y 1)))))

(defun add (x y)
  "Adds two integers together."
  (if (< x 0)  (add_neg x y)
    (add_pos x y)))

;;;; Main function
(defun main ()
  (format t "Hello, world!~%")
  (format t "4 + 5 = ~a~%" (add 5 4))
  (format t "-10 - 12 = ~a~%" (add -10 -12)))

(main)
