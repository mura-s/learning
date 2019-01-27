ops = ['*', '']

(1000..9999).each do |i|
  ops.each do |op1|
    ops.each do |op2|
      ops.each do |op3|
        n = i.to_s
        nAndOps = n[0] + op1 + n[1] + op2 + n[2] + op3 + n[3]
        if nAndOps.length > 4
          begin
            puts n if eval(nAndOps).to_s.reverse == n
          rescue SyntaxError => e
          end
        end
      end
    end
  end
end