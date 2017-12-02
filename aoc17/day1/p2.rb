code = gets.chomp.to_s()
code_len = code.length
step = code_len/2
ans = 0
for i in 0..code_len
    if code[i] == code[(i+step)%code_len] 
        ans += code[i].to_i
    end
end
puts "ans is: " + ans.to_s
