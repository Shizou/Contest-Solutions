require 'matrix'
rows, cols = gets.chomp.split(" ").map(&:to_i)
arr = Array.new(rows) {Array.new(cols)} 
x = Array.new(cols)
for i in 0...rows
    vals = gets.chomp.split(" ").map(&:to_i)
    for j in 0...cols
        arr[i][j] = vals[j]
    end
    x[i] = vals[cols]
end
m = Matrix[*arr]
if rows < cols
    puts "NO UNIQUE SOLUTION"
elsif rows == cols and m.lup.det() == 0
    puts "NO UNIQUE SOLUTION"
elsif rows == cols and m.lup.issingular?
    puts "NO UNIQUE SOLUTION"
else
    v = m.lup.solve(x).to_a
    for i in 0...v.length
        puts "#{'%.05f' % v[i].to_f}"
    end
end
